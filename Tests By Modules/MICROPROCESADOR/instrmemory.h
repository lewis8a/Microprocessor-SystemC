#ifndef INSTRMEMORY_H
#define INSTRMEMORY_H
#include <systemc.h>
#include <fstream>
#define instruction_length 20
#define instructions_number_read 5
class InstrMemory: public sc_module
{
	public:
		sc_in< sc_uint<instructions_number_read> > dir_in;
		sc_out< sc_uint<instruction_length> >instr_out;
		SC_CTOR(InstrMemory)
		{
			SC_METHOD(search);
			sensitive << dir_in;
			memoryFile.open("instrmemory.txt");
		}
		~InstrMemory()
		{
			memoryFile.close();
		}
	private:
		ifstream memoryFile;
		void search()
		{
			unsigned int dir;
			sc_uint<instruction_length> instr;
			char instrTmp[instruction_length];
			dir = dir_in.read();
			memoryFile.seekg(dir*(instruction_length+1), ios::beg);
			memoryFile.getline(instrTmp,instruction_length+1);
			for(int i=0; i < instruction_length;i++)
			{
				if (instrTmp[i] == '1')
				{
					instr[instruction_length-1-i] = 1;
				}
				else
				{
					instr[instruction_length-1-i] = 0;
				}
			}
			instr_out.write(instr);
		}
};
#endif
