#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct nos{
        int dado;
        struct nos * prox;
} nos;

typedef struct lista{
               nos * inicio;
               nos * fim;
               int tm;
    } lista;

void initLista(lista *lst){
    lst->inicio = NULL;
    lst->fim = NULL;;
    lst->tm = 0;
}
bool insereFim(lista * lst, int dado){
    nos * novo = NULL;
    novo = malloc(sizeof(nos));

    if(!novo)
        return false;

    if(!lst->inicio){
        lst->inicio = novo;
    }else{
       lst->fim->prox = novo;
    }

    lst->fim = novo;
    lst->tm++;
    novo->dado = dado;
    novo->prox = NULL;

    return true;
}

bool insereInicio(lista *lst, int dado){
    nos * novo = NULL;
    novo =  malloc(sizeof(nos));

    if(!novo)
        return false;

    novo->dado = dado;
    novo->prox = lst->inicio;
    lst->inicio = novo;
    lst->tm++;
    return true;
}

bool insereOrdenado(lista *lst, int dado){
    nos * novo = NULL, *pos = NULL, *ant = NULL;
    novo = malloc(sizeof(nos));

    if(!novo)
        return false;

    pos = lst->inicio;

    if(!lst->inicio)
        lst->inicio = novo;

    while(!pos){
        if( dado < pos->dado){
            novo->prox = pos->prox;
            ant->prox = novo;
            lst->tm++;
            lst->fim = novo;
        }else{
            //lst->fim = novo;
        }

        ant = pos;
        pos = pos->prox;

    }

    return true;
}

void imprimeLista(lista *lst){
   nos * pos = NULL;
   pos = lst->inicio;

   while(pos != NULL){
        printf("Dado %d \n",pos->dado);
        pos = pos->prox;
   }
   printf("TOTAL: %d \n",lst->tm);

}


int main(){

    lista lst;
    initLista(&lst);

    insereInicio(&lst, 10);
    insereOrdenado(&lst, 1);
    imprimeLista(&lst);



    return 0;
}
