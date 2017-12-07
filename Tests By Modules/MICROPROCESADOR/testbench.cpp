#include"testbench.h"

void testbench::test()
{
	for(int i = 0; i<15; i++)
	{
		cout<<endl<<"\tInstrucción: "<<i<<endl;
		pc_out.write(i);
		enable_out.write(1);
		wait();
		//print();
	}
	sc_stop();
}

void testbench::print()
{
	cout<<sc_time_stamp()<<" | "<<pc_out.read()<<"\t| "<< enable_out.read()<<endl;
}
