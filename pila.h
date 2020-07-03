#ifndef PILA_H
#define PILA_H
#include "Nodo.h"
#include "Object.h"
class pila{
    private:
        Nodo* head;
    public:
        pila(){
            head = nullptr;
        };
        Stpilaack(Nodo* _head){
            head = _head;
        };
        Nodo* pop(){
            Nodo* temp_head = head;
            head = head->getNext();
            return temp_head;
        };
        Nodo* top(){
            return head;
        };
        void push(Nodo* _node){
            _node->setNext(head);
            head = _node;
        };
        void delete_stack(Nodo* _node){
            if (_node->getNext() != nullptr){
                delete_stack(_node->getNext());
            }            
            delete _node;
        }
        ~pila(){
            delete_stack(head);
        }
};

#endif
