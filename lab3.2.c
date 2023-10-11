#include <stdio.h>
// B82870 EFW
//Arreglos y punteros

// 1- Función para encontrar el valor mínimo en el arreglo 
int encontrarMin(int arr[], int longi) {
    int minimo = arr[0];
    for (int i = 1; i < longi; i++) {
        if (arr[i] < minimo) {
            minimo = arr[i];
        }
    }
    return minimo;
}

// 2- Función para encontrar el valor máximo en el arreglo
int encontrarMax(int arr[], int longi) {
    int maximo = arr[0];
    for (int i = 1; i < longi; i++) {
        if (arr[i] > maximo) {
            maximo = arr[i];
        }
    }
    return maximo;
}

// 3- Función para encontrar el valor mínimo y máximo con punteros
void encontrarMinMax(int arr[], int longi, int *minimo, int *maximo) {
    *minimo = arr[0];
    *maximo = arr[0];
    for (int i = 1; i < longi; i++) {
        if (arr[i] < *minimo) {
            *minimo = arr[i];
        }
        if (arr[i] > *maximo) {
            *maximo = arr[i];
        }
    }
}

// Esta función solo almacena las variables

int main() {
    int arrDesord[] = {21, 24, 65, 3, 56, 12, 35, 15};
    int longi = sizeof(arrDesord) / sizeof(arrDesord [0]);

    int minimo = encontrarMin(arrDesord, longi);
    int maximo = encontrarMax(arrDesord, longi);

// Para la verificacion se imprimen los datos para verificar la efectividad de la funcion

    printf("El valor mínimo encontrado es: %d\n", minimo);
    printf("El valor máximo encontrado es: %d\n", maximo);

    int minPuntero, maxPuntero;
    encontrarMinMax(arrDesord, longi, &minPuntero, &maxPuntero);

    printf("Valor mínimo encontrado con punteros: %d\n", minPuntero);
    printf("Valor máximo encontrado con punteros: %d\n", maxPuntero);

    return 0;
}
