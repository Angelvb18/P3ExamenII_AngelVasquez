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
bool evaluarOperacion(string);
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
		}else{
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
bool evaluarOperacion(string cad){
	if(cad[0] != '+' && cad[0] != '-'){
		return true;
	}else{
		return false;
	}
}
