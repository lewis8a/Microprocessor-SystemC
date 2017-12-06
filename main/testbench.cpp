#include"testbench.h"

void testbench::test()
{
	cout<<"Clock"<<" | "<<"PC\t| Enable"<<endl;
	cout<<"------------------------"<<endl;
	for(int i = 0; i<12; i++)
	{
		pc_out.write(i);
		enable_out.write(1);
		wait();
		print();
	}
	sc_stop();
}

void testbench::print()
{
	cout<<sc_time_stamp()<<" | "<<pc_out.read()<<"\t| "<< enable_out.read()<<endl;
}
