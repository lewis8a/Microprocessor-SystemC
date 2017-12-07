#-----------------------------------------------------------------------------------------
# Modelo de Makefile para compilaciï¿½n de diseï¿½os realizados con la librerï¿½a SystemC
#----------------------------------------------------------------------------------------

# Especificar los archivos .cpp en SRCS y los archivos .h en SRCH
SRCS = testbench.cpp main.cpp

# Nombre del ejecutable
TARGET = test
SYSTEMC = /usr/local/systemc-2.3.1
INCDIR = -I. -I.. -I$(SYSTEMC)/include
LIBDIR = -L. -L.. -L$(SYSTEMC)/lib-linux/
LIBS   = -lsystemc -lm

CC     = clang++
CFLAGS = -g -Wno-deprecated -Wall
OBJS   = $(SRCS:.cpp=.o)

OTHER  = -Wl,-rpath=/$(SYSTEMC)/lib-linux

EXE    = $(TARGET)

 .SUFFIXES: .cpp .o

$(EXE): $(OBJS) $(SRCH)
	$(CC) $(CFLAGS) $(INCDIR) $(LIBDIR) $(OTHER) -o $@ $(OBJS) $(LIBS) 2>&1 | c++filt

all: $(EXE) exp

.cpp.o:
	$(CC) $(DEBUG) $(CFLAGS) $(INCDIR) -c $<

clean:
	rm -f $(OBJS) *~ $(EXE) *.bak $(TARGET).stackdump *.vcd

exp:
	export LD_LIBRARY_PATH=$(SYSTEMC)/lib-linux