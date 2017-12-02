#ifndef RICHARD_H
#define RICHARD_H
#include "alu.h"
#include "registerfile.h"
#include "datamemory.h"
#include "instrmemory.h"
#include "regs5.h"
#include "regs32.h"
#define direction_bits 5
#define numbers_of_bits 32
#define instruction_length 20
#define instructions_number_read 4

class Richard : public sc_module
{
	public:
		sc_in <bool> clk_in;
		sc_in<bool > enable_in,write_enable;
		sc_in<sc_uint<instructions_number_read> > pc_in;
		SC_CTOR(Richard)
		{
			SC_METHOD(split);
			sensitive<<instr_sg;
			instmem = new InstrMemory("instmem");
			reg0_op = new Regs5("reg0_op");
			reg0_result = new Regs5("reg0_result");
			reg0_op1 = new Regs5("reg0_op1");
			reg0_op2 = new Regs5("reg0_op2");
			registerfile = new registerfile("registerfile");
			reg1_op = new Regs5("reg1_op");
			reg32_data_a = new Regs32("reg32_data_a");
			reg32_data_b = new Regs32("reg32_data_b");
			reg1_result = new Regs5("reg1_result");
			alu = new Alu("alu");
			reg2_op = new Regs5("reg2_op");
			reg32_result = new Regs32("reg32_result");
			reg2_result = new Regs5("reg2_result");
			datamem = new DataMemory("datamem");
			reg32_data_out = new Regs32("reg32_data_out");
			reg3_op = new Regs5("reg3_op");
			reg3_result = new Regs5("reg3_result");

//ETAPA FETCH------------------------------
			instmem->dir_in(pc_in);
			instmem->instr_out(instr_sg);
//Primer PIPE------------------------------
			reg0_op->data_in(op_sg);
			reg0_op->enable_in(enable_in);
			reg0_op->clk_in(clk_in);
			reg0_op->data_out(reg0_op_sg);

			reg0_result->data_in(dir_result_sg);
			reg0_result->enable_in(enable_in);
			reg0_result->clk_in(clk_in);
			reg0_result->data_out(reg0_result_sg);	

			reg0_op1->data_in(dirop1_sg);
			reg0_op1->enable_in(enable_in);
			reg0_op1->clk_in(clk_in);
			reg0_op1->data_out(reg0_op1_sg);	

			reg0_op2->data_in(instr_sg);
			reg0_op2->enable_in(enable_in);
			reg0_op2->clk_in(clk_in);
			reg0_op2->data_out(reg0_op2_sg);

//ETAPA DECODE-----------------------------
			registerfile->enable_in(write_enable);
			registerfile->dira_in(reg0_op1_sg);
			registerfile->dirb_in(reg0_op2_sg);
			registerfile->a_out(data_a_sg);
			registerfile->b_out(data_b_sg);
			registerfile->clk(clk_in);
//Segundo PIPE-----------------------------
			reg32_data_a->data_in (data_a_sg);
			reg32_data_a->enable_in (enable_in);
			reg32_data_a->clk_in (clk_in);
			reg32_data_a->data_out (reg32_data_a_sg);

			reg32_data_b->data_in (data_b_sg);
			reg32_data_b->enable_in (enable_in);
			reg32_data_b->clk_in (clk_in);
			reg32_data_b->data_out (reg32_data_b_sg);

			reg1_op->data_in(reg0_op_sg);
			reg1_op->enable_in(enable_in);
			reg1_op->clk_in(clk_in);
			reg1_op->data_out(reg1_op_sg);

			reg1_result->data_in(reg0_result_sg);
			reg1_result->enable_in(enable_in);
			reg1_result->clk_in(clk_in);
			reg1_result->data_out(reg1_result_sg);

//ETAPA EXECUTE----------------------------
			alu->ra_in(reg32_data_a_sg);
			alu->rb_in(reg32_data_b_sg);
			alu->op_in(reg1_op_sg);
			alu->c_out(alu_sg);
//Tercer PIPE------------------------------
			reg32_result->data_in (alu_sg);
			reg32_result->enable_in (enable_in);
			reg32_result->clk_in (clk_in);
			reg32_result->data_out (reg32_result_sg);

			reg2_op->data_in(reg1_op_sg);
			reg2_op->enable_in(enable_in);
			reg2_op->clk_in(clk_in);
			reg2_op->data_out(reg2_op_sg);

			reg2_result->data_in(reg1_result_sg);
			reg2_result->enable_in(enable_in);
			reg2_result->clk_in(clk_in);
			reg2_result->data_out(reg2_result_sg);
	
//ETAPA MEMORY----------------------------
			datamem->dir_in(reg2_result_sg);
			datamem->op_in(reg2_op_sg);
			datamem->data_in(reg32_result_sg);
			datamem->data_out(data_out_sg);
//Cuarto PIPE------------------------------
			reg32_data_out->data_in (data_out_sg);
			reg32_data_out->enable_in (enable_in);
			reg32_data_out->clk_in (clk_in);
			reg32_data_out->data_out (reg32_data_out_sg);

			reg3_op->data_in(reg2_op_sg);
			reg3_op->enable_in(enable_in);
			reg3_op->clk_in(clk_in);
			reg3_op->data_out(reg3_op_sg);

			reg3_result->data_in(reg2_result_sg);
			reg3_result->enable_in(enable_in);
			reg3_result->clk_in(clk_in);
			reg3_result->data_out(reg3_result_sg);

//ETAPA WRITE BACK------------------------
			registerfile->dirdata_in(reg3_result_sg);
			registerfile->data_in(reg32_data_out_sg);

		}
	private:
		InstrMemory *instmem;
		registerfile *registerfile;
		Alu *alu;
		DataMemory *datamem;
		Regs5 *reg0_op,*reg1_op,*reg2_op,*reg3_op,*reg0_op1,*reg0_op2,*reg0_result,*reg1_result,*reg2_result,*reg3_result;
		Regs32 *reg32_data_a,*reg32_data_b,*reg32_result,*reg32_data_out;
		sc_signal<sc_uint<direction_bits> > dirop1_sg, dirop2_sg, dir_result_sg, op_sg;
		sc_signal<sc_uint<direction_bits> > reg0_op_sg,reg1_op_sg,reg2_op_sg,reg3_op_sg,reg0_op1_sg, reg0_op2_sg, reg0_result_sg,reg1_result_sg,reg2_result_sg,reg3_result_sg;
		sc_signal<sc_int<numbers_of_bits> > data_a_sg, data_b_sg,data_out_sg,reg32_data_a_sg, reg32_data_b_sg,alu_sg,reg32_result_sg,reg32_data_out_sg;
		sc_signal<sc_uint<instruction_length> > instr_sg;
	void split()
	{
		op_sg=(instr_sg.read().range(19,15));
		dir_result_sg=(instr_sg.read().range(14,10)
		dirop2_sg=(instr_sg.read().range(9,5));
		dirop1_sg=(instr_sg.read().range(4,0));
	}
};
#endif
