#include<alu.h>
#include<testbench.h>

int sc_main(int argc,char *argv[])
{
	sc_time DELAY(10,SC_NS);
	sc_time PERIOD(10,SC_NS);
	sc_clock clk("clock",PERIOD,0.5,DELAY,true);

	sc_signal< sc_uint<instructions_number> > op;
	sc_signal< sc_uint<numbers_of_bits> > a,b,c;

	Alu alu("alu");
	testbench tb("tb");

	alu.op_in(op);
	alu.a_in(a);
	alu.b_in(b);
	alu.c_out(c);

	tb.clk(clk);
	tb.op_out(op);
	tb.a_out(a);
	tb.b_out(b);
	tb.c_in(c);
	
	sc_start();
	return 0;
}
