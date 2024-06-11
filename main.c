#include <stdio.h>
#include "stack.h"

int main() {
    Stack* stack = createStack();

    push(stack, 12);
    push(stack, 15);
    push(stack, 37);

    printf("Elemento en la cima: %d\n", peek(stack));

    printf("Elemento sacado: %d\n", pop(stack));
    printf("Elemento en la cima: %d\n", peek(stack));

    printf("Elemento sacado: %d\n", pop(stack));
    printf("Elemento sacado: %d\n", pop(stack));
    
    // Intentar hacer pop en una pila vacía
    printf("Elemento sacado: %d\n", pop(stack)); 

    freeStack(stack);

    return 0;
}