#ifndef ALU_H
#define ALU_H
#include <systemc.h>
#define instructions_number 3
#define numbers_of_bits 32
class Alu: public sc_module
{
	public:
		sc_in<sc_uint<instructions_number> > op_in;
		sc_in<sc_int<numbers_of_bits> > a_in;
		sc_in<sc_int<numbers_of_bits> > b_in;
		sc_out<sc_int<numbers_of_bits> > c_out;
		SC_CTOR(Alu)
		{
			SC_METHOD(operation);
			sensitive<<a_in<<b_in<<op_in;
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
				break;
				case 1:
				{
					c_out.write(a_in.read() - b_in.read());
				}
				break;
				case 2:
				{
					c_out.write(a_in.read() * b_in.read());
				}
				break;
				case 3:
				{
						c_out.write((float)a_in.read() / (float)b_in.read());
				}
				break;
				case 4:
				{
					if (a_in.read() > b_in.read())
						c_out.write(a_in.read());
					else 
						c_out.write(b_in.read());
				}
				break;
				case 5:
				{
					c_out.write(a_in.read() == b_in.read());  
				}
				break;
				case 6:
				{
					c_out.write(a_in.read() or b_in.read());
				}
				break;
				case 7:
				{
					c_out.write(a_in.read() and b_in.read());  
				}
				break;
			}
		}
};
#endif
