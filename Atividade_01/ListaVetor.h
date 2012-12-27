#define MAX_LISTA 10

typedef enum { FALSE, TRUE } bool;

typedef struct { float V[MAX_LISTA];
               	 int fim;
                } Lista;


// ***********************************************
// ******  initLista                        ******
// ***********************************************
void initLista(Lista *lst){
    lst->fim = -1;
}

// ***********************************************
// ******  tamLista                         ******
// ***********************************************

int tamLista(Lista *lst){
    return lst->fim + 1;
}

// ***********************************************
// ******  imprimeLista                     ******
// ***********************************************
void imprimeLista(Lista *lst){


}

// ***********************************************
// ******  imprimeListaTotal                ******
// ***********************************************
void imprimeListaTotal(Lista *lst){
    int i;

    printf("----> INICIO Lista Total <---------\n");

    for(i = 0; i< MAX_LISTA; i++){
        printf("{%f} \n", lst->V[i]);
    }

    printf("----> FIM Lista Total <---------\n");
}

// ***********************************************
// ******  insereElemento                   ******
// ***********************************************
bool insereElemento(Lista *lst, float var){
    bool retorno = 0;

    if(lst->fim < MAX_LISTA-1){
        lst->V[++lst->fim] = var;
        retorno = 1;
    }
    return retorno;
}

// ***********************************************
// ******  buscaElemento                    ******
// ***********************************************
int buscaElemento(Lista *lst){
    return 0;
}

// ***********************************************
// ******  removeElemento                   ******
// ***********************************************
bool removeElemento(Lista *lst){
    bool retorno = 0;
    return retorno;
}
