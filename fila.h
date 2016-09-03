#include <stdlib.h>

typedef struct cell{
    int item;
    struct cell *prox;
} Fila;


int currentFila;
Fila *Inicio;
Fila *Fim;


bool initFila(){
    Inicio=NULL;
    Fim=NULL;
    currentFila=0;
}

bool isEmptyFila(){
    if(Inicio==NULL)
        return true;
    return false;
}

bool deleteFila(){
    Fila *Temp;
    if(isEmptyFila())
        return false;

    while(Inicio!=NULL){
        Temp=Inicio;
          Temp->prox=NULL;
        Inicio=Inicio->prox;
        free(Temp);
    }
    currentFila=0;
    return true;
}

//poe
bool pushFila(int valor){
    Fila *Temp = (Fila*)malloc(sizeof(Fila));
    if(Temp==NULL)
        return false;
    Temp->item = valor; //(*) .
    Temp->prox = NULL;
    if(isEmptyFila()){
		Inicio=Temp;
	}else{
		Fim->prox=Temp;
	}
    Fim=Temp;
    currentFila++;
    return true;
}

//remove
bool popFila(int &valor){
    Fila *Temp;
    if(isEmptyFila())
        return false;
    valor=Inicio->item;
    Temp=Inicio;
    Inicio=Inicio->prox;
      Temp->prox=NULL;
    free(Temp);
    currentFila--;
    if(isEmptyFila())
    	Fim=NULL;
    return true;
}

bool getFila(int &value){
    if(isEmptyFila())
        return false;
    value=Inicio->item;
    return true;
}
