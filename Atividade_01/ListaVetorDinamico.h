#define MAX_LISTA 10

typedef enum { FALSE, TRUE } bool;

typedef struct { float dado;
                 int   prox;
               } tNo;

typedef struct { tNo V[MAX_LISTA];
                 int ini;
                 int tm;
               } Lista;

int proxDisponivel(Lista *lst);
int buscaAnterior(Lista *lst);

// ***********************************************
// ******  initLista                        ******
// ***********************************************
void initLista(Lista *lst){
    limpaLista(lst);
    lst->ini = -1;
    lst->tm = 0;
}
// ***********************************************
// ******  limpaLista                       ******
// ***********************************************
void limpaLista(Lista *lst){
    int i;

    for(i = 0; i < MAX_LISTA; i++){
        lst->V[i].prox = i;
    }
}

// ***********************************************
// ******  tamLista                         ******
// ***********************************************
int tamLista(Lista *lst){
    return lst->tm;
}

// ***********************************************
// ******  imprimeLista                     ******
// ***********************************************
void imprimeLista(Lista *lst){
    int i, pos;

    pos = lst->ini;
    if(pos != -1){
        printf("%%%%%%%%%%%% INICIO LISTA %%%%%%%%%%%%%%\n");
        while(pos != -1){
            printf("[%f] [%d]\n", (float) lst->V[pos].dado, pos);
            pos = lst->V[pos].prox;
        }
        printf("%%%%%%%%%%%% FIM LISTA %%%%%%%%%%%%%%%%%\n");
    }
}

// ***********************************************
// ******  imprimeListaTotal                ******
// ***********************************************

void imprimeListaTotal(Lista *lst){
    int i;

    printf("<<<<<<<< ------ Lista Total ----->>>>>>\n");
    for(i = 0; i < MAX_LISTA; i++){
        printf("Dado[%f] Index[%i] Proximo[%d]\n",(float)lst->V[i].dado, (int) i, (int)lst->V[i].prox);
    }
}

// ***********************************************
// ******  insereElemento                   ******
// ***********************************************

bool insereElemento(Lista *lst,float var){
    bool ok;
    int pos, ant;

    ant = buscaAnterior(lst);
    pos = proxDisponivel(lst);

    if(pos != -1){
        if(lst->ini == -1)
            lst->ini = pos;

        lst->V[ant].prox = pos;
        lst->V[pos].dado = var;
        lst->V[pos].prox = -1;
        lst->tm++;
        ok = 1;
    }
    return ok;
}

// ***********************************************
// ******  buscaElemento                    ******
// ***********************************************
int buscaElemento(Lista *lst, float var){
    int i;
    for(i = 0; i < MAX_LISTA; i++){
        if(lst->V[i].dado == var)
            return i;
    }
    return -1;
}

// ***********************************************
// ******  removeElemento                   ******
// ***********************************************
bool removeElemento(Lista *lst, float var){
    bool ok = 0;
    int pos, ant;

    pos = buscaElemento(lst, var);

    if(pos != -1){
        ant = buscaAnteriorRemover(lst, pos);

        if(ant != -1)
            lst->V[ant].prox = lst->V[pos].prox;
        else
            lst->ini = lst->V[pos].prox;

        lst->V[pos].prox = pos;
        lst->tm--;
        ok = 1;
    }
    return ok;
}

int proxDisponivel(Lista *lst){
    int i;
    for(i = 0; i < MAX_LISTA; i++){
        if(lst->V[i].prox == i)
            return i;
    }
    return -1;
}

int buscaAnterior(Lista *lst){
    int i;
    for(i = 0; i < MAX_LISTA; i++){
        if(lst->V[i].prox == -1)
            return i;
    }
    return -1;
}

int buscaAnteriorRemover(Lista *lst, int pos){
    int i;
    for(i = 0; i < MAX_LISTA; i++){
        if(lst->V[i].prox == pos)
            return i;
    }
    return -1;
}
