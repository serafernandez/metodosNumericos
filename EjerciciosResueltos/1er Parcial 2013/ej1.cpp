#include <iostream>
#include <math.h>

using namespace std;
float f(float x){
    return 3 * x + sin(x) - expf(x);
}

int evaluarF(float a, float b){
    // cout << "f(" << a << ") " << f(a) << " f(" << b << ") " << f(b);
    // cout << "\nValor de evaluarF " << (f(a)*f(b) > 0 ? 0 : 1) << "\n";
    return f(a)*f(b) > 0 ? 0 : 1;
}

int main(){
    float limiteSuperior, limiteInferior, e;

    cout << "Ingrese valor inferior ";
    cin >> limiteInferior;
    cout << "Ingrese valor superior ";
    cin >> limiteSuperior;
    cout << "Ingrese el error tolerado ";
    cin >> e;

    if(!evaluarF(limiteSuperior, limiteInferior)){
        cout << "No hay raices";
        return 0;
    }

    float limiteNuevo, error;
    int iteracion = 0;

    error = e + 1.0;
    do{
        limiteNuevo = limiteSuperior - f(limiteSuperior) * (limiteInferior - limiteSuperior) / (f(limiteInferior) - f(limiteSuperior));
        iteracion++;

        if(evaluarF(limiteSuperior, limiteNuevo)){
            limiteInferior = limiteNuevo;
        }else if(evaluarF(limiteInferior, limiteNuevo)){
            limiteSuperior = limiteNuevo;
        }else{
            break;
        }

        error = fabs(f(limiteNuevo));
        cout << "\nIteracion " << iteracion << ", Error: " << error;
    }while(error > e);
    cout << "\nRaiz " << limiteNuevo << "\n";
    return 0;
}
