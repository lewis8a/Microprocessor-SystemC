#ifndef REGS5_H
#define REGS5_H
#include <systemc.h>
#include <string>
using namespace std;
class Regs5 : public sc_module
{
	public:
		sc_in < bool > clk_in, enable_in;
		sc_in < sc_uint<5> > data_in;
		sc_out < sc_uint<5> > data_out;
		sc_uint<5> data;
		SC_CTOR(Regs5)
		{
			data=0;		
			SC_METHOD(read);
			sensitive << clk_in.neg();
			SC_METHOD(write);
			sensitive << clk_in.pos();
		}
	private:
		void read()
		{
			if (enable_in.read() == true)
				data=data_in.read();
		}
	void write()
	{
		string n = sc_module::name();
		data_out.write(data);

		if( n.find("opcode") != -1 )
			cout<<endl;
		if( n.find("dir_result") != -1 )
			std::cout<<sc_module::name()<<": \t"<<data<<endl;
		else
			std::cout<<sc_module::name()<<": \t\t"<<data<<endl;
	}
};
#endif
