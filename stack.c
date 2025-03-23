#include "stack.h"
#include <stdio.h>

void CreateStack(Stack *S) {
    S->top = NULL;
}

boolean IsEmpty(Stack S) {
    return isEmpty(S.top);
}

void Push(Stack *S, infotype X) {
    address P;
    Create_Node(&P);
    Isi_Node(&P, X);
    Ins_Awal(&(S->top), P);
}

void Pop(Stack *S, infotype *X) {
    if (!IsEmpty(*S)) {
        Del_Awal(&(S->top), X);
    }
}

void PrintStack(Stack S) {
    Tampil_List(S.top);
}
