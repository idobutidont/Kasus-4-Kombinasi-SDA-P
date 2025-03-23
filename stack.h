#ifndef STACK_H
#define STACK_H

#include "linked.h"

typedef struct {
    address top;
} Stack;

// Stack operations
void CreateStack(Stack *S);
boolean IsEmpty(Stack S);
void Push(Stack *S, infotype X);
void Pop(Stack *S, infotype *X);
void PrintStack(Stack S);

#endif
