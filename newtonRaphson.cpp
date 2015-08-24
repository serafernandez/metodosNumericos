#include <iostream>
#include <math.h>

using namespace std;

float f(float x){
    return exp(-x) - x;
}
float fprima(float x){
    return - exp(-x) - 1;
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
    do{
        valorViejo = valorInicial;
        valorInicial = g(valorInicial);
        error = (((valorInicial - valorViejo) / valorInicial ) * 100);
    }while(error > e);

    cout << "La raiz es " << valorInicial << "con un error de " << error << endl;


    return 0;
}
