#include <iostream>
#include <cstdlib>
#include <math.h>
/*
@author Daniel Sagastume -12041018
@Return - retorna la opcion elegida del menu
*/
int menu();

void ejercicio_1(int, int, int[], int[]);

void imprimir(int[], int);

void ejercicio_2();

void ejercicio_3();

using namespace std;

int main(int argc, char** argv) {
	int op=0;
	while(op!=4) {

		switch(op=menu()) {

			case 1: {
				int size=100;
				int max_n=0, n=0;
				int salida[size];
				int res[size];
				cout<<"Ingrese el valor maximo: ";
				cin>>max_n;
				while(max_n<1||max_n>99) {
					cout<<"El numero debe estar entre 1 a 99"<<endl
					    <<"Ingrese el valor maximo: ";
					cin>>max_n;
				}
				for(int i=0; i<100; i++) {
					salida[i]=0;
				}
				for(int i=0; i<100; i++) {
					res[i]=0;
				}
				ejercicio_1(max_n, 0, res, salida);
				break;
			}//Fin del case 1

			case 2: {
				ejercicio_2();
				break;
			}//Fin del case 2

			case 3: {
				ejercicio_3();
				break;
			}//Fin del case 3

			case 4: {
				cout<<"Fin del laboratorio"<<endl;
				break;
			}//Fin del case 4
		}//Fin del switch

	}//Fin del while del menu

	return 0;
}

void ejercicio_1(int max_n,int n,int res[],int salida[]) {
	if(n==max_n) { //Caso base
		for(int i=0; i<n; i++) {
			salida[i]=res[i-1]+res[i];
		}
		for(int j=0; j<n; j++) {//impresion
			if(salida[j]!=0) {
				cout<<salida[j]<<" ";
			}
		}	
		cout<<"\n";
	} else {	
		for(int i=0; i<n; i++) {
			if(i!=0 || i!=(n-1)) {
				salida[i]=res[i-1]+res[i];
			} else if(i==0) {
				salida[i]=1;
			}
		}
		for(int j=0; j<n; j++) {
			if(salida[j]!=0) {		
				cout<<salida[j]<<" ";//Imprime el digito
				res[j]=salida[j];
			}
		}
		cout<<"\n";
		ejercicio_1(max_n, n+1, res, salida);
	}
}


void imprimir(int arreglo[], int size) {
	for(int i=0; i<size; i++) {
		cout<<arreglo[i]<<", ";
	}
}

int menu() {
	int op=0;
	while(true) {//si no presione el 4 va a seguir el menu
		cout<<"===================="<<endl
		    <<"	MENU"<<endl
		    <<"1. Ejercicio 1"<<endl
		    <<"2. Ejercicio 2"<<endl
		    <<"3. Ejercicio 3"<<endl;
		cout<<"Ingrese la opcion: ";
		cin>>op;
		if(op>0&&op<5)
			return op;
	}
}//Fin de la funcion del menu



void ejercicio_2() {
	int size=20,max_random=100;
	int arreglo[size];

	for(int i=0; i<size; i++) { //llenar arreglo de randoms
		int random=(rand()%max_random)+1;
		arreglo[i]=random;
	}
	cout<<"El arreglo es: ";
	for(int u=0; u<size; u++) {//imprimir el arreglo
		if(u!=size-1) {//If para que en el ultimo valor sin la ultima coma
			cout<<arreglo[u]<<",";
		} else {
			cout<<arreglo[u]<<endl;
		}
	}
	int promedio=0, suma=0, result_sumatoria=0;
	for(int j=0; j<size; j++) { //Sacar el promedio
		suma+=arreglo[j];
	}
	promedio=suma/size;
	for(int k=0; k<size; k++) { //Sumatoria
		result_sumatoria+= pow((arreglo[k] - promedio),2);
	}
	double temp=result_sumatoria/20.00;
	double result= sqrt(temp);
	cout<<"La desviación estándar poblacional es: "<<result<<endl;
}

void ejercicio_3() {

	int size=10;
	int max=20;
	int arreglo[size];
	int arreglo1[size];
	int bandera=0;//para que llene el primer arreglo o el segundo

	for(int j=0; j<2; j++) { //para llenar los dos arreglos
		for(int i=0; i<size; i++) {
			int random=(rand()%max)+1;
			if(bandera==0) {
				arreglo[i]=random;
			} else {
				arreglo1[i]=random;
			}
		}
		bandera=1;
	}

	bandera=0;

	for(int a=0; a<2; a++) {//Impresion de los dos arreglos
		if(bandera==0) {//Imprimir el primer arreglo
			cout<<"Arreglo 1: ";
			for(int i=0; i<size; i++) {
				if(i!=size-1) {//If para que en el ultimo valor sin la ultima coma
					cout<<arreglo[i]<<",";
				} else {
					cout<<arreglo[i]<<endl;
				}
			}
		} else { //Imprimir el segundo arreglo
			cout<<"Arreglo 2: ";
			for(int i=0; i<size; i++) {
				if(i!=size-1) {
					cout<<arreglo1[i]<<",";
				} else {
					cout<<arreglo1[i]<<endl;
				}
			}
		}
		bandera=1;
	}

	for(int j=0; j<size; j++) { //Va a recorrer los 10 valores de los arreglos
		cout<<j+1<<":"<<endl;

		for(int y=0; y<arreglo[j]; y++) {
			char temp=177;
			cout<<temp<<" ";
		}
		cout<<"\n";
		for(int y=0; y<arreglo1[j]; y++) {
			char temp=178;
			cout<<temp<<" ";
		}
		cout<<"\n";
	}

}//Din de opcion 3