/*programita ejemplo para leer/escribir datos en un archivo*/

#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <math.h>
#include <iostream>
using namespace std;


int main(void)
{
     #include"lectura_escritura_datos.c"

	int n = filas;
	int it =0;
	double xn[n];  //x nuevo calculado
	double xv[n];  //x viejo q uso en el nuevo calculo
	double suma;
	int condicion; //funciona como boolean para saber si es o no dominante la matriz
	double e;  //epsilon (tolerancia)
	double sumaEa;	//auxiliares q uso para poder calcular el error
	double sumaEb; //idem del de arriba
	double errorRelativo;
	double b[filas];
	double w; //coeficiente de relajacion
	
	// ********************* Terminos independientes ********************
	#include"lectura_escritura_datos_ideptes.c"
	

	//*******************************************************************
	//			verifico la matriz sea diagonalmente dominante
	
	condicion = 0; 
	for(int i=0;i<n;i++){
		suma=0;
		for(int j=0;j<n;j++){
			if(j!=i)
				suma=suma+m[i][j];
		}

		if( fabs(m[i][i]) < fabs(suma) ){
			printf("\n\n La matriz no es diagonalmente dominante en la %dº ecuacion",i+1);
			condicion=1;
		}
	}
				
	if(condicion == 0)
		cout << "La matriz es diagonalmente dominante" << endl;

	if(condicion != 0){
		cout << "La matriz no diagonalmente dominante" << endl;
		cout << "No se recomienda este metodo para la resolucion del SEL" << endl;	
	}
	//**************** FIN DE LA VERIFICACION ****************************
	
	cout << endl << "Tolerancia (epsilon): " << endl;
	cin >> e;
	cout << endl << "Coeficiente de Relajacion: "<< endl;
	cin >> w;
	
	if(w==1){
		cout << "Es el Metodo Gauss-Seidel normal" << endl;
	}else if (0 < w || w < 1){
		cout << "Metodo Gauss-Seidel con subrelajacion" << endl;
	}else if (1 < w || w < 2){
		cout << "Metodo Gauss-Seidel con sobrelajacion" << endl;
	}


	//********************* INICIALIZO LAS VARIABLES *********************
	for (int i=0; i<n; i++){
		xn[i]=0;
		xv[i]=0;
	}
	
	//*********************** GAUSS-SEIDEL *******************************
	do{
		for(int i=0;i<n;i++){
			suma=0;
			for(j=0;j<i;j++)
				suma=suma+m[i][j]*xn[j];				
			for(j=i+1;j<n;j++)
				suma=suma+m[i][j]*xv[j];
			xn[i]= xv[i]*(1-w) + w*((b[i]-suma)/m[i][i]);	
		}
		sumaEa=0;
		sumaEb=0;
		
		//************** Calculo del error *****************
		for(int i=0;i<n;i++){
			sumaEa=sumaEa+pow((xn[i]-xv[i]),2);
			sumaEb=sumaEb+pow(xn[i],2);		
		}
		errorRelativo=sqrt(sumaEa/sumaEb);
		it++;
		
		//redefino mis vectores
		for (int i=0;i<n;i++){
			xv[i]=xn[i];
		}

	}while(errorRelativo>e);

	cout << endl << "Cantidad de Ecuaciones: " << n << endl;
	cout << "Cantidad de iteraciones: " << it << endl;
	cout << "Error Relativo final: " << errorRelativo << endl;

	cout << "----Solucion----" << endl;
	for(int i=0;i<n;i++)
		cout << "x[" << i << "]=" << xn[i] << endl; 					
		
}
