
#include <stdio.h>
#include <stdlib.h>
//Evelyn Feng Wu B82870
// Para representar un nodo de la lista enlazada se utiliza lo siguiente
struct Node {
    int data;
    struct Node* next;
};

// 1. Crear o agregar un nuevo nodo con un valor dado con un int
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode) {
        newNode->data = value;
        newNode->next = NULL;
    }
    return newNode;
}


// 2. Eliminar un nodo por su valor
void deleteNodeByValue(struct Node** head, int value) {
    if (*head == NULL) {
        return;
    }

    if ((*head)->data == value) {
        struct Node* temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    struct Node* current = *head;
    while (current->next != NULL) {
        if (current->next->data == value) {
            struct Node* temp = current->next;
            current->next = temp->next;
            free(temp);
            return;
        }
        current = current->next;
    }
}

// 3. Aregar un nodo al principio de la lista
void prependNode(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (newNode) {
        newNode->next = *head;
        *head = newNode;
    }
}

// 4. Agregar un nodo al final de la lista
void appendNode(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (newNode) {
        if (*head == NULL) {
            *head = newNode;
        } else {
            struct Node* current = *head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }
    }
}




// 5. Buscar un nodo por su valor
void searchNodeByValue(struct Node* head, int value) {
    struct Node* current = head;
    while (current != NULL) {
        if (current->data == value) {
            printf("El valor %d existe en la lista.\n", value);
            return;
        }
        current = current->next;
    }
    printf("El valor %d no existe en la lista.\n", value);
}

// 6. Imprimir la lista
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// 7. Obtener el elemento enésimo
void getNodeByIndex(struct Node* head, int index) {
    int count = 0;
    struct Node* current = head;
    while (current != NULL) {
        if (count == index) {
            printf("El elemento en el índice %d es %d.\n", index, current->data);
            return;
        }
        count++;
        current = current->next;
    }
    printf("No hay un elemento en el índice %d.\n", index);
}


// Función para liberar la memoria de la lista
void freeList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL;

    appendNode(&head, 1);
    appendNode(&head, 2);
    appendNode(&head, 3);
    appendNode(&head, 4);
    appendNode(&head, 5);

    printf("Lista inicial: ");
    printList(head);

    prependNode(&head, 0);
    printf("Lista después de agregar un nodo al inicio: ");
    printList(head);

    appendNode(&head, 6);
    printf("Lista después de agregar un nodo al final: ");
    printList(head);

    deleteNodeByValue(&head, 3);
    printf("Lista después de eliminar el nodo con valor 3: ");
    printList(head);

    searchNodeByValue(head, 5);
    searchNodeByValue(head, 7);

    getNodeByIndex(head, 2);
    getNodeByIndex(head, 10);

    freeList(head);

    return 0;
}
