#ifndef ALU_H
#define ALU_H
#include <systemc.h>
class Alu: public sc_module
{
	public:
		sc_in<sc_uint<3> > op;
		sc_in<sc_uint<32> > a_in;
		sc_in<sc_uint<32> > b_in;
		sc_out<sc_uint<32> > c_out;
		SC_CTOR(alu)
		{
			SC_METHOD(operation);
			sensitive << a_in << b_in << op_in;
		}
	private:
		void operation()
		{
			switch(op_in.read())
			{
				case 0:
				{
					c_out.write(a_in.read() + b_in.read());
				}
				case 1:
				{
					c_out.write(a_in.read() - b_in.read());
				}
				case 2:
				{
					c_out.write(a_in.read() * b_in.read());
				}
				case 3:
				{
					if(b_in.read()!=0)
						c_out.write(a_in.read() / b_in.read());
				}
				break;
				case 4:
				{
					if (a_in.read() > b_in.read())
					{
						c_out.write(a_in.read());
					}
					else 
					{
						c_out.write(b_in.read());
					}
				}
				break;
				case 5:
				{
					c_out.write(a_in.read() or b_in.read());
				}
				break;
				case 6:
				{
					c_out.write(a_in.read() and b_in.read());  
				}
				break;
			}
		}
};
#endif
