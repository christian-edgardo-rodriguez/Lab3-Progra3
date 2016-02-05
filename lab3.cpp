#include <iostream>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;

int menu();
void mayorMenor(int , int);
void printArray(int [], int);

int main(int argc, char const *argv[]){
	int size=10, opcion=menu(), currentTry, numIntentos, resp=1;
	int array[size]={1000,1000,1000,1000,1000,1000,1000,1000,1000,1000};
	if (opcion==1){
		while(resp==1){
			srand(time(NULL));
			int numRand=rand()%1001-500;
			do{
				cout<<numRand<<endl;
				cout<<"Ingrese el numero: ";
				cin>> currentTry;
				numIntentos++;
				if (currentTry==numRand){
					cout<<"Este es el numero!"<<endl;
					cout<<endl;
				}
				mayorMenor(currentTry,numRand);
			} while (currentTry!=numRand);
			int bandera=1, reemplazo;
			for (int i = 0; (i < size)&&bandera==1; ++i){
				if (numIntentos<array[i]||numIntentos==array[i]){
						reemplazo=array[i];
						array[i]=numIntentos;
						array[i+1]=reemplazo;
						bandera=0;
				} 	
			}
			printArray(array, size);
			numIntentos=0;
			cout<<"Quiere seguir jugando? [1/2]: ";
			cin>>resp;
			cout<<endl;
		}
		cout<<"Gracias por jugar!"<<endl;
		cout<<"Se borraran los numeros de la tabla"<<endl;
		cout<<endl;
		opcion=menu();
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
