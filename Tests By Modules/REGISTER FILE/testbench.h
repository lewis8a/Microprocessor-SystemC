#ifndef testbench_H
#define testbench_H
#include <systemc.h>
#include <iostream>
#define instructions_bits 5
#define direction_bits 5
#define numbers_of_bits 5

class testbench: public sc_module
{
	public:
		sc_in_clk clk;
		sc_out<sc_uint<instructions_bits> > enable_out;
		sc_out<sc_uint<direction_bits> > dirdata_out;
		sc_out<sc_uint<direction_bits> > dira_out;
		sc_out<sc_uint<direction_bits> > dirb_out;
		sc_out<sc_uint<numbers_of_bits> > data_out;
		sc_in<sc_uint<numbers_of_bits> > a_in;
		sc_in<sc_uint<numbers_of_bits> > b_in;
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
