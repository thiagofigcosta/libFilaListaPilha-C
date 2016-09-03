#include <stdlib.h>

typedef struct cell{
    int item;
    struct cell *prox;
} Lista;

int currentLista;
Lista *Inicio;


bool initLista(){
    Inicio=NULL;
    currentLista=0;
}

bool isEmptyLista(){
    if(Inicio==NULL)
        return true;
    return false;
}

bool deleteLista(){
    int Aux;
    Lista *Temp;
    if(isEmptyLista())
        return false;

    while(Inicio!=NULL){
        Temp=Inicio;
          Temp->prox=NULL;
        Inicio=Inicio->prox;
        free(Temp);
    }
    currentLista=0;
    return true;
}

//fazer com aluno

//poe
bool pushLista(int pos,int valor){
    Lista *Temp = (Lista*)malloc(sizeof(Lista));
    if(Temp==NULL)
        return false;
    Temp->item = valor;
    Temp->prox = NULL;
    Fim->prox=Temp;
    Fim=Temp;
    currentLista++;
    return true;
}

//remove
bool popLista(int pos, int &valor){
    Lista *Temp;
    if(isEmptyLista())
        return false;
    valor=Inicio->item;
    Temp=Inicio;
    Inicio=Inicio->prox;
      Temp->prox=NULL;
    free(Temp);
    currentLista--;
    return true;
}

bool getLista(int pos,int &value){
    if(isEmptyLista())
        return false;
    value=Inicio->item;
    return true;
}
