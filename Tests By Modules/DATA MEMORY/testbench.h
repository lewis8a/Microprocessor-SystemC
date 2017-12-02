#ifndef testbench_H
#define testbench_H
#include <systemc.h>
#include <iostream>
#define data_length 5
#define data_number_read 5
#define instructions_bits 4

class testbench: public sc_module
{
	public:
		sc_in_clk clk;
		sc_in< sc_uint<data_length> >data_in;
		sc_out< sc_uint<data_number_read> > dir_out;
		sc_out<sc_uint<instructions_bits> > op_out;
		sc_out<sc_uint<data_length> > data_out;
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
