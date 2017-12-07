#ifndef testbench_H
#define testbench_H
#include <systemc.h>
#include <iostream>
using namespace std;
#define instructions_number_read 5

class testbench: public sc_module
{
	public:
		sc_in_clk clk;
		sc_out<bool> enable_out;
		sc_out<sc_uint<instructions_number_read> > pc_out;
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
