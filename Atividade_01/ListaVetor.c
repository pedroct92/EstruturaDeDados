#include <stdlib.h>
#include <stdio.h>
#include "ListaVetor.h"

int main() {
    Lista L;
    bool OK;
    int i = 0,n;

    srand(time(NULL));

    imprimeListaTotal(&L);
    initLista(&L);
    imprimeLista(&L);

    do{
    	float n = rand() % 10;
        OK = insereElemento(&L, n);
		if(!OK)
            break;
    }while (1);

    imprimeLista(&L);
    n = tamLista(&L);

    for (i = 0 ; i < n ; i++){
        OK = removeElemento(&L, i);
    	if (OK)
    		printf("Remocao %f OK\n", (float)i);
    	else
    		printf("Remocao %f nao OK\n", (float)i);
    }

    imprimeLista(&L);
    imprimeListaTotal(&L);
}



