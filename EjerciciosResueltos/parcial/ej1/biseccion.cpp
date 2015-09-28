#include <iostream>
#include <math.h>

using namespace std;
float f(float x){
    return -3 + 4.23333 * x - 1.35 * pow(x, 2) + 0.116667 * pow(x, 3);
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

    float limiteNuevo, error, limiteAnterior = limiteSuperior;
    int iteracion = 0;

    error = e + 1.0;
    do{
        limiteNuevo = (limiteSuperior + limiteInferior) / 2;
        iteracion++;

        if(evaluarF(limiteSuperior, limiteNuevo)){
            limiteInferior = limiteNuevo;
        }else if(evaluarF(limiteInferior, limiteNuevo)){
            limiteSuperior = limiteNuevo;
        }else{
            break;
        }

        error = fabs(limiteNuevo - limiteAnterior);
        limiteAnterior = limiteNuevo;
        cout << "\nIteracion " << iteracion << ", Error: " << error;
    }while(error > e);
    cout << "\nRaiz " << limiteNuevo << endl;
    return 0;
}
