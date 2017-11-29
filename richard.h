#ifndef RICHARD_H
#define RICHARD_H
#include "alu.h"
#include "registerfile.h"
#include "instrmemory.h"
#include "regs32.h"
#define direction_bits 2
#define numbers_of_bits 32
#define instruction_length 6
#define instructions_number_read 4
class Richard : public sc_module
{
	public:
		sc_in <bool> clk; //Reloj
		sc_in<bool > enable_in, write_enable_in; //Direcciones
		sc_in<sc_uint<instructions_number_read> > pc_in; //Es la entrada que viene del pc, y nos indica cual instruccion buscaremos
		sc_out<sc_int<numbers_of_bits> > r_out; //Resultado de la operacion realizada en la ALU
		SC_CTOR(Richard)
		{
			SC_METHOD(split);
			sensitive << reg6_1_sg ; //Instruccion cuando sale del REGISTRO FETCH (el primer pipe)
			alu1 = new alu("alu1");
			registerfile1 = new registerfile("registerfile1");
			reg2_1 = new regs2("reg2_1");
			reg6_1 = new regs6("reg6_1");
			reg32_1 = new regs32("reg32_1");
			reg32_2 = new regs32("reg32_2");
			reg32_3 = new regs32("reg32_3");
			memory = new InstrMemory("memory");
//ETAPA FETCH------------------------------
			memory->dir_in(pc_in);
			memory->instr_out(instr_sg);
//Primer PIPE------------------------------
			reg6_1 -> data_in (instr_sg);
			reg6_1 -> enable_in (enable_in);
			reg6_1 -> clk_in (clk_in);
			reg6_1 -> data_out (reg6_1_sg);	
//ETAPA DECODE-----------------------------
			registerfile1 -> write_enable_in(write_enable_in);
			registerfile1 -> dirdata_in(op);
			registerfile1 -> dira_in(dira);
			registerfile1 -> dirb_in(dirb);
			registerfile1 -> data_in(gnd);
			registerfile1 -> ra_out(da);
			registerfile1 -> rb_out(db);
			registerfile1 -> clk(clk_in);
//Segundo PIPE-----------------------------
			reg32_1 -> data_in (da);
			reg32_1 -> enable_in (enable_in);
			reg32_1 -> clk_in (clk_in);
			reg32_1 -> data_out (reg32_1_sg);
			reg32_2 -> data_in (db);
			reg32_2 -> enable_in (enable_in);
			reg32_2 -> clk_in (clk_in);
			reg32_2 -> data_out (reg32_2_sg);
			reg2_1 -> data_in (op);
			reg2_1 -> enable_in (enable_in);
			reg2_1 -> clk_in (clk_in);
			reg2_1 -> data_out (reg2_1_sg);
//ETAPA EXECUTE----------------------------
			alu1 -> ra_in (reg32_1_sg);
			alu1 -> rb_in (reg32_2_sg);
			alu1 -> op_in (reg2_1_sg);
			alu1 -> r_out (alu_sg);
//Tercer PIPE
			reg32_3 -> data_in (alu_sg);
			reg32_3 -> enable_in (enable_in);
			reg32_3 -> clk_in (clk_in);
			reg32_3 -> data_out (r_out);
//ETAPA ACCESS MEMORY NO IMPLEMENTADA------------

//ETAPA WRITEE BACK NO IMPLEMENTADA--------------

		}
	private:
		alu *alu1;
		registerfile *registerfile1;
		InstrMemory *memory;
		regs2 *reg2_1;
		regs6 *reg6_1;
		regs32 *reg32_1, *reg32_2, *reg32_3;
		sc_signal<sc_uint<direction_bits> > dira, dirb, op, reg2_1_sg;
		sc_signal<sc_uint<instruction_length> > reg6_1_sg, instr_sg;
		sc_signal<sc_int<numbers_of_bits> > da, db, reg32_1_sg, reg32_2_sg, alu_sg, gnd;
	void split()
	{
		op = (reg6_1_sg.read().range(5,4));
		dira = (reg6_1_sg.read().range(3,2));
		dirb = (reg6_1_sg.read().range(1,0));
	}
};
#endif
