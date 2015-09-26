#include <iostream>
#include <math.h>

using namespace std;

float f(float x){
    return 500 * exp(x*-0.0248) - 5;
}
float fprima(float x){
    return -12.4 * exp(x*-0.0248);
}

float g(float x){
    return x - ( f(x) / fprima(x) );
}

int main(){

    float valorInicial, e;

    cout << "Ingrese valor inicial ";
    cin >> valorInicial;
    cout << "Ingrese error esperado ";
    cin >> e;

    float valorViejo, error;
    int iteracion = 0;
    do{
        iteracion++;
        valorViejo = valorInicial;
        valorInicial = g(valorInicial);
        error = (((valorInicial - valorViejo) / valorInicial ) * 100);
        cout << "\nIteracion " << iteracion << ", Error: " << error;
    }while(error > e);

    cout << endl << "La raiz es " << valorInicial << " con un error de " << error << endl;


    return 0;
}
