#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::vector;
#include "pila.h"
#include "Nodo.h"
#include "Object.h"
#include "Matriz.h"
#include "Operador.h"
#include <math.h>
#include <stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
///pila ,nodo,objet,martiz:object,operador:object
Matriz* suma(Matriz* p1,Matriz* p2);
Matriz* resta(Matriz* p1,Matriz* p2);
bool evaluarOperacion(string,pila*);
bool evaluarCadena(string,vector<char>&);
int main() {
	pila* lista = new pila();
	string lectura;
	vector<char>valores;
	do{
		cout << ">>";
		cin >> lectura;
		if(evaluarCadena(lectura , valores) ){
			 lista->push(new Nodo(new Matriz(lectura[0],sqrt(valores.size()),valores)));
			 dynamic_cast<Matriz*>(lista->top()->getDatas())->print();
			 valores.clear();
		}else{
			Nodo* matrizIzq = lista->top();
			Nodo* matrizDer= lista->top();
			bool valid = true;
			int posicionLectura = 0 ;
			while(posicionLectura < lectura.size()){
				
				int  valid2 = 1; 
				if(lectura[posicionLectura] == '+'){
					
					do{
						
						if( matrizIzq->getData() != lectura[posicionLectura-1]){
											
							if(matrizIzq->getNext() != NULL){
								
								matrizIzq = matrizIzq->getNext();
							}else{
								posicionLectura = lectura.size();
								valid2 = 2;
							}
						}else{
							
							valid2 = 3;
						}
					}while(valid2 == 1 ||valid2 == 2);
					if(valid2 == 3){
						do{
							if( matrizDer->getData() != lectura[posicionLectura+1]){						
								if(matrizDer->getNext() != NULL){
									matrizDer = matrizDer->getNext();
								}else{
									valid2 = 2;
									posicionLectura = lectura.size();
								}	
							}else{
								valid2 = 3;
							}
						}while(valid2 == 1 ||valid2 == 2);
						
					}else{
						valid = false;
					}
					if(valid2 == 3){
					    suma(dynamic_cast<Matriz*>(matrizIzq->getDatas()),dynamic_cast<Matriz*>(matrizDer->getDatas()))->print();	
					    posicionLectura ++;
					}
				}
				if(lectura[posicionLectura] == '-'){
					do{
						if( matrizIzq->getData() != lectura[posicionLectura-1]){						
							if(matrizIzq->getNext() != NULL){
								matrizIzq = matrizIzq->getNext();
							}else{
								valid2 = 2;
								posicionLectura = lectura.size();
							}
						}else{
							valid2 = 3;
						}
					}while(valid2 == 1 ||valid2 == 2);
					if(valid2 == 3){
						do{
							if( matrizDer->getData() != lectura[posicionLectura+1]){						
								if(matrizDer->getNext() != NULL){
									matrizDer = matrizDer->getNext();
								}else{
									valid2 = 2;
									posicionLectura = lectura.size();
								}	
							}else{
								valid2 = 3;
							}
						}while(valid2 == 1 ||valid2 == 2);
						
					}else{
						valid = false;
					}
					if(valid2 == 3){
					    resta(dynamic_cast<Matriz*>(matrizIzq->getDatas()),dynamic_cast<Matriz*>(matrizDer->getDatas()))->print();	
					    posicionLectura ++;
					}
				}
				
				if(posicionLectura == lectura.size()-1){
					valid = false;
				}
				 posicionLectura ++;
			}
			
		}
		
		
	}while(lectura != "exit");
	return 0;
}
bool evaluarCadena(string cad,vector<char>& valores){
	if(cad.size()>3){
	    if(cad[1] == '=' && cad[2] == '[' && cad[cad.size()-1] == ']'){
		    for(int i = 3 ; i < cad.size() ; i++){
		    	if(cad[i]-48 >= 0 && cad[i+1] == ','|| cad[i]-48 >= 0 && cad[i+1] == ']'|| cad[i]-48 <= 9 && cad[i+1] == ',' ||cad[i]-48 <= 9 && cad[i+1] == ']'|| cad[i] == ',' && cad[i]-48 >= 0 || cad[i] == ',' && cad[i+1]-48 <= 9 || cad[i] ==']' &&  cad[i]-48 >= 0 || cad[i] ==']' &&  cad[i]-48 <= 9 ){
		    		if(cad[i] !=','&& cad[i] !=']'){
		    			valores.push_back(cad[i]);
					}
					
				}else
					return false;
			}
	    }else
	    	return false;
	}else
		return false;
    return true;
}
bool evaluarOperacion(string cad,pila* stack){
	if(cad[0] != '+' && cad[0] != '-' && cad[cad.size()-1] != '-' && cad[cad.size()-1] != '+'){
			return true;
	}else{
		return false;
	}
}
Matriz* suma(Matriz* p1,Matriz* p2)
{
	int**matriz = new int*[p1->getSize()];
	
	for(int i = 0 ; i < p1->getSize() ; i++){
		matriz[i] = new int[p1->getSize()];
	}
;
	for(int i = 0 ; i < p1->getSize() ; i++){
		for (int j = 0 ; j < p1->getSize() ; j++){
			matriz[i][j] = p1->getMatriz()[i][j] + p2->getMatriz()[i][j];
		}
	}
  return new Matriz('R',p1->getSize() , matriz);
}
Matriz* resta(Matriz* p1,Matriz* p2)
{
	int**matriz = new int*[p1->getSize()];
	for(int i = 0 ; i < p1->getSize() ; i++){
		matriz[i] = new int[p1->getSize()];
	}
	for(int i = 0 ; i < p1->getSize() ; i++){
		for (int j = 0 ; j < p1->getSize() ; j++){
			matriz[i][j] = p1->getMatriz()[i][j] - p2->getMatriz()[i][j];
		}
	}
  return new Matriz('R',p1->getSize() , matriz);
}
