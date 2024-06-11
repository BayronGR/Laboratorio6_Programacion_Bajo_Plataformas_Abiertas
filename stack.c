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
// Función para añadir un elemento a la pila
void push(Stack* stack, int data) {
    Node* newNode = createNode(data);
    newNode->next = stack->top;
    if (stack->top != NULL) {
        stack->top->prev = newNode;
    }
    stack->top = newNode;
    printf("%d añadido a la pila.\n", data);
    printStack(stack);
}

// Función para eliminar y devolver el elemento superior de la pila
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Pila vacía, no se puede hacer pop.\n");
        return 0;
    }
    Node* temp = stack->top;
    int popped = temp->data;
    stack->top = stack->top->next;
    if (stack->top != NULL) {
        stack->top->prev = NULL;
    }
    free(temp);
    printf("%d eliminado de la pila.\n", popped);
    printStack(stack);
    return popped;
}

// Función para obtener el elemento superior de la pila sin eliminarlo
int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Pila vacía.\n");
        return -1;
    }
    return stack->top->data;
}

// Función para verificar si la pila está vacía
int isEmpty(Stack* stack) {
    return stack->top == NULL;
}

// Función para imprimir la pila
void printStack(Stack* stack) {
    Node* current = stack->top;
    printf("Estado actual de la pila: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Función para liberar la memoria de la pila
void freeStack(Stack* stack) {
    while (!isEmpty(stack)) {
        pop(stack);
    }
    free(stack);
}
