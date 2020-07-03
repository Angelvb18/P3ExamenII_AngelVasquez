#include "Matriz.h"
using std::cout;
using std::endl;

Matriz::Matriz(char value,int size,vector<char> valores):Object(value){
	this->size = size;
	matriz = new int*[size];
	for (int i = 0 ; i < size ; i++){
		matriz[i] = new int[size];
	}
	int posicionValue = 0 ;
	for(int i = 0 ; i < size ; i++){
		for(int j = 0 ; j < size ; j++){
			matriz[i][j] = valores[posicionValue]-48;
			posicionValue++;
		}
	}
	
}
Matriz::Matriz(char value,int size ,int**matriz2):Object(value){
	this->size = size;
	for(int i = 0 ; i < size ; i++){
		for(int j = 0 ; j < size ; j++){
			matriz[i][j] = matriz2[i][j];
		}
	}
}
void Matriz:: print(){
	cout << value << "=" << endl;
	
	for(int i = 0 ; i < size ; i++){
		cout << "    | ";
		for(int j = 0 ; j < size ; j++){
			cout <<matriz[i][j]<<" ";
		}
		cout << "|"<<endl;
	}
}
 char Matriz::getValue(){
 	   print();
 	  return value;
 }
