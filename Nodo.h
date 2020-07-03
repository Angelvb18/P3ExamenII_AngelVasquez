#ifndef NODO_H
#define NODO_H
#include "Object.h"
class Nodo
{
	public:
		Nodo(Object* data);
		Nodo* getNext(){return next_nodo;}
		void setNext(Nodo* next);
		void setData(Object*);
		Object* getDatas(){return data;}
		char getData(){ return data->getValue();}
		
	protected:
		Nodo* next_nodo;
		Object* data;
};

#endif
