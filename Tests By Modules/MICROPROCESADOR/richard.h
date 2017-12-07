#ifndef RICHARD_H
#define RICHARD_H
#include "alu.h"
#include "registerfile.h"
#include "datamemory.h"
#include "instrmemory.h"
#include "multiplexor.h"
#include "regs5.h"
#define direction_bits 5
#define numbers_of_bits 5
#define instruction_length 20
#define instructions_number_read 4

class Richard : public sc_module
{
	public:

		sc_in<bool> clk_in;
		sc_in<bool> enable_in;
		sc_in<sc_uint<instructions_number_read> > pc_in;
		SC_CTOR(Richard)
		{
			SC_METHOD(split);
			sensitive << instruction_in_sg;

			instrmem = new InstrMemory("instrmem");
			regP1_opcode = new Regs5("regP1_opcode");
			regP1_dir_result = new Regs5("regP1_dir_result");
			regP1_dirop1 = new Regs5("regP1_dirop1");
			regP1_dirop2 = new Regs5("regP1_dirop2");

			registerfile = new Registerfile("registerfile");
			regP2_opcode = new Regs5("regP2_opcode");
			regP2_dir_result = new Regs5("regP2_dir_result");
			regP2_dirop1 = new Regs5("regP2_dirop1");
			regP2_datA = new Regs5("regP2_datA");
			regP2_datB = new Regs5("regP2_datB");

			alu = new Alu("alu");
			regP3_opcode = new Regs5("regP3_opcode");
			regP3_dir_result = new Regs5("regP3_dir_result");
			regP3_dirop1 = new Regs5("regP3_dirop1");
			regP3_datC = new Regs5("regP3_datC");

			datamem = new DataMemory("datamem");
			mult = new Multiplexor("mult");
			mult2 = new Multiplexor("mult2");
			regP4_opcode = new Regs5("regP4_opcode");
			regP4_dir_result = new Regs5("regP4_dir_result");
			regP4_datC = new Regs5("regP4_datC");

//ETAPA FETCH------------------------------
			instrmem->dir_in(pc_in);
			instrmem->instr_out(instruction_in_sg); 
//Primer PIPE------------------------------
			regP1_opcode->data_in(opcode_sg);
			regP1_opcode->enable_in( enable_in);
			regP1_opcode->clk_in(clk_in);
			regP1_opcode->data_out(P1opcode_sg);

			regP1_dir_result->data_in(dir_result_sg);
			regP1_dir_result->enable_in(enable_in);
			regP1_dir_result->clk_in(clk_in);
			regP1_dir_result->data_out(P1dir_result_sg);	

			regP1_dirop1->data_in(dirop1_sg);
			regP1_dirop1->enable_in(enable_in);
			regP1_dirop1->clk_in(clk_in);
			regP1_dirop1->data_out(P1dirop1_sg);	

			regP1_dirop2->data_in(dirop2_sg);
			regP1_dirop2->enable_in(enable_in);
			regP1_dirop2->clk_in(clk_in);
			regP1_dirop2->data_out(P1dirop2_sg);

//ETAPA DECODE-----------------------------
			registerfile->dira_in(P1dirop1_sg);
			registerfile->dirb_in(P1dirop2_sg);
			registerfile->a_out(datA_regfile_sg); 
			registerfile->b_out(datB_regfile_sg);
			registerfile->clk(clk_in );
//Segundo PIPE-----------------------------
			regP2_datA->data_in (datA_regfile_sg);
			regP2_datA->enable_in (enable_in);
			regP2_datA->clk_in (clk_in);
			regP2_datA->data_out (P2datA_sg);

			regP2_datB->data_in (datB_regfile_sg);
			regP2_datB->enable_in (enable_in);
			regP2_datB->clk_in (clk_in);
			regP2_datB->data_out (P2datB_sg);

			regP2_dirop1->data_in(P1dirop1_sg);
			regP2_dirop1->enable_in(enable_in);
			regP2_dirop1->clk_in(clk_in);
			regP2_dirop1->data_out(P2dirop1_sg);

			regP2_dir_result->data_in(P1dir_result_sg);
			regP2_dir_result->enable_in(enable_in);
			regP2_dir_result->clk_in(clk_in);
			regP2_dir_result->data_out(P2dir_result_sg);

			regP2_opcode->data_in(P1opcode_sg);
			regP2_opcode->enable_in(enable_in);
			regP2_opcode->clk_in(clk_in);
			regP2_opcode->data_out(P2opcode_sg);	

//ETAPA EXECUTE----------------------------
			alu->a_in(P2datA_sg);
			alu->b_in(P2datB_sg);
			alu->op_in(P2opcode_sg);
			alu->c_out(alu_sg);
//Tercer PIPE------------------------------
			regP3_datC->data_in (alu_sg);
			regP3_datC->enable_in (enable_in);
			regP3_datC->clk_in (clk_in);
			regP3_datC->data_out (P3_datC_sg);

			regP3_dirop1->data_in(P2dirop1_sg);
			regP3_dirop1->enable_in(enable_in);
			regP3_dirop1->clk_in(clk_in);
			regP3_dirop1->data_out(P3dirop1_sg);

			regP3_dir_result->data_in(P2dir_result_sg);
			regP3_dir_result->enable_in(enable_in);
			regP3_dir_result->clk_in(clk_in);
			regP3_dir_result->data_out(P3dir_result_sg);

			regP3_opcode->data_in(P2opcode_sg);
			regP3_opcode->enable_in(enable_in);
			regP3_opcode->clk_in(clk_in);
			regP3_opcode->data_out(P3opcode_sg);

//ETAPA MEMORY----------------------------

			mult->a_in(P3dirop1_sg);
			mult->b_in(P3dir_result_sg);
			mult->selector(P3opcode_sg);
			mult->s_out(multiplexor_sg);

			datamem->op_in(P3opcode_sg);
			datamem->data_in(P3_datC_sg);
			datamem->dir_in(multiplexor_sg);
			datamem->data_out(data_mem_sg);			

			mult2->a_in(P3_datC_sg);
			mult2->b_in(data_mem_sg);
			mult2->selector(P3opcode_sg);
			mult2->s_out(multiplexor2_sg);
//Cuarto PIPE------------------------------
			regP4_datC->data_in (multiplexor2_sg);
			regP4_datC->enable_in (enable_in);
			regP4_datC->clk_in (clk_in);
			regP4_datC->data_out (P4_datC_sg);

			regP4_dir_result->data_in(P3dir_result_sg);
			regP4_dir_result->enable_in(enable_in);
			regP4_dir_result->clk_in(clk_in);
			regP4_dir_result->data_out(P4dir_result_sg);

			regP4_opcode->data_in(P3opcode_sg);
			regP4_opcode->enable_in(enable_in);
			regP4_opcode->clk_in(clk_in);
			regP4_opcode->data_out(P4opcode_sg);

//ETAPA WRITE BACK------------------------

			registerfile->enable_in(P4opcode_sg);
			registerfile->dirdata_in(P4dir_result_sg);
			registerfile->data_in(P4_datC_sg);
		}
	private:
		InstrMemory *instrmem;
//Señal del formato de instrucciones
		sc_signal<sc_uint<instruction_length> > instruction_in_sg;
//Señales que entran al primer pipe
		sc_signal<sc_uint<direction_bits> > opcode_sg, dir_result_sg, dirop1_sg, dirop2_sg;
//Registros del primer pipe
		Regs5 *regP1_opcode,*regP1_dir_result, *regP1_dirop1, *regP1_dirop2;
//Señales que salen del primer pipe
		sc_signal<sc_uint<direction_bits> > P1opcode_sg, P1dir_result_sg, P1dirop1_sg, P1dirop2_sg;

		Registerfile *registerfile;
//Registros del segundo pipe
		Regs5 *regP2_opcode ,*regP2_dir_result, *regP2_dirop1, *regP2_datA, *regP2_datB;
//Señales que entran al segundo pipe
		sc_signal<sc_uint<direction_bits> > datA_regfile_sg, datB_regfile_sg;

//Señales que salen del segundo pipe
		sc_signal<sc_uint<direction_bits> > P2opcode_sg, P2dir_result_sg, P2dirop1_sg, P2datA_sg, P2datB_sg;

		Alu *alu;
//Registros del tercer pipe
		Regs5 *regP3_opcode,*regP3_dir_result, *regP3_dirop1, *regP3_datC;
//Señales que entran al tercer pipe
		sc_signal<sc_uint<direction_bits> > alu_sg; 
//Señales que salen del tercer pipe
		sc_signal<sc_uint<direction_bits> > P3opcode_sg, P3dir_result_sg, P3dirop1_sg ,P3_datC_sg;

		DataMemory *datamem;
		Multiplexor *mult,*mult2;
//Registros del cuarto pipe
		Regs5 *regP4_opcode, *regP4_dir_result, *regP4_datC;
//Señales que entran al cuarto pipe
		sc_signal<sc_uint<direction_bits> > data_mem_sg, multiplexor_sg,multiplexor2_sg;
//Señales que salen del cuarto pipe
		sc_signal<sc_uint<direction_bits> > P4opcode_sg, P4dir_result_sg,P4_datC_sg;

	void split()
	{
		opcode_sg=(instruction_in_sg.read().range(19,15));
		dir_result_sg=(instruction_in_sg.read().range(14,10)); 
		dirop1_sg=(instruction_in_sg.read().range(9,5));
		dirop2_sg=(instruction_in_sg.read().range(4,0));
	}
};
#endif
