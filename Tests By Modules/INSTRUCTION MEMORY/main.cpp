#include<instrmemory.h>
#include<testbench.h>

int sc_main(int argc,char *argv[])
{
	sc_time DELAY(10,SC_NS);
	sc_time PERIOD(10,SC_NS);
	sc_clock clk("clock",PERIOD,0.5,DELAY,true);

	sc_signal< sc_uint<instructions_number_read> > dir;
	sc_signal< sc_uint<instruction_length> > instr;
	sc_signal< bool > enable;
	InstrMemory InstrMemory("InstrMemory");
	testbench test("test");

	InstrMemory.dir_in(dir);
	InstrMemory.instr_out(instr);

	test.dir_out(dir);
	test.instr_in(instr);
	test.clk(clk);

	sc_start();
	return 0;
}
