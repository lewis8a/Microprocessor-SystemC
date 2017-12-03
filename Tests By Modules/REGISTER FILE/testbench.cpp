#include"testbench.h"

void testbench::test()
{
	cout <<"Clock"<<" | "<<"Enable"<<"\t| " <<" Dir_Data\t"<<"Data"<<"\t| " <<"Dir_A\t"<<"Dir_B\t"<<" A\t"<<" B"<<endl;
  cout<<"-------------------------------------------------------------------"<<endl;

	enable_out.write(1000);
	dirdata_out.write(0);
	data_out.write(7);
	dira_out.write(0);
	dirb_out.write(0);
	wait();
	print();

	enable_out.write(1000);
	dirdata_out.write(1);
	data_out.write(7);
	dira_out.write(1);
	dirb_out.write(1);
	wait();
	print();

	enable_out.write(1000);
	dirdata_out.write(2);
	data_out.write(7);
	dira_out.write(2);
	dirb_out.write(2);
	wait();
	print();

	enable_out.write(1000);
	dirdata_out.write(3);
	data_out.write(7);
	dira_out.write(3);
	dirb_out.write(3);
	wait();
	print();

	enable_out.write(1001);
	dirdata_out.write(3);
	data_out.write(3);
	dira_out.write(0);
	dirb_out.write(1);
	wait();
	print();
	
	enable_out.write(1001);
	dirdata_out.write(1);
	data_out.write(14);
	dira_out.write(0);
	dirb_out.write(3);
	wait();
	print();
	
	enable_out.write(1000);
	dirdata_out.write(3);
	data_out.write(10);
	dira_out.write(3);
	dirb_out.write(1);
	wait();
	print();

	enable_out.write(1001);
	dirdata_out.write(2);
	data_out.write(9);
	dira_out.write(1);
	dirb_out.write(3);
	wait();
	print();
	
	enable_out.write(1000);
	dirdata_out.write(2);
	data_out.write(12);
	dira_out.write(2);
	dirb_out.write(0);
	wait();
	print();

	enable_out.write(1001);
	dirdata_out.write(3);
	data_out.write(13);
	dira_out.write(1);
	dirb_out.write(3);
	wait();
	print();
	
	enable_out.write(1000);
	dirdata_out.write(3);
	data_out.write(12);
	dira_out.write(2);
	dirb_out.write(3);
	wait();
	print();
	
	sc_stop();
}

void testbench::print()
{
  cout<<sc_time_stamp()<< " | "<<enable_out.read()<<"\t| " <<dirdata_out.read()<<"\t\t"<<data_out.read()<<"\t| "<<dira_out.read()<<"\t "<< dirb_out.read()<<"\t "<<a_in.read()<<"\t "<<b_in.read()<<endl;
}
