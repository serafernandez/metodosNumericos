#include <math.h>
#include <iostream>

using namespace std;

float f(float x){
    return exp(-x) - x;
}

float g(float x1, float x2){
    return x1 - ((f(x1) * (x2-x1)) / (f(x2) - f(x1)));
}


int main(){
    float valor1, valor2, e;

    cout << "Ingrese el primer valor: ";
    cin >> valor1;
    cout << "Ingrese el segundo valor: ";
    cin >> valor2;
    cout << "Ingrese el error admisible: ";
    cin >> e;

    float valorNuevo, error;
    int iteracion = 0;
    do{

        valorNuevo = g(valor1, valor2);
        error = fabs(valor1 - valorNuevo);
        valor1 = valor2;
        valor2 = valorNuevo;
        iteracion++;
        cout << endl << "Iteracion: " << iteracion << " - Error: " << error;
    }while(error > e);
    cout << endl << "La raiz es: " << valor1 << endl;

}
