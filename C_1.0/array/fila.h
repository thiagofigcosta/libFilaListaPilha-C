#include <iostream>
int tam=65535;
int *fila;
int frente=0;
int tras=0;
int size=0;
bool alloqued=false;

void push(int value){
	if(size==tam) return;
	fila[tras]=value;
	tras=(tras+1)%tam;
	size++;
}

int pop(){
	if(!size) return 0;
	int r=fila[frente];
	frente=(frente+1)%tam;
	size--;
	return r;
}

bool isEmpty(){
	return !size;
}

int getSize(){
	return size;
}
bool isFull(){
	return size==tam;
}


void clear(){
	frente=0;
	tras=0;
	size=0;
	if(!alloqued){
		alloqued=false;
		free(fila);
	}
}
void setSize(int n){
	alloqued=true;
	tam=n;
	fila=(int*)malloc(sizeof(int)*n);
}
void printFront(){
	if(isEmpty()) return;
	std::cout<<fila[frente]<<std::endl;
}
