// La rais esta en 1 y -1
// Le tomo 20 iteraciones con un intervalo entre 0 y 5.
// El resultado fue que la raiz es 0.999999 con un error de 9.5367e-06
#include <iostream>
#include <math.h>

using namespace std;
float f(float x){
    return pow(x, 10) - 1;
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
        limiteNuevo = (limiteSuperior + limiteInferior) / 2;
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
    cout << "\nRaiz " << limiteNuevo;
    return 0;
}
