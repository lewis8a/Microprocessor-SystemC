#ifndef REGISTERFILE_H
#define REGISTERFILE_H
#include <systemc.h>
#define tam_reg 4
#define direction_bits 2
#define numbers_of_bits 32
class Registerfile: public sc_module
{
	public:
		sc_in<bool> clk;
		sc_in<bool> enable_in;
		sc_in<sc_uint<direction_bits> > dirdata_in; //Es la direccion del registro en el cual quiero escribir
		sc_in<sc_uint<direction_bits> > dira_in;	//Dirección del operando "a" que se utilizara en la ALU
		sc_in<sc_uint<direction_bits> > dirb_in; //Es la direccion del operando "b" que se utilizara en la ALU
		sc_in<sc_int<numbers_of_bits> > data_in;
		sc_out<sc_int<numbers_of_bits> > a_out; //Registro leido que apunta la direccion "dira_in"
		sc_out<sc_int<numbers_of_bits> > b_out;  //Registro leido que apunta la direccion "dira_in"
		SC_CTOR(registerfile)
		{
			SC_METHOD(read);
			sensitive<<clk.neg()<<dira_in<<dirb_in;
			SC_METHOD(write);
			sensitive<<clk.pos()<<dirdata_in<<data_in<<enable_in;
			for (int i=0;i<tam_reg;i++)
			{
				registers[i]=0;
	  	}
		}
	private:
		sc_int<numbers_of_bits> registers[tam_reg];
		void read()
		{
			if(enable_in == false)
			{
				a_out.write(registers[ dira_in.read() ] );
				b_out.write(registers[ dirb_in.read() ] );
			}
		} 
		void write()
		{
			if(enable_in == true)
			{
				registers[dirdata_in.read()] = data_in.read();
			}
		}
};
#endif
