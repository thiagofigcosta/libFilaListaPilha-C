#include <stdlib.h>

typedef struct Cell{
    int item;
    struct Cell *prox;
} Pilha;

int currentPilha;
Pilha *Topo;


bool initPilha(){
    Topo=NULL;
    currentPilha=0;
}

bool isEmptyPilha(){
    if(Topo==NULL)
        return true;
    return false;
}

bool deletePilha(){
    Pilha *Temp;
    if(isEmptyPilha())
        return false;

    while(Topo!=NULL){
        Temp=Topo;
        Topo=Topo->prox;
          Temp->prox=NULL;
        free(Temp);
    }
    currentPilha=0;
    return true;
}

//poe
bool pushPilha(int valor){
    Pilha *Temp = (Pilha*)malloc(sizeof(Pilha));
    if(Temp==NULL)
        return false;
    Temp->item = valor;
    Temp->prox = Topo;
    Topo=Temp;
    currentPilha++;
    return true;
}

//remove
bool popPilha(int &valor){
    Pilha *Temp;
    if(isEmptyPilha())
        return false;
    valor=Topo->item;
    Temp=Topo;
    Topo=Topo->prox;
      Temp->prox=NULL;
    free(Temp);
    currentPilha--;
    return true;
}

bool getPilha(int &value){
    if(isEmptyPilha())
        return false;
    value=Topo->item;
    return true;
}
