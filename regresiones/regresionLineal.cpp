#include <math.h>
#include <stdio.h>

double f(double x, double a, double b);
double regresionLineal( double *x, double *y, int n);

int main(){

    int n;
    printf("Ingrese la cantidad de puntos:");
    scanf("%d", &n);

    double x[n], y[n];

    for(int i=0; i < n; i++){
        printf("Vector numero %d \n", i+1);
        printf("X = ");
        scanf("%lf", &x[i]);
        printf("Y = ");
        scanf("%lf", &y[i]);
    }

    for(int i=0; i < n; i++){
        printf("Vector numero %d \n", i+1);
        printf("X = ");
        printf("%f\n", x[i]);
        printf("Y = ");
        printf("%f\n", y[i]);
    }

    regresionLineal(x, y, n);

    return 0;
}

double regresionLineal( double *x, double *y, int n){
    double sumx = 0, sumy = 0, sumxy = 0, sumx2 = 0, st = 0, sr = 0;

    for(int i = 0; i < n; i++){
        sumx += x[i];
        sumy += y[i];
        sumxy += x[i] * y[i];
        sumx2 += pow(x[i], 2);
    }

    double xmedia = sumx / n;
    double ymedia = sumy / n;

    // Ecuaciones normales
    double pendienteA1 = ( n * sumxy - sumx * sumy ) / ( n * sumx2 - pow(sumx, 2));
    double interseccionA0 = ymedia - pendienteA1 * xmedia;
    double errorCuadraticoMedio;

    for(int i = 0; i < n; i++){
        st += pow(y[i] - ymedia, 2); // Varianza
        sr += pow(y[i] - pendienteA1 * x[i] - interseccionA0, 2); // Sumatoria de los errores al cuadrado
        errorCuadraticoMedio += pow( f( x[i], pendienteA1, interseccionA0 ) - y[i], 2) / n;
    }
    errorCuadraticoMedio = sqrt(errorCuadraticoMedio);

    double syx = sqrt(( sr / ( n - 2 ) )); // Error estandar del estimado
    double r2 = ( st - sr ) / st; // Coeficiente de correlacion

    printf("El valor del R2 es %f ---- el valor de R es %f ---- el valor del Syx es %f\n", r2, sqrt(r2), syx);

    printf("El ajuste por minimos cuadrados es: \n    y = %f + %fx\n", interseccionA0, pendienteA1);
    printf("El error cuadratico medio es: %f\n", errorCuadraticoMedio);

}

double f(double x, double a, double b){
    return a * x + b;
}
