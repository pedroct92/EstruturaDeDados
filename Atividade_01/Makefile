.c.o:   $*.h
	gcc -c $*.c

.cpp.o:	$*.h
	g++	-c $*.cpp

all:	ListaVetor \
		ListaVetorDinamico 
		
		
ListaVetor:  ListaVetor.o
	gcc -o $@ $^

ListaVetorDinamico:  ListaVetorDinamico.o
	gcc -o $@ $^

clean:
	rm *.o *.*~ *~	ListaVetor \
					ListaVetorDinamico 
