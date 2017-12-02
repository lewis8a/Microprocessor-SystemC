#ifndef testbench_H
#define testbench_H
#include <systemc.h>
#include <iostream>
#define instruction_length 20
#define instructions_number_read 4

class testbench: public sc_module
{
	public:
		sc_in_clk clk;
		sc_in< sc_uint<instruction_length> >instr_in;
		sc_out< sc_uint<instructions_number_read> > dir_out;
		SC_CTOR(testbench)
		{
			SC_THREAD(test);
			sensitive<<clk.neg();
			dont_initialize();
}
	private:
		void test();
		void print();
};
#endif
