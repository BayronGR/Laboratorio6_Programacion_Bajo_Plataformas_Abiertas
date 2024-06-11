#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

// Función para crear un nuevo nodo
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Error al asignar memoria.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Función para inicializar la pila
Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    if (!stack) {
        printf("Error al asignar memoria.\n");
        exit(1);
    }
    stack->top = NULL;
    return stack;
}
