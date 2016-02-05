#include <iostream>
#include <ctime>
#include <iomanip>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;
using std::setw;

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
		srand(time(NULL));
		const int row=4;
		const int col=3;
		int matriz[row][col], sizeJug1=3, sizeJug2=3;
		int jugador1[sizeJug1], jugador2[sizeJug2];
		int atkJug1, defJug1, velJug1, atkJug2, defJug2, velJug2, ans=1;
		while(ans==1){
			for (int i = 0; i < row; ++i){
				for (int j = 0; j < col; ++j){
					int randAtk=rand()%30+85;
					int randDef=rand()%25+50;
					int randVel=rand()%50+150;
					if (j==0){
						matriz[i][0]=randAtk;
					}else if (j==1){
						matriz[i][1]=randDef;
					}else{
						matriz[i][2]=randVel;
					}
				}
			}
			for (int i = 0; i < row; ++i){
				for (int j = 0; j < col; ++j){
					cout<<setw(8)<<matriz[i][j];
				}
				cout<<endl;
			}
			cout<<endl;
			for (int i = 0; i < sizeJug1; ++i){
				int randJug1=rand()%4;
				if (i==0){
					atkJug1=matriz[randJug1][0];
				}else if (i==1){
					defJug1=matriz[randJug1][1];
				}else{
					velJug1=matriz[randJug1][2];
				}
			}
			for (int i = 0; i < sizeJug2; ++i){
				int randJug2=rand()%4;
				if (i==0){
					atkJug2=matriz[randJug2][0];
				}else if (i==1){
					defJug2=matriz[randJug2][1];
				}else{
					velJug2=matriz[randJug2][2];
				}
			}
			int resultadoJug1=atkJug1-defJug2;
			int resultadoJug2=atkJug2-defJug1;
			if (resultadoJug1>resultadoJug2){
				cout<<"Jugador 1 gano por "<<resultadoJug1-resultadoJug2<<" puntos, no gano por velocidad. "<<endl;
			}else if (resultadoJug2>resultadoJug1){
				cout<<"Jugador 2 gano por "<<resultadoJug2-resultadoJug1<<" puntos, no gano por velocidad. "<<endl;
			}else if (resultadoJug1=resultadoJug2){
				if (velJug1>velJug2){
					cout<<"Jugador 1 gano por "<<velJug1-velJug2<<" puntos, gano por velocidad. "<<endl;	
				}else if (velJug2>velJug1){
					cout<<"Jugador 2 gano por "<<velJug2-velJug1<<" puntos, gano por velocidad. "<<endl;	
				}else{
					cout<<"EMPATE TOTAL"<<endl;
				}
			}
			cout<<"Quiere seguir jugando? [1/2]: ";
			cin>>ans;
		}
		int opcion=menu();
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
void printMatriz(int array[], int size){
	for (int i = 0; i < size; ++i){
		cout<<setw(8)<<array[i]<<endl;
	}
}