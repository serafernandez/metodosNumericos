# Raices

# Metodos Cerrados
Se los llama cerrados porque necesitan dos valores iniciales para calcular la raiz. Estos valores deben encerrar a la raiz. Se los llama metodos convergentes.

## Biseccion

Si f(xi) y f(xf) tienen signos opuestos, quiere decir que en el medio hay al menos una raiz entre xi y xf.
El metodo de biseccion es un tipo de busqueda incremental en el que el intervalo se divide siempre a la mitad. Si la funcion cambia de signo sobre un intervalo, se evalua el valor de la funcion en el punto medio. La posicion de la raiz se determina situandola en el punto medio del subintervalo, dentro del cual ocurre un cambio de signo. El proceso se repite hasta obtener una mejor aproximacion.

### Uso

Es adecuado si se quiere realizar la evaluacion de una sola raiz de una funcion que es facil de evaluar.

### Contras

Es ineficiente.

## Falsa Posicion

La falsa posicion es una alternativa basada en una visualizacion grafica. Uno de los valores ingresados permanece fijo mientras el otro se le acerca.

### Contras

Hay que tener cuidado en que casos se usa. No hay que usarlo cuando crece demasiado rapido.

# Metodos abiertos
Los metodos abiertos se basan en formulas que requieren unicamente de un solo valor de inicio x o que empiecen con un par de ellos, pero no necesariamente encierran la raiz. Algunas veces divergen o se alejan de la raiz verdadera a medida que se avanza en el calculo, pero cuando convergen, en general, lo hacen mucho mas rapido que los metodos cerrados. El problema es que cuando la inclinacion de la tangente es mayor a 45 grados.

## Punto fijo

Utiliza dos funciones. Pero solo se ingresa f(x). Si g(x) esta cerca del punto fijo tiene una pendiente mayor a 45 grados diverge. Cuando la raiz es cero, se encuentra rapidamente.

## Newton - Raphson

Necesita un valor inicial. A este lo valua en la funcion y le calcula la tangente, ese va a cortar en algun momento el eje x. Ahi va a dar una aproximacion. El valor en el que toca al eje x vuelve a evaluar la tangente. No tengo que tocar g(x).
CIUDADO: es muy sensible al punto de origen, por lo que hay que tener un valor cercano al valor de la raiz.
Es el mas rapido de todos los metodos.

## Secante

Muy parecido al metodo de falsa posicion. Tiene dos puntos de inicio, pero no tienen, necesariamente, que encerrar la raiz. Calcula la secante utilizando estos dos puntos, donde toca al punto x se calcula otra secante.
Es uno de los metodos mas seguros.
Puede tener problemas de redondeo.

# Sistema de resolucion de ecuaciones

# Metodos directos

Los metodos directos hacen n^3 cantidad de operaciones. Siendo n la cantidad de variables. Se utilizan cuando son pocas las carpetas.

## Eliminacion gaussiana

Hace la triangulacion superior. Y despues hace sustitucion regresiva.

### Desventaja

Puede producir division por cero. Se soluciono con pivoteo.


### Contras
Son aquellos donde un pequeno cambio en el coeficiente generan grandes cambios en la humanidad.
Sistema singular. Cuando el determinante es 0.

# Metodos indirectos

Son mas rapidos pero menos robustos. Solo vemos metodos iterativos. Estos proponen una solucion que no soluciona el problema pero luego lo van resolviendo. Cuanto mas dominante sea la diagonal de la matriz llega mas rapido al resultado.

## Jacobi

Postula 3 y los resuelve, y en la proxima pasada los utiliza luego.

## Gauss - Seidel - Con relajacion

Llega mas rapido a la solucion.
La relajacion lo que hace es mejorar la convergencia. Si no tengo que usar relajacion, pongo 1. Si el valor es entre 0 y uno es subrelajacion, converge mas lento, sirve para asegurarme que converge. Entre 1 y 2 es sobrerelajacion. Para cada matriz hay un valor optimo para la relajacion. En el codigo relajacion es w.

# Interpolacion

Se usa para estimar valores intermedios para datos definidos por puntos.

## Lagrange

Devuelve una funcion que une los puntos de orden: cantidad de puntos - 1. Solo se usa con pocos puntos, sino produce ruido numerico.
No importa que los numeros esten ordenados. No es bueno para extrapolar. Este metodo sirve para conocer el valor en el punto en el que lo quiero saber.
