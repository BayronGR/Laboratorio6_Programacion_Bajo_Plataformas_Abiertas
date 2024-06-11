#ifndef STACK_H
#define STACK_H

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct Stack {
    Node* top;
} Stack;