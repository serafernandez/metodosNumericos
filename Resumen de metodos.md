# Metodos Cerrados
Se los llama cerrados porque necesitan dos valores iniciales para calcular la raiz. Estos valores deben encerrar a la raiz.

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

Hay que tener cuidado en que casos se usa.
