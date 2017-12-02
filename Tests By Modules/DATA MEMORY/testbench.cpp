#include"testbench.h"

void testbench::test()
{
	cout<<"Clock"<<" | Operation | "<<"Dir_Out | "<<"Data_Out\t| Data_In"<<endl;
	cout<<"-------------------------------------------------"<<endl;
//Leer
	op_out.write(1000);
	dir_out.write(0);
	data_out.write(111);
	wait();
	print();
//Escribir
	op_out.write(1001);
	dir_out.write(1);
	data_out.write(111);
	wait();
	print();
//Leer
	op_out.write(1000);
	dir_out.write(2);
	data_out.write(111);
	wait();
	print();
//Escribir
	op_out.write(1001);
	dir_out.write(3);
	data_out.write(111);
	wait();
	print();
//Leer
	op_out.write(1000);
	dir_out.write(1);
	data_out.write(11);
	wait();
	print();
//Leer
	op_out.write(1000);
	dir_out.write(3);
	data_out.write(11);
	wait();
	print();

	for(int i=10;i<20;i++)
	{
	op_out.write(1001);
	dir_out.write(i);
	data_out.write(i);
	wait();
	print();
	}

	sc_stop();
}

void testbench::print()
{
	cout<<sc_time_stamp()<<" | "<<op_out<<"\t  | "<<dir_out.read()<<"\t    | "<<data_out.read().to_string(SC_BIN).substr(3)<<"\t| "<<data_in.read().to_string(SC_BIN).substr(3)<<endl;
}
