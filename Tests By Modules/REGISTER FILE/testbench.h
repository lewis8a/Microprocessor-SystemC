#ifndef testbench_H
#define testbench_H
#include <systemc.h>
#include <iostream>
#define direction_bits 2
#define numbers_of_bits 32

class testbench: public sc_module
{
	public:
		sc_in_clk clk;
		sc_out<bool> enable_out;
		sc_out<sc_uint<direction_bits> > dirdata_out;
		sc_out<sc_uint<direction_bits> > dira_out;
		sc_out<sc_uint<direction_bits> > dirb_out;
		sc_out<sc_int<numbers_of_bits> > data_out;
		sc_in<sc_int<numbers_of_bits> > a_in;
		sc_in<sc_int<numbers_of_bits> > b_in;
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
