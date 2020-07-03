#include "Nodo.h"
Nodo::Nodo(Object* data){
	this->data = data;
}
void Nodo::setNext(Nodo* next){
			next_nodo = next;
}
