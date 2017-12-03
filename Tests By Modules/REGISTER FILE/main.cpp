#include<registerfile.h>
#include<testbench.h>

int sc_main(int argc,char *argv[])
{
	sc_time DELAY(10,SC_NS);
	sc_time PERIOD(10,SC_NS);
	sc_clock clk("clock",PERIOD,0.5,DELAY,true);
	
	sc_signal< sc_uint<direction_bits> > dird,dira,dirb;
	sc_signal< sc_uint<numbers_of_bits> > a,b,data_in;
	sc_signal< sc_uint<instructions_bits> >  enable;
	
	Registerfile registerfile("registerfile");
	testbench test("test");

	registerfile.enable_in(enable);
	registerfile.dirdata_in(dird);
	registerfile.dira_in(dira);
	registerfile.dirb_in(dirb);
	registerfile.data_in(data_in);
	registerfile.a_out(a);
	registerfile.b_out(b);
	registerfile.clk(clk);

	test.enable_out(enable);
	test.dirdata_out(dird);
	test.dira_out(dira);
	test.dirb_out(dirb);
	test.data_out(data_in);
	test.a_in(a);
	test.b_in(b);
	test.clk(clk);

	sc_start();
	return 0;
}
