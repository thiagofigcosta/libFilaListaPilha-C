#include <iostream>
int tam=65535;
int *pilha;
int pos=0;
bool alloqued=false;

void push(int value){
	if(pos==tam) return;
	pilha[pos++]=value;
}

int pop(){
	if(!pos) return 0;
	return pilha[--pos];
}

bool isEmpty(){
	return !pos;
}

bool isFull(){
	return (pos==tam);
}

int getSize(){
	return pos;
}

void clear(){
	pos=0;
	if(!alloqued){
		alloqued=false;
		free(pilha);
	}
}

void setSize(int n){
	alloqued=true;
	tam=n;
	pilha=(int*)malloc(sizeof(int)*n);
}

void printTop(){
	if(isEmpty()) return;
	std::cout<<pilha[pos-1]<<std::endl;
}
