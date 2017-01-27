/* 
*------------------------------
*TO CHANGE CELL VARS YOU NEED TO CHANGE THE FUNCTIONS BELLOW:
*newCell
*print
*printReverse
*and ncell contets
*------------------------------
*by: nanoTech Corp
*/


#ifndef NCELL_H
#define NCELL_H
typedef struct ncell{
    /*
    *DEFINE YOUR VARS HERE
    */
    int value;

    static struct ncell* newCell(int value){//CONSTRUCTOR HERE
        struct ncell* cell=new struct ncell;
        /*
        *DEFINE VALUES HERE
        */
        cell->value=value;
        return cell;
    }
private:
    friend struct ntad;
    struct ncell *nxt=nullptr;
    struct ncell *prv=nullptr;
}nCELL;
typedef nCELL nCell;
#endif

#ifndef NTAD_H
#define NTAD_H

#include <iostream>

typedef struct ntad{
public:
    //defines
    static const short STACK=666; 
    static const short LIST=1592; 
    static const short DLIST=3184; 
    static const short QUEUE=1965; 
    static const short UKNW='?';
    
    //vars
private:
    int type=UKNW;
    int size=0;
    nCELL *begin=nullptr;
    nCELL *end=nullptr;
public:
    //constructors
    static struct ntad* newList(){
        struct ntad *list=new struct ntad;
        list->type=LIST;
        return list;
    }
    static struct ntad* newStack(){
        struct ntad *stack=new struct ntad;
        stack->type=STACK;
        return stack;
    }
    static struct ntad* newQueue(){
        struct ntad *queue=new struct ntad;
        queue->type=QUEUE;
        return queue;
    }
    static struct ntad* newDoubleList(){
        struct ntad *queue=new struct ntad;
        queue->type=DLIST;
        return queue;
    }

    //operations
    bool isEmpty(){
        return !size;
    }

    int getSize(){
        return size;
    }
    
    void push(nCELL *value){
        switch(type){
            case STACK:
                value->nxt=end;
                end=value;
                size++;
            return;

            case QUEUE:
                if(!size)
                    begin=value;
                else
                    end->nxt=value;
                end=value;
                size++;
            return;

            default:
                char* str;
                switch(type){
                    case STACK: str=(char*)"stack";break;
                    case QUEUE: str=(char*)"queue";break;
                    case LIST:  str=(char*)"list";break;
                    default:    str=(char*)"unkown";break;
                }
                std::cout<<"Invalid operation for "<<str<<std::endl;
                return;
        }
    }

    nCELL *pop(){
        if(!size) return nullptr;
        nCELL *aux;
        switch(type){
            case STACK:
                aux=end;
                end=end->nxt;
                size --;
                aux->prv=nullptr; 
                aux->nxt=nullptr; 
            return aux;

            case QUEUE:
                aux=begin;
                begin=begin->nxt;
                size--;
                aux->prv=nullptr; 
                aux->nxt=nullptr; 
            return aux;

            default:
                char* str;
                switch(type){
                    case STACK: str=(char*)"stack";break;
                    case QUEUE: str=(char*)"queue";break;
                    case LIST:  str=(char*)"list";break;
                    default:    str=(char*)"unkown";break;
                }
                std::cout<<"Invalid operation for "<<str<<std::endl;
                return nullptr;
        }
    }

    nCELL *get(){
        if(!size) return nullptr;
        switch(type){
            case STACK:
            return end;

            case QUEUE:
            return begin;

            default:
                char* str;
                switch(type){
                    case STACK: str=(char*)"stack";break;
                    case QUEUE: str=(char*)"queue";break;
                    case LIST:  str=(char*)"list";break;
                    default:    str=(char*)"unkown";break;
                }
                std::cout<<"Invalid operation for "<<str<<std::endl;
                return nullptr;
        }
    }

    void push(nCELL *value, int pos){
        if(pos>size||pos<0) return;
        nCELL *aux;
        switch(type){
            case LIST:
                if(!pos){
                    value->nxt=begin;
                    begin=value;
                    size++;
                    return;
                }
                aux=begin;
                while(pos>0){
                    if(pos--==1){
                        value->nxt=aux->nxt;
                        aux->nxt=value;
                        size++;
                        return;
                    }
                    aux=aux->nxt;
                }                
            return;

            case DLIST:
                if(!pos){
                    value->nxt=begin;
                    value->prv=nullptr;
                    if(begin==nullptr)
                        end=value;
                    else
                        begin->prv=value;
                    begin=value;
                    size++;
                    return;
                }
                if(pos==size){
                    value->prv=end;
                    value->nxt=nullptr;
                    if(end==nullptr)
                        begin=value;
                    else
                        end->nxt=value;
                    end=value;
                    size++;
                    return;
                }
                if(pos<=size/2){
                    aux=begin;
                    while(pos>0){
                        if(pos--==1){
                            value->nxt=aux->nxt;
                            value->prv=aux;
                            aux->nxt->prv=value;
                            aux->nxt=value;
                            size++;
                            return;
                        }
                        aux=aux->nxt;
                    }      
                }else{
                    aux=end;
                    while(pos>0){
                        if(pos--==1){
                            value->nxt=aux;
                            value->prv=aux->prv;
                            aux->prv->nxt=value;
                            aux->prv=value;
                            size++;
                            return;
                        }
                        aux=aux->prv;
                    } 
                }          
            return;

            default:
                char* str;
                switch(type){
                    case STACK: str=(char*)"stack";break;
                    case QUEUE: str=(char*)"queue";break;
                    case LIST:  str=(char*)"list";break;
                    default:    str=(char*)"unkown";break;
                }
                std::cout<<"Invalid operation for "<<str<<std::endl;
                return;
        }
    }

    nCELL *pop(int pos){
        if(!size) return nullptr;
        if(pos>=size||pos<0) return nullptr;
        nCELL *aux,*aux2;
        switch(type){
            case LIST:
                aux=begin;
                if(!pos){
                    begin=begin->nxt;
                    size--;
                    aux->prv=nullptr; 
                    aux->nxt=nullptr; 
                    return aux;
                }
                while(pos>0){
                    if(pos--==1){
                        aux2=aux->nxt;
                        aux->nxt=aux->nxt->nxt;
                        size--;
                        break;
                    }
                    aux=aux->nxt;
                }
                aux2->prv=nullptr; 
                aux2->nxt=nullptr;                
            return aux2;

            case DLIST:
                if(!pos){
                    aux=begin;
                    begin->prv=nullptr;
                    begin=begin->nxt;
                    size--;
                    aux->prv=nullptr; 
                    aux->nxt=nullptr;  
                    return aux;
                }
                if(pos==size-1){
                    aux=end;
                    end->nxt=nullptr;
                    end=end->prv;
                    size--;
                    aux->prv=nullptr; 
                    aux->nxt=nullptr;  
                    return aux;
                }
                if(pos<=size/2){
                    aux=begin;
                    while(pos>0){
                        if(pos--==1){
                            aux2=aux->nxt;
                            aux->nxt=aux->nxt->nxt;
                            aux->nxt->prv=aux;
                            size--;
                            break;
                        }
                        aux=aux->nxt;
                    }
                }else{
                    aux=end;
                    while(pos<size-1){
                        if(pos++==1){
                            aux2=aux->prv;
                            aux->prv=aux->prv->prv;
                            aux->prv->nxt=aux;
                            size--;
                            break;
                        }
                        aux=aux->prv;
                    }
                } 
            aux2->prv=nullptr; 
            aux2->nxt=nullptr;               
            return aux2;

            default:
                char* str;
                switch(type){
                    case STACK: str=(char*)"stack";break;
                    case QUEUE: str=(char*)"queue";break;
                    case LIST:  str=(char*)"list";break;
                    default:    str=(char*)"unkown";break;
                }
                std::cout<<"Invalid operation for "<<str<<std::endl;
                return nullptr;
        }
    }

    nCELL *get(int pos){
        if(!size) return nullptr;
        if(pos>=size||pos<0) return nullptr;
        nCELL *aux;
        switch(type){
            case LIST:
                aux=begin;
                while(pos>0){
                    if(pos--==1){
                        aux=aux->nxt;
                        break;
                    }
                    aux=aux->nxt;
                }                
            return aux;

            case DLIST:
                if(pos<=size/2){
                    aux=begin;
                    while(pos>0){
                        if(pos--==1){
                            aux=aux->nxt;
                            break;
                        }
                        aux=aux->nxt;
                    }
                }else{
                    aux=end;
                    while(pos<size-1){
                        if(pos++==1){
                            aux=aux->prv;
                            break;
                        }
                        aux=aux->prv;
                    }
                }             
            return aux;

            default:
                char* str;
                switch(type){
                    case STACK: str=(char*)"stack";break;
                    case QUEUE: str=(char*)"queue";break;
                    case LIST:  str=(char*)"list";break;
                    default:    str=(char*)"unkown";break;
                }
                std::cout<<"Invalid operation for "<<str<<std::endl;
                return nullptr;
        }
    }

    void print(){
        if(!size) return;
        nCELL *aux;
        if(type==STACK){
            aux=end;
            struct ntad *stack=newStack();
            for(int i=0;i<size;i++){
                stack->push(nCell::newCell(aux->value));
                aux=aux->nxt;
            }
            stack->type=QUEUE;
            stack->begin=stack->end;
            stack->print();
            stack->type=STACK;
            stack->clear(); 
        }else{
            aux=begin;
            for(int i=0;i<size;){
                std::cout<<aux->value;
                if(++i<size)
                    std::cout<<"-";
                else
                    std::cout<<std::endl;
                aux=aux->nxt;
            }
        }
    }

    void reversePrint(){
        if(!size) return;
        nCELL *aux;
        if(type==STACK||type==DLIST){
            aux=end;
            for(int i=0;i<size;){
                std::cout<<aux->value;
                if(++i<size)
                    std::cout<<"-";
                else
                    std::cout<<std::endl;
                if(type==DLIST)
                    aux=aux->prv;
                else    
                    aux=aux->nxt;
            }
        }else{
            aux=begin;
            struct ntad *stack=newStack();
            for(int i=0;i<size;i++){
                stack->push(nCell::newCell(aux->value));
                aux=aux->nxt;
            }
            stack->reversePrint();
            stack->clear(); 
        }
    }

    void clear(){
        if(isEmpty()) return;
        nCELL *aux;
        switch(type){
            case STACK:
                while(size>0){
                    aux=end;
                    end=end->nxt;
                    aux->nxt=nullptr;
                    aux->prv=nullptr;
                    free(aux);
                    size --;
                }
            return;

            case LIST:
            case DLIST:
            case QUEUE:
                while(size>0){
                    aux=begin;
                    begin=begin->nxt;
                    aux->nxt=nullptr;
                    aux->prv=nullptr;
                    free(aux);
                    size --;
                }
            return;

            default:
                char* str;
                switch(type){
                    case STACK: str=(char*)"stack";break;
                    case QUEUE: str=(char*)"queue";break;
                    case LIST:  str=(char*)"list";break;
                    default:    str=(char*)"unkown";break;
                }
                std::cout<<"Invalid operation for "<<str<<std::endl;
                return;
        }
    }
    
    
}nTAD;

typedef nTAD nStack;
typedef nTAD nQueue;
typedef nTAD nList;
typedef nTAD nDoubleList;

const short nTAD::STACK; 
const short nTAD::LIST; 
const short nTAD::DLIST; 
const short nTAD::QUEUE; 
const short nTAD::UKNW;
#endif
