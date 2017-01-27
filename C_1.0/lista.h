#include <stdlib.h>

typedef struct cEll{
    int item;
    struct cEll *prox;
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
    Lista *Temp;
    if(isEmptyLista())
        return false;

    while(Inicio!=NULL){
        Temp=Inicio;
        Inicio=Inicio->prox;
        	Temp->prox=NULL;
        free(Temp);
    }
    currentLista=0;
    return true;
}





//poe
bool pushLista(int pos,int valor){
	if(pos>currentLista)
		return false;
    Lista *Temp = (Lista*)malloc(sizeof(Lista));
    Lista *Atual=Inicio;
    if(Temp==NULL)
        return false;
    /*
		do{
			if(...){
			
				break;
			}
		}while(Atual!=NULL);
	*/
        
    for(int i=0;i<=currentLista;i++){
    	if(pos==0){
    		Temp->item=valor;
    		Temp->prox=Inicio;
    		Inicio=Temp;
    		i=currentLista;
		}else if(i==pos-1){
    		Temp->item=valor;
    		Temp->prox=Atual->prox;
    		Atual->prox=Temp;
    		i=currentLista;
		}
		if(pos!=0)
		Atual=Atual->prox;
	}    
    currentLista++;
    return true;
}

//remove
bool popLista(int pos, int &valor){
	if(pos>=currentLista)
		return false;
    Lista *Temp;
    Lista *Atual=Inicio;
    if(isEmptyLista())
        return false;
        
    for(int i=0;i<=currentLista;i++){
    	if(pos==0){
    		Inicio=Inicio->prox;
    		valor=Inicio->item;
    			Atual->prox=NULL;
    		free(Atual);
    		i=currentLista+1;
		}else if(i==pos-1){
    		Temp=Atual->prox;
    		valor=Temp->item;
    		Atual->prox=Temp->prox;
    			Temp->prox=NULL;
    		free(Temp);
    		i=currentLista+1;
		}
		if(pos!=0)
		Atual=Atual->prox;
	}    
    currentLista--;
    return true;
}

bool getLista(int pos,int &value){
	if(pos>=currentLista)
		return false;
    if(isEmptyLista())
        return false;
        
    for(int i=0;i<=currentLista;i++){
    	if(pos==i){
    		valor=Atual->item;
    		i=currentLista+1;
		}
		if(pos!=0)
		Atual=Atual->prox;
	}    
    return true;
}
