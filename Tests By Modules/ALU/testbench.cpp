#include"testbench.h"

void testbench::test()
{
	cout<<"Clock"<<" | "<<"Op\t| A\tB\t| C"<<endl;
	cout<<"------------------------------------"<<endl;
//Sumas
	op_out.write(0);
	a_out.write(0);
	b_out.write(0);
	wait();
	print();

	op_out.write(0);
	a_out.write(1);
	b_out.write(0);
	wait();
	print();

	op_out.write(0);
	a_out.write(0);
	b_out.write(1);
	wait();
	print();

	op_out.write(0);
	a_out.write(-1);
	b_out.write(0);
	wait();
	print();

	op_out.write(0);
	a_out.write(0);
	b_out.write(-1);
	wait();
	print();

	op_out.write(0);
	a_out.write(1);
	b_out.write(1);
	wait();
	print();

	op_out.write(0);
	a_out.write(5);
	b_out.write(5);
	wait();
	print();

	op_out.write(0);
	a_out.write(99);
	b_out.write(1);
	wait();
	print();

	op_out.write(0);
	a_out.write(1);
	b_out.write(99);
	wait();
	print();

	op_out.write(0);
	a_out.write(2);
	b_out.write(-2);
	wait();
	print();

	op_out.write(0);
	a_out.write(-2);
	b_out.write(2);
	wait();
	print();

	op_out.write(0);
	a_out.write(3);
	b_out.write(-7);
	wait();
	print();

	op_out.write(0);
	a_out.write(-7);
	b_out.write(3);
	wait();
	print();

	op_out.write(0);
	a_out.write(-9);
	b_out.write(-9);
	wait();
	print();

	op_out.write(0);
	a_out.write(-999);
	b_out.write(-999);
	wait();
	print();

	op_out.write(0);
	a_out.write(999);
	b_out.write(999);
	wait();
	print();

//Restas
	op_out.write(1);
	a_out.write(0);
	b_out.write(0);
	wait();
	print();

	op_out.write(1);
	a_out.write(1);
	b_out.write(0);
	wait();
	print();

	op_out.write(1);
	a_out.write(0);
	b_out.write(1);
	wait();
	print();

	op_out.write(1);
	a_out.write(-1);
	b_out.write(0);
	wait();
	print();

	op_out.write(1);
	a_out.write(0);
	b_out.write(-1);
	wait();
	print();

	op_out.write(1);
	a_out.write(1);
	b_out.write(1);
	wait();
	print();

	op_out.write(1);
	a_out.write(5);
	b_out.write(5);
	wait();
	print();

	op_out.write(1);
	a_out.write(99);
	b_out.write(1);
	wait();
	print();

	op_out.write(1);
	a_out.write(1);
	b_out.write(99);
	wait();
	print();

	op_out.write(1);
	a_out.write(2);
	b_out.write(-2);
	wait();
	print();

	op_out.write(1);
	a_out.write(-2);
	b_out.write(2);
	wait();
	print();

	op_out.write(1);
	a_out.write(3);
	b_out.write(-7);
	wait();
	print();

	op_out.write(1);
	a_out.write(-7);
	b_out.write(3);
	wait();
	print();

	op_out.write(1);
	a_out.write(-9);
	b_out.write(-9);
	wait();
	print();

	op_out.write(1);
	a_out.write(-999);
	b_out.write(-999);
	wait();
	print();

	op_out.write(1);
	a_out.write(999);
	b_out.write(999);
	wait();
	print();

//Multiplicación
	op_out.write(2);
	a_out.write(0);
	b_out.write(0);
	wait();
	print();

	op_out.write(2);
	a_out.write(1);
	b_out.write(0);
	wait();
	print();

	op_out.write(2);
	a_out.write(0);
	b_out.write(1);
	wait();
	print();

	op_out.write(2);
	a_out.write(-1);
	b_out.write(0);
	wait();
	print();

	op_out.write(2);
	a_out.write(0);
	b_out.write(-1);
	wait();
	print();

	op_out.write(2);
	a_out.write(1);
	b_out.write(1);
	wait();
	print();

	op_out.write(2);
	a_out.write(5);
	b_out.write(5);
	wait();
	print();

	op_out.write(2);
	a_out.write(99);
	b_out.write(1);
	wait();
	print();

	op_out.write(2);
	a_out.write(1);
	b_out.write(99);
	wait();
	print();

	op_out.write(2);
	a_out.write(2);
	b_out.write(-2);
	wait();
	print();

	op_out.write(2);
	a_out.write(-2);
	b_out.write(2);
	wait();
	print();

	op_out.write(2);
	a_out.write(3);
	b_out.write(-7);
	wait();
	print();

	op_out.write(2);
	a_out.write(-7);
	b_out.write(3);
	wait();
	print();

	op_out.write(2);
	a_out.write(-9);
	b_out.write(-9);
	wait();
	print();

	op_out.write(2);
	a_out.write(-999);
	b_out.write(-999);
	wait();
	print();

	op_out.write(2);
	a_out.write(999);
	b_out.write(999);
	wait();
	print();

//División
	op_out.write(3);
	a_out.write(0);
	b_out.write(0);
	wait();
	print();

	op_out.write(3);
	a_out.write(1);
	b_out.write(0);
	wait();
	print();

	op_out.write(3);
	a_out.write(0);
	b_out.write(1);
	wait();
	print();

	op_out.write(3);
	a_out.write(-1);
	b_out.write(0);
	wait();
	print();

	op_out.write(3);
	a_out.write(0);
	b_out.write(-1);
	wait();
	print();

	op_out.write(3);
	a_out.write(1);
	b_out.write(1);
	wait();
	print();

	op_out.write(3);
	a_out.write(5);
	b_out.write(5);
	wait();
	print();

	op_out.write(3);
	a_out.write(99);
	b_out.write(1);
	wait();
	print();

	op_out.write(3);
	a_out.write(1);
	b_out.write(99);
	wait();
	print();

	op_out.write(3);
	a_out.write(2);
	b_out.write(-2);
	wait();
	print();

	op_out.write(3);
	a_out.write(-2);
	b_out.write(2);
	wait();
	print();

	op_out.write(3);
	a_out.write(3);
	b_out.write(-7);
	wait();
	print();

	op_out.write(3);
	a_out.write(-7);
	b_out.write(3);
	wait();
	print();

	op_out.write(3);
	a_out.write(-9);
	b_out.write(-9);
	wait();
	print();

	op_out.write(3);
	a_out.write(-999);
	b_out.write(-999);
	wait();
	print();

	op_out.write(3);
	a_out.write(999);
	b_out.write(999);
	wait();
	print();

//Mayor
	op_out.write(100);
	a_out.write(0);
	b_out.write(0);
	wait();
	print();

	op_out.write(100);
	a_out.write(1);
	b_out.write(0);
	wait();
	print();

	op_out.write(100);
	a_out.write(0);
	b_out.write(1);
	wait();
	print();

	op_out.write(100);
	a_out.write(-1);
	b_out.write(0);
	wait();
	print();

	op_out.write(100);
	a_out.write(0);
	b_out.write(-1);
	wait();
	print();

	op_out.write(100);
	a_out.write(1);
	b_out.write(1);
	wait();
	print();

	op_out.write(100);
	a_out.write(5);
	b_out.write(5);
	wait();
	print();

	op_out.write(100);
	a_out.write(99);
	b_out.write(1);
	wait();
	print();

	op_out.write(100);
	a_out.write(1);
	b_out.write(99);
	wait();
	print();

	op_out.write(100);
	a_out.write(2);
	b_out.write(-2);
	wait();
	print();

	op_out.write(100);
	a_out.write(-2);
	b_out.write(2);
	wait();
	print();

	op_out.write(100);
	a_out.write(3);
	b_out.write(-7);
	wait();
	print();

	op_out.write(100);
	a_out.write(-7);
	b_out.write(3);
	wait();
	print();

	op_out.write(100);
	a_out.write(-9);
	b_out.write(-9);
	wait();
	print();

	op_out.write(100);
	a_out.write(-999);
	b_out.write(-999);
	wait();
	print();

	op_out.write(100);
	a_out.write(999);
	b_out.write(999);
	wait();
	print();

//Comparar
	op_out.write(101);
	a_out.write(0);
	b_out.write(0);
	wait();
	print();

	op_out.write(101);
	a_out.write(1);
	b_out.write(0);
	wait();
	print();

	op_out.write(101);
	a_out.write(0);
	b_out.write(1);
	wait();
	print();

	op_out.write(101);
	a_out.write(-1);
	b_out.write(0);
	wait();
	print();

	op_out.write(101);
	a_out.write(0);
	b_out.write(-1);
	wait();
	print();

	op_out.write(101);
	a_out.write(1);
	b_out.write(1);
	wait();
	print();

	op_out.write(101);
	a_out.write(5);
	b_out.write(5);
	wait();
	print();

	op_out.write(101);
	a_out.write(99);
	b_out.write(1);
	wait();
	print();

	op_out.write(101);
	a_out.write(1);
	b_out.write(99);
	wait();
	print();

	op_out.write(101);
	a_out.write(2);
	b_out.write(-2);
	wait();
	print();

	op_out.write(101);
	a_out.write(-2);
	b_out.write(2);
	wait();
	print();

	op_out.write(101);
	a_out.write(3);
	b_out.write(-7);
	wait();
	print();

	op_out.write(101);
	a_out.write(-7);
	b_out.write(3);
	wait();
	print();

	op_out.write(101);
	a_out.write(-9);
	b_out.write(-9);
	wait();
	print();

	op_out.write(101);
	a_out.write(-999);
	b_out.write(-999);
	wait();
	print();

	op_out.write(101);
	a_out.write(999);
	b_out.write(999);
	wait();
	print();

//Or
	op_out.write(6);
	a_out.write(0);
	b_out.write(0);
	wait();
	print();

	op_out.write(6);
	a_out.write(1);
	b_out.write(0);
	wait();
	print();

	op_out.write(6);
	a_out.write(0);
	b_out.write(1);
	wait();
	print();

	op_out.write(6);
	a_out.write(-1);
	b_out.write(0);
	wait();
	print();

	op_out.write(6);
	a_out.write(0);
	b_out.write(-1);
	wait();
	print();

	op_out.write(6);
	a_out.write(1);
	b_out.write(1);
	wait();
	print();

	op_out.write(6);
	a_out.write(5);
	b_out.write(5);
	wait();
	print();

	op_out.write(6);
	a_out.write(99);
	b_out.write(1);
	wait();
	print();

	op_out.write(6);
	a_out.write(1);
	b_out.write(99);
	wait();
	print();

	op_out.write(6);
	a_out.write(2);
	b_out.write(-2);
	wait();
	print();

	op_out.write(6);
	a_out.write(-2);
	b_out.write(2);
	wait();
	print();

	op_out.write(6);
	a_out.write(3);
	b_out.write(-7);
	wait();
	print();

	op_out.write(6);
	a_out.write(-7);
	b_out.write(3);
	wait();
	print();

	op_out.write(6);
	a_out.write(-9);
	b_out.write(-9);
	wait();
	print();

	op_out.write(6);
	a_out.write(-999);
	b_out.write(-999);
	wait();
	print();

	op_out.write(6);
	a_out.write(999);
	b_out.write(999);
	wait();
	print();

//And
	op_out.write(7);
	a_out.write(0);
	b_out.write(0);
	wait();
	print();

	op_out.write(7);
	a_out.write(1);
	b_out.write(0);
	wait();
	print();

	op_out.write(7);
	a_out.write(0);
	b_out.write(1);
	wait();
	print();

	op_out.write(7);
	a_out.write(-1);
	b_out.write(0);
	wait();
	print();

	op_out.write(7);
	a_out.write(0);
	b_out.write(-1);
	wait();
	print();

	op_out.write(7);
	a_out.write(1);
	b_out.write(1);
	wait();
	print();

	op_out.write(7);
	a_out.write(5);
	b_out.write(5);
	wait();
	print();

	op_out.write(7);
	a_out.write(99);
	b_out.write(1);
	wait();
	print();

	op_out.write(7);
	a_out.write(1);
	b_out.write(99);
	wait();
	print();

	op_out.write(7);
	a_out.write(2);
	b_out.write(-2);
	wait();
	print();

	op_out.write(7);
	a_out.write(-2);
	b_out.write(2);
	wait();
	print();

	op_out.write(7);
	a_out.write(3);
	b_out.write(-7);
	wait();
	print();

	op_out.write(7);
	a_out.write(-7);
	b_out.write(3);
	wait();
	print();

	op_out.write(7);
	a_out.write(-9);
	b_out.write(-9);
	wait();
	print();

	op_out.write(7);
	a_out.write(-999);
	b_out.write(-999);
	wait();
	print();

	op_out.write(7);
	a_out.write(999);
	b_out.write(999);
	wait();
	print();

	sc_stop();
}



void testbench::print()
{
	cout<<sc_time_stamp()<<" | "<<op_out.read()<<"\t| "<<a_out.read()<<"\t"<<b_out.read()<<"\t| "<<c_in.read()<<endl;
}
