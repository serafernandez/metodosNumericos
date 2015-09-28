#include <iostream>
#include <math.h>

using namespace std;

double f(double x){
    return 3 * x + sin(x) - exp(x);
}

double g(double x){
    return f(x) + x;
}

double gprima(double x){
    return 3 - exp(x) + cos(x);
}

int main(){

    double e, valor;

    cout << "Ingresar el valor inicial: ";
    cin >> valor;

    cout << "Ingresar error admisible: ";
    cin >> e;

    if(fabs(gprima(valor)) >= 1){
        cout << endl << "El metodo no converge" << endl;
        return 0;
    }

    double valorViejo, error;
    int iteracion = 0;
    do{
        iteracion++;
        valorViejo = valor;
        valor = g(valor);
        error = fabs(valor - valorViejo);
        cout << "\nIteracion " << iteracion << ", Error: " << error << " --- |valor - valorViejo| = |" << valor << " - " << valorViejo << "|";
    }while(error > e);
    cout << endl << "La raiz es " << valor << " con un eshror de " << error << endl;

    return 0;
}
