#ifndef REGS5_H
#define REGS5_H
#include <systemc.h>
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
		data_out.write(data);
		std::cout<<sc_module::name()<<": "<<data_out.read()<<endl;
	}
};
#endif
