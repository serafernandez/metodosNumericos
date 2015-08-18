#include <iostream>
#include <math.h>

using namespace std;

float f(float x){
    return exp(-x) - x;
}

float g(float x){
    return f(x) + x;
}

int main(){

    float e, valor;

    cout << "Ingresar el valor inicial: ";
    cin >> valor;

    cout << "Ingresar error admisible: ";
    cin >> e;

    float valorViejo, error;
    do{
        valorViejo = valor;
        valor = g(valor);
        error = fabs(((valor - valorViejo) / valor) * 100);
    }while(error > e);
    cout << "La raiz es " << valor << " con un eshror de " << error;

    return 0;
}