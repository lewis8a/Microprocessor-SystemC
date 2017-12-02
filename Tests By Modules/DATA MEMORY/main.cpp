#include<datamemory.h>
#include<testbench.h>

int sc_main(int argc,char *argv[])
{
	sc_time DELAY(10,SC_NS);
	sc_time PERIOD(10,SC_NS);
	sc_clock clk("clock",PERIOD,0.5,DELAY,true);

	sc_signal< sc_uint<data_number_read> > dir;
	sc_signal< sc_uint<data_length> > data_1,data_2;
	sc_signal<sc_uint<instructions_bits> > op;
	DataMemory DataMemory("DataMemory");
	testbench test("test");

	DataMemory.op_in(op);
	DataMemory.dir_in(dir);
	DataMemory.data_in(data_1);
	DataMemory.data_out(data_2);

	test.op_out(op);
	test.dir_out(dir);
	test.data_in(data_2);
	test.data_out(data_1);
	test.clk(clk);

	sc_start();
	return 0;
}
