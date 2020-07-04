#ifndef MATRIZ_H
#define MATRIZ_H
#include <iostream>
#include <vector>
using std::vector;
#include <string>
using std::string;
#include "Object.h"

class Matriz : public Object
{
	public:
		Matriz(char,int,vector<char>);
		Matriz(char,int,int**);
		void print();
		char getValue();
		int getSize(){return size;}
		int**getMatriz(){return matriz;}
	protected:
		int**matriz;
		int size;
		
};

#endif
