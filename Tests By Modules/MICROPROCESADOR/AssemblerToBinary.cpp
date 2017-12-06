#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <iomanip>
using namespace std;

string decimal_to_binary(string);

int main(int argc, char *argv[])
{
	if (argc!=2)
	{
		cerr<<"Error en la lectura"<<endl;
		return 1;  
	}
	ifstream entrada(argv[1]);
	if (entrada.fail())
	{
		cerr<<"Error al vincular el archivo"<<endl;
		return 2;
	}
	ofstream salida("instrmemory.txt");
	if (salida.fail())
	{
		cerr<<"Error al vincular el archivo"<<endl;
		return 3;
	}
	string cod, dir_result, dir_op1, dir_op2;
	while(!entrada.eof())
	{
		getline(entrada,cod,' ');
		getline(entrada,dir_result,' ');
		getline(entrada,dir_op1,' ');		
		getline(entrada,dir_op2,'\n');

		if (!entrada.fail())
		{
			salida<<right<<setw(5)<<setfill('0');

			if(cod == "ADD")
				salida<<"0";
			if(cod == "SUB")
				salida<<"1";
			if(cod == "MUL")
				salida<<"10";
			if(cod == "DIV")
				salida<<"11";
			if(cod == "CMP")
				salida<<"100";
			if(cod == "EQU")
				salida<<"101";
			if(cod == "OOR")
				salida<<"110";
			if(cod == "AND")
				salida<<"111";
			if(cod == "LOAD")
				salida<<"1000";
			if(cod == "STORE")
				salida<<"1001";

			salida<<right<<setw(5)<<setfill('0')<<decimal_to_binary(dir_result);
			salida<<right<<setw(5)<<setfill('0')<<decimal_to_binary(dir_op1);
			salida<<right<<setw(5)<<setfill('0')<<decimal_to_binary(dir_op2);
			salida<<'\n';
		}
	}
	entrada.close();
	salida.close();
	return 0;
}

string decimal_to_binary (string dir)
{
	string binary;
	dir = dir.substr(1,dir.length()-1);
	int number;
	number = atoi(dir.c_str());
	if (number > 0)
	{
		while(number > 0)
		{
			if (number%2 == 0)
				binary = "0" + binary;
			else
				binary = "1" + binary;
			number = (int)number/2;
		}
	} 
	else
		return "0";
	return binary;
}
