#ifndef MULTIPLEXOR_H
#define MULTIPLEXOR_H
#include <systemc.h>

class Multiplexor: sc_module
{
	public:
		sc_in<sc_uint<5> > a_in, b_in;
		sc_in<sc_uint<5> > selector;
		sc_out<sc_uint<5> > s_out;
		SC_CTOR(Multiplexor)
		{
			SC_METHOD(select);
			sensitive<<selector<<a_in<<b_in;
		}
	private:
	void select()
	{
		if(selector.read()==8)
			s_out.write(b_in.read());
		else
			s_out.write(a_in.read());
		string n = sc_module::name();
		cout<<endl<<sc_module::name()<<": \t"<<"selector: "<<selector.read()<<" a: "<<a_in.read()<<" b: "<<b_in.read()<<" s: "<<s_out.read()<<endl;

	}
};
#endif
