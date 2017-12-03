#include"testbench.h"

testbench::testbench(sc_module_name nm): sc_module(nm)
{
	SC_THREAD(test);
	sensitive<<clk_in.neg();
}
testbench :: ~testbench(){}

void testbench :: test()
{
	cout<<"Clock"<<" | "<<"Data_In\t| Enable | Data_Out"<<endl;
	cout<<"-----------------------------------"<<endl;

	enable_out.write(1);
	data_out.write(15);	
	wait();
	print();

	enable_out.write(0);
	data_out.write(2);	
	wait();
	print();

	enable_out.write(0);
	data_out.write(3);	
	wait();
	print();
	
	enable_out.write(1);
	data_out.write(3);	
	wait();
	print();

	enable_out.write(0);
	data_out.write(7);	
	wait();
	print();	

  sc_stop();
}

void testbench :: print()
{
	cout<<sc_time_stamp()<<" |\t"<<data_out.read()<<"\t| "<<enable_out.read()<<"\t | "<<data_in.read()<<endl;
}
