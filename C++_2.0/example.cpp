#include <iostream>
#include "nanoTAD.h"

using namespace std;

void fila();
void pilha();
void lista();
void listaduplamenteencadeada();

int main(){
    fila();
    pilha();
    lista();
    listaduplamenteencadeada();
    return 0;
}
void fila(){
    cout<<"---------------QUEUE---------------"<<endl;
    nQueue *queue=nStack::newQueue();
    nCell *cell=nCell::newCell(7);
    queue->push(cell);
    queue->push(nCell::newCell(70));
    queue->push(nCell::newCell(700));
    queue->push(nCell::newCell(7000));
    queue->push(nCell::newCell(70000));
    queue->print();
    queue->reversePrint();
    nCELL *poped=queue->pop();
    cout<<"Value in init of queue: "<<poped->value<<"-size: "<<queue->getSize()<<endl;
    cout<<"Value in init of queue: "<<queue->pop()->value<<"-size: "<<queue->getSize()<<endl;
    cout<<"Value in init of queue: "<<queue->pop()->value<<"-size: "<<queue->getSize()<<endl;
    cout<<"Value in init of queue: "<<queue->pop()->value<<"-size: "<<queue->getSize()<<endl;
    cout<<"Value in init of queue: "<<queue->pop()->value<<"-size: "<<queue->getSize()<<endl;
    for(int i=0; i<10; i++)
        queue->push(nCell::newCell(i));
    cout<<"Queue size: "<<queue->getSize()<<endl;
    queue->clear();
    cout<<"Queue size: "<<queue->getSize()<<endl;
    free(poped);
    cout<<"-----------------------------------"<<endl;
}
void pilha(){
    cout<<"--------------STACK----------------"<<endl;
    nStack *stack=nStack::newStack();
    nCell *cell=nCell::newCell(7);
    stack->push(cell);
    stack->push(nCell::newCell(70));
    stack->push(nCell::newCell(700));
    stack->push(nCell::newCell(7000));
    stack->push(nCell::newCell(70000));
    stack->print();
    stack->reversePrint();
    nCELL *poped=stack->pop();
    cout<<"Value in top  of stack: "<<poped->value<<"-size: "<<stack->getSize()<<endl;
    cout<<"Value in top  of stack: "<<stack->pop()->value<<"-size: "<<stack->getSize()<<endl;
    cout<<"Value in top  of stack: "<<stack->pop()->value<<"-size: "<<stack->getSize()<<endl;
    cout<<"Value in top  of stack: "<<stack->pop()->value<<"-size: "<<stack->getSize()<<endl;
    cout<<"Value in top  of stack: "<<stack->pop()->value<<"-size: "<<stack->getSize()<<endl;
    for(int i=0; i<10; i++)
        stack->push(nCell::newCell(i));
    cout<<"Stack size: "<<stack->getSize()<<endl;
    stack->clear();
    cout<<"Stack size: "<<stack->getSize()<<endl;
    free(poped);
    cout<<"-----------------------------------"<<endl;
}
void lista(){
    cout<<"--------------LIST-----------------"<<endl;
    nList *list=nStack::newList();
    nCell *cell=nCell::newCell(7);
    list->push(cell,list->getSize());
    list->push(nCell::newCell(70),list->getSize());
    list->push(nCell::newCell(700),list->getSize());
    list->push(nCell::newCell(7000),list->getSize());
    list->push(nCell::newCell(70000),list->getSize());
    list->print();
    list->reversePrint();
    nCELL *poped=list->get(0);
    cout<<"Value in init of list(has queue): "<<poped->value<<endl;
    cout<<"Value in init of list(has queue): "<<list->get(1)->value<<endl;
    cout<<"Value in init of list(has queue): "<<list->get(2)->value<<endl;
    cout<<"Value in init of list(has queue): "<<list->get(3)->value<<endl;
    cout<<"Value in init of list(has queue): "<<list->get(4)->value<<endl;
    poped=list->pop(list->getSize()-1);
    cout<<"Value in top  of list(has stack): "<<poped->value<<"-size: "<<list->getSize()<<endl;
    cout<<"Value in top  of list(has stack): "<<list->pop(list->getSize()-1)->value<<"-size: "<<list->getSize()<<endl;
    cout<<"Value in top  of list(has stack): "<<list->pop(list->getSize()-1)->value<<"-size: "<<list->getSize()<<endl;
    cout<<"Value in top  of list(has stack): "<<list->pop(list->getSize()-1)->value<<"-size: "<<list->getSize()<<endl;
    cout<<"Value in top  of list(has stack): "<<list->pop(list->getSize()-1)->value<<"-size: "<<list->getSize()<<endl;
    for(int i=0; i<10; i++)
        list->push(nCell::newCell(i),0);
    cout<<"List size: "<<list->getSize()<<endl;
    list->clear();
    cout<<"List size: "<<list->getSize()<<endl;
    free(poped);
    cout<<"-----------------------------------"<<endl;
}

void listaduplamenteencadeada(){
	cout<<"-----------DOUBLE-LIST-------------"<<endl;
    nDoubleList *dlist=nStack::newDoubleList();
    nCell *cell=nCell::newCell(7);
    dlist->push(cell,dlist->getSize());
    dlist->push(nCell::newCell(70),dlist->getSize());
    dlist->push(nCell::newCell(700),dlist->getSize());
    dlist->push(nCell::newCell(7000),dlist->getSize());
    dlist->push(nCell::newCell(70000),dlist->getSize());
    dlist->print();
    dlist->reversePrint();
    nCELL *poped=dlist->get(0);
    cout<<"Value in init of dlist(has queue): "<<poped->value<<endl;
    cout<<"Value in init of dlist(has queue): "<<dlist->get(1)->value<<endl;
    cout<<"Value in init of dlist(has queue): "<<dlist->get(2)->value<<endl;
    cout<<"Value in init of dlist(has queue): "<<dlist->get(3)->value<<endl;
    cout<<"Value in init of dlist(has queue): "<<dlist->get(4)->value<<endl;
    poped=dlist->pop(dlist->getSize()-1);
    cout<<"Value in top  of dlist(has stack): "<<poped->value<<"-size: "<<dlist->getSize()<<endl;
    cout<<"Value in top  of dlist(has stack): "<<dlist->pop(dlist->getSize()-1)->value<<"-size: "<<dlist->getSize()<<endl;
    cout<<"Value in top  of dlist(has stack): "<<dlist->pop(dlist->getSize()-1)->value<<"-size: "<<dlist->getSize()<<endl;
    cout<<"Value in top  of dlist(has stack): "<<dlist->pop(dlist->getSize()-1)->value<<"-size: "<<dlist->getSize()<<endl;
    cout<<"Value in top  of dlist(has stack): "<<dlist->pop(dlist->getSize()-1)->value<<"-size: "<<dlist->getSize()<<endl;
    for(int i=0; i<10; i++)
        dlist->push(nCell::newCell(i),0);
    cout<<"DList size: "<<dlist->getSize()<<endl;
    dlist->clear();
    cout<<"DList size: "<<dlist->getSize()<<endl;
    free(poped);
    cout<<"-----------------------------------"<<endl;
}