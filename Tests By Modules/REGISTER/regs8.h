#ifndef REGS8_H
#define REGS8_H
#include <systemc.h>
class Regs8 : public sc_module
{
	public:
		sc_in < bool > clk_in, enable_in;
		sc_in < sc_int<8> > data_in;
		sc_out < sc_int<8> > data_out;
		sc_int<8> data;
		SC_CTOR(Regs8)
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
	}
};
#endif
