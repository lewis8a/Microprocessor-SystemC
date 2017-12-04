#ifndef MULTIPLEXOR_H
#define MULTIPLEXOR_H
#include <systemc.h>

class Multiplexor: sc_module
{
	public:
		sc_in<sc_uint<5> > a_in, b_in;
		sc_in<sc_uint<1> > selector;
		sc_out<sc_uint<5> > s_out;
		SC_CTOR(Multiplexor)
		{
			SC_METHOD(select);
			sensitive<<selector<<a_in<<b_in;
		}
	private:
	void select()
	{
		switch(selector.read())
		{
			case 0: s_out.write(a_in.read()); break;
			case 1: s_out.write(b_in.read()); break;
		}
	}
};
#endif
