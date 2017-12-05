#ifndef DATAMEMORY_H
#define DATAMEMORY_H
#include <systemc.h>
#include <fstream>
#define data_length 5
#define data_number_read 5
#define instructions_bits 5

class DataMemory: public sc_module
{
	public:
		sc_in< sc_uint<data_number_read> > dir_in;
		sc_in<sc_uint<instructions_bits> > op_in;
		sc_in<sc_uint<data_length> > data_in;
		sc_out< sc_uint<data_length> >data_out;
		SC_CTOR(DataMemory)
		{
			SC_METHOD(operation);
			sensitive << dir_in<<op_in<<data_in;
			dataFile.open("../memoryfiles/datamemory.txt");
		}
		~DataMemory()
		{
			dataFile.close();
		}
	private:
		fstream dataFile;
		void operation()
		{
			unsigned int dir;
			sc_uint<data_length> data;
			char dataTmp[data_length];
			dir = dir_in.read();
			dataFile.seekg(dir*(data_length+1), ios::beg);
			if(op_in.read()==8)
			{
				dataFile.getline(dataTmp,data_length+1);
				for(int i=0; i < data_length;i++)
				{
					if (dataTmp[i] == '1')
					{
						data[data_length-1-i] = 1;
					}
					else
					{
						data[data_length-1-i] = 0;
					}
				}
				data_out.write(data);
			}
			if(op_in.read()==9)
			{
				dataFile<<data_in.read().to_string(SC_BIN).substr(3);
			}
		}
};
#endif
