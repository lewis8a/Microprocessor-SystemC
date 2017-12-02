programa=AssemblertoBinary

all:AssemblertoBinary.exe
	./AtB.exe assembler.txt

AssemblertoBinary.exe: AssemblertoBinary.o
	g++ AssemblerToBinary.o -o AtB.exe

AssemblertoBinary.o:
	g++ AssemblerToBinary.cpp -c

clean:
	rm -fr *.o *.exe memoryFile.txt
