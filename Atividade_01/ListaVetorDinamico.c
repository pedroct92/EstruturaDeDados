// ******************************************************************
// Exemplo de implementacao de Lista utilizando agregados homogeneos
// ******************************************************************
#include <stdio.h>
#include <stdlib.h>
#include "ListaVetorDinamico.h"

int main(int argc, char** argv) {
    Lista L0, L1;
    bool OK;
    int i = 0, n;

    initLista(&L0);
    //imprimeLista(&L0);
    //imprimeListaTotal(&L0);

    initLista(&L1);
    //imprimeLista(&L1);
    //imprimeListaTotal(&L1);

    do {
    	float n = rand() % 50;
    	OK = insereElemento(&L0, n);
		if (!OK)
    		break;
    	i++;
    } while (i < 5);

    i = 0;
    do {
    	float n = rand() % 50;
    	OK = insereElemento(&L1, n);
		if (!OK)
    		break;
    	i++;
    } while (i < 10);

   	imprimeLista(&L0);
   	imprimeLista(&L1);

	n = tamLista(&L0);

    for (i = 0 ; i < n ; i++){
		OK = removeElemento(&L0, i);
    	if (OK)
    		printf("Remocao %f OK\n", (float)i);
    	else
    		printf("Remocao %f nao OK\n", (float)i);
    }

    n = tamLista(&L1);

    for (i = 0 ; i < n ; i++){
        OK = removeElemento(&L1, i);
    	if (OK)
    		printf("Remocao %f OK\n", (float)i);
    	else
    		printf("Remocao %f nao OK\n", (float)i);
    }

    imprimeLista(&L0);
    imprimeLista(&L1);

    imprimeListaTotal(&L0);
    imprimeListaTotal(&L1);
}
