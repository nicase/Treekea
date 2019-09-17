OPCIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG  -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

program.exe: Sala.o Sistema.o Almacen.o main.o
	g++ -o program.exe *.o

Sala.o:  Sala.cc Sala.hh 
	g++ -c Sala.cc $(OPCIONS)

Sistema.o:  Sistema.cc Sistema.hh 
	g++ -c Sistema.cc $(OPCIONS)

Almacen.o: Almacen.cc Almacen.hh Sala.hh BinTree.hh Sistema.hh
	g++ -c Almacen.cc $(OPCIONS)

main.o: main.cc Sistema.hh Almacen.hh
	g++ -c main.cc $(OPCIONS)

clean:
	rm *.o
	rm *.exe

