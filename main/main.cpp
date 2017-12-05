#include<richard.h>
#include<testbench.h>

int sc_main(int argc,char *argv[])
{
	sc_time DELAY(10,SC_NS);
	sc_time PERIOD(10,SC_NS);
	sc_clock clk("clock",PERIOD,0.5,DELAY,true);

	sc_signal< sc_uint<instructions_number_read> > i1;
	sc_signal< bool > enable;
	Richard richard("richard");
	testbench test("test");

	richard.pc_in(i1);
	richard.enable_in(enable);
	richard.clk_in(clk);

	test.pc_out(i1);
	test.enable_out(enable);
	test.clk(clk);

	sc_start();
	return 0;
}
