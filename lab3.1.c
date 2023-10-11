#include <stdio.h>
// B82870 EFW
// Función para búsqueda lineal
int busqL (int arr[], int longi, int val) {
    for (int i = 0; i < longi; i++) {
        if (arr[i] == val) {
            return i;
        }
    }
    return -1; // Si no se encuentra el val
}

// Función para búsqueda binaria 
int busqB (int arr[], int longi, int val) {
    int izquierda = 0;
    int derecha=longi-1;

    while (izquierda <= derecha) {
        int medio = izquierda + (derecha - izquierda) / 2;

        if (arr[medio] == val) {
            return medio;
        }
        if (arr[medio] < val) {
            izquierda = medio + 1;
        } else {
            derecha = medio - 1;
        }
    }

    return -1; // Si no se encuentra el val
}

// Función para búsqueda binaria recursiva
int busqBR(int arr[], int izquierda, int derecha, int val) {
    if (izquierda <= derecha) {
        int medio = izquierda + (derecha - izquierda) / 2;

        if (arr[medio] == val) {
            return medio;
        }
        if (arr[medio] < val) {
            return busqBR(arr, medio + 1, derecha, val);
        } else {
            return busqBR(arr, izquierda, medio - 1, val);
        }
    }

    return -1; // Si no se encuentra el val
}

int main() {
    int arrOrdenado[] = {2, 4, 6, 23, 56, 79};
    int longi = sizeof(arrOrdenado) / sizeof(arrOrdenado[0]);

    int valBuscado;
    printf("Ingrese un valor entero: ");
    scanf("%d", &valBuscado);
//posicion

    int posiL = busqL(arrOrdenado, longi, valBuscado);
    if (posiL != -1) {
        printf("En la búsqueda lineal: El valor %d se encuentra en la posición %d.\n", valBuscado, posiL);
    } else {
        printf("En la búsqueda lineal: El valor %d no se encontró.\n", valBuscado);
    }

    int posiB = busqB(arrOrdenado,longi, valBuscado);
    if (posiB != -1) {
        printf("En la búsqueda binaria: El valor %d se encuentra en la posición %d.\n", valBuscado, posiB);
    } else {
        printf("En la búsqueda binaria> El valor %d no se encontró.\n", valBuscado);
    }

    int posiBR = busqBR(arrOrdenado, 0, longi - 1, valBuscado);
    if (posiBR!= -1) {
        printf("Búsqueda binaria (recursiva): El valor %d se encuentra en la posición %d.\n", valBuscado, posiBR);
    } else {
        printf("Búsqueda binaria (recursiva): El valor %d no se encontró.\n", valBuscado);
    }

    return 0;
}

