#include <iostream>
#include <math.h>

using namespace std;
float f(float x){
    return pow(x, 2) - 1;
}

int evaluarF(float a, float b){
    // cout << "f(" << a << ") " << f(a) << " f(" << b << ") " << f(b);
    // cout << "\nValor de evaluarF " << (f(a)*f(b) > 0 ? 0 : 1) << "\n";
    return f(a)*f(b) > 0 ? 0 : 1;
}

int main(){
    float limiteSuperior, limiteInferior, e;

    cout << "Ingrese valor superior ";
    cin >> limiteSuperior;
    cout << "Ingrese valor inferior ";
    cin >> limiteInferior;
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
    }while(error > e);
    cout << "Raiz " << limiteNuevo;
    return 0;
}
