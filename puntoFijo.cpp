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
    int iteracion = 0;
    do{
        iteracion++;
        valorViejo = valor;
        valor = g(valor);
        error = fabs(((valor - valorViejo) / valor) * 100);
        cout << "\nIteracion " << iteracion << ", Error: " << error;
    }while(error > e);
    cout << endl << "La raiz es " << valor << " con un eshror de " << error << endl;

    return 0;
}
