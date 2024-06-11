#include <stdio.h>
#include "stack.h"

int main() {
    Stack* stack = createStack();

    push(stack, 12);
    push(stack, 15);
    push(stack, 37);