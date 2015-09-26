#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#define N 100000
using namespace std;

int main(void){

	#include"lectura_escritura_datos.c"

	int n=filas;
	double La[n];
	double px;	/*COORDENADA X DE UN PAR [x,y]*/
	double py;	/*COORDENADA Y DE UN PAR [x,y]*/
	double L;	
	
	//Solicitud del punto
	cout << "Par ordenado [x,y]" << endl;
	cout << endl << "Punto a aproximar(x): ";
	cin >> px;
	
	//LAGRANGE!!! 
	py=0;
	for(i=0;i<n;i++){
		L=1;
		for(j=0;j<n;j++){
			if(i!=j){
				L=L*(x[j]-px)/(x[j]-x[i]);		
			}
		}
		py=py+(L*y[i]);			
	}
	
	//Solucion
	cout << endl <<"Aproximacion para " << px << ": " << py << endl;
	

}
