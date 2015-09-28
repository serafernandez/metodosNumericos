#include <iostream>
#include <math.h>

using namespace std;

double h = 0.01;

double f(double x){
    return 3 * x + sin(x) - exp(x);
}
double fprima(double x){
    return (f(x + h) - f(x - h)) / (2 * h);
}

double g(double x){
    return x - ( f(x) / fprima(x) );
}

int main(){

    double valorInicial, e;

    cout << "Ingrese valor inicial ";
    cin >> valorInicial;
    cout << "Ingrese error esperado ";
    cin >> e;

    double valorViejo, error;
    int iteracion = 0;
    do{
        iteracion++;
        valorViejo = valorInicial;
        valorInicial = g(valorInicial);
        error = fabs(valorInicial - valorViejo);
        cout << "\nIteracion " << iteracion << ", Error: " << error;
    }while(error > e);

    cout << endl << "La raiz es " << valorInicial << " con un error de " << error << endl;


    return 0;
}
