#ifndef REGISTERFILE_H
#define REGISTERFILE_H
#include <systemc.h>
#define TAM_REG 4
class Registerfile: public sc_module
{
	public:
		sc_in<bool> clk;
		sc_in<bool> enable_in;
		sc_in<sc_uint<2> > dirdata_in; //Es la direccion del registro en el cual quiero escribir
		sc_in<sc_uint<2> > dira_in;	//Dirección del operando "a" que se utilizara en la ALU
		sc_in<sc_uint<2> > dirb_in; //Es la direccion del operando "b" que se utilizara en la ALU
		sc_in<sc_uint<32> > data_in;
		sc_out<sc_uint<32> > a_out; //Registro leido que apunta la direccion "dira_in"
		sc_out<sc_uint<32> > b_out;  //Registro leido que apunta la direccion "dira_in"
		SC_CTOR(registerfile)
		{
			SC_METHOD(read);
			sensitive<<clk.neg()<<dira_in<<dirb_in;
			SC_METHOD(write);
			sensitive<<clk.pos()<<dirdata_in<<data_in<<enable_in;
			for (int i=0;i<TAM_REG;i++)
			{
				registers[i]=0;
	  	}
		}
	private:
		sc_uint<32> registers[TAM_REG];
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
