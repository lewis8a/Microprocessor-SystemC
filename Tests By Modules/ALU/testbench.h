#ifndef testbench_H
#define testbench_H
#include <systemc.h>
#include <iostream>
#define instructions_number 5
#define numbers_of_bits 5
class testbench: public sc_module
{
	public:
		sc_in_clk clk;
		sc_in<sc_uint<numbers_of_bits> > c_in;
		sc_out<sc_uint<instructions_number> > op_out;
		sc_out<sc_uint<numbers_of_bits> > a_out;
		sc_out<sc_uint<numbers_of_bits> > b_out;
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
