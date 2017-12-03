#ifndef TESTBENCH_H
#define TESTBENCH_H
#include <systemc.h>
#include <iostream>
using namespace std;

class testbench : public sc_module
{
	public:
		sc_in<bool> clk_in;
		sc_out<bool> enable_out;
		sc_out<sc_uint<5> > data_out;
		sc_in<sc_uint<5> > data_in;
		SC_CTOR(testbench);
		~testbench();
	private:
		void test();
		void print();
};
#endif
