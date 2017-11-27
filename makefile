CXXFLAGS= -Wall
all:limpar_tela programa limpar
programa: main.o grafos.o tree.o dados.o
	g++ -o Projeto4 grafos.o tree.o dados.o main.o

main.o: main.cpp grafos.hpp dados.hpp
	g++ $(CXXFLAGS) -c main.cpp

grafos.o: grafos.cpp grafos.hpp
	g++ $(CXXFLAGS) -c grafos.cpp

tree.o: tree.hpp tree.cpp
	g++ $(CXXFLAGS) -c tree.cpp

dados.o: dados.cpp dados.hpp
	g++ $(CXXFLAGS) -c dados.cpp

limpar_tela:
	clear

limpar:
	rm -rf *.o