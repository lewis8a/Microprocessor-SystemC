#include"testbench.h"

void testbench::test()
{
	cout<<"Clock"<<" | "<<"PC\t| Enable"<<endl;
	cout<<"------------------------"<<endl;
for(int i=0; i<16; i++)
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
	cout<<sc_time_stamp()<<" | "<<pc_out.read()<<"\t| "<<"LA ENTRADA: "<<LAENTRADA.read().to_string(SC_BIN).substr(3)<<endl;
}
