#include"testbench.h"

void testbench::test()
{
	cout<<"Clock"<<" | "<<"Dir_Out\t| Instr_In"<<endl;
	cout<<"--------------------------------------"<<endl;
	for (int i=0;i<8;i++)
	{
		dir_out.write(i);
		wait();
		print();
	}
	sc_stop();
}

void testbench::print()
{
	cout<<sc_time_stamp()<<" | "<<dir_out.read()<<"\t| "<<instr_in.read().to_string(SC_BIN).substr(3)<<endl;
}
