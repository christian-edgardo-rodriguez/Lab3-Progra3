#include <iostream>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;

int menu();
void mayorMenor(int , int);
void printArray(int [], int);

int main(int argc, char const *argv[]){
	int size=10, array[size], opcion=menu(), vecesJuego=0, currentTry, numIntentos;
	if (opcion==1){
		while(vecesJuego<2){
			srand(time(NULL));
			int numRand=rand()%1001-500;
			for(int i=0;i<1001;i++){
				cout<<"Intento #"<<i+1<<": ";
				cin>> currentTry;
				numIntentos++;
				if(currentTry==numRand){
					cout<<"Este es el numero!!!"<<endl;					
					array[vecesJuego]=numIntentos;
					vecesJuego++;
					numIntentos=0;
					cout<<endl;
					break;					
				}else
					mayorMenor(currentTry,numRand); 
			}
		}
		cout<<"-----------------------------"<<endl;
		printArray(array, size);
	}else if (opcion==2){
		
	}else
		cout<<"Opcion Invalida"<<endl;
	return 0;
}
int menu(){
	int opc;
	cout<<"1. Juego de loteria"<<endl;
	cout<<"2. Juego de batalla"<<endl;
	cout<<"Escoja su opcion: ";
	cin>>opc;
	if (opc<1&&opc>2){
		return 0;
	}else{
		return opc;
	}
}
void mayorMenor(int currentTry,int numRand){
	if (currentTry<numRand){
		cout<<"Ingrese un numero mayor"<<endl;
	}else if (currentTry>numRand){
		cout<<"Ingrese un numero menor"<<endl;
	}
}
void printArray(int array[], int size){
	for (int i = 0; i < size; ++i){
		cout<<array[i]<<endl;
	}
}