#ifndef REGISTERFILE_H
#define REGISTERFILE_H
#include <systemc.h>
#define tam_reg 4
#define instructions_bits 5
#define direction_bits 5
#define numbers_of_bits 5

class Registerfile: public sc_module
{
	public:
		sc_in<bool> clk;
		sc_in<sc_uint<instructions_bits> > enable_in;
		sc_in<sc_uint<direction_bits> > dirdata_in; //Es la direccion del registro en el cual quiero escribir
		sc_in<sc_uint<direction_bits> > dira_in;	//Dirección del operando "a" que se utilizara en la ALU
		sc_in<sc_uint<direction_bits> > dirb_in; //Direccion del operando "b" que se utilizara en la ALU
		sc_in<sc_uint<numbers_of_bits> > data_in;
		sc_out<sc_uint<numbers_of_bits> > a_out; //Registro leido que apunta la direccion "dira_in"
		sc_out<sc_uint<numbers_of_bits> > b_out;  //Registro leido que apunta la direccion "dirb_in"
		// sc_out<sc_uint<numbers_of_bits> > s_out;  //Registro leido que apunta la direccion "dirdata_in"
		SC_CTOR(Registerfile)
		{
			SC_METHOD(write);
			sensitive<<clk.pos()<<dirdata_in<<data_in<<enable_in;
			SC_METHOD(read);
			sensitive<<clk.neg()<<enable_in;
			for (int i=0;i<tam_reg;i++)
			{
				registers[i]=0;
	  	}
		}
	private:
		sc_uint<numbers_of_bits> registers[tam_reg];
		void write()
		{
			if( (enable_in.read() != 9) )
			{
				registers[dirdata_in.read()] = data_in.read();
				cout<<endl<<"op: "<<enable_in.read()<<" write: "<<data_in.read()<<"dir: "<<dirdata_in.read()<<endl;
			}
		}
		void read()
		{
			a_out.write(registers[ dira_in.read() ] );
			b_out.write(registers[ dirb_in.read() ] );
		}
};
#endif
