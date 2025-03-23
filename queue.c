#include "queue.h"
#include <stdio.h>

void CreateQueue(Queue *Q) {
    Q->First = NULL;
    Q->Last = NULL;
    Q->wasEmpty = true;
}

boolean IsQueueEmpty(Queue Q) {
    return (Q.First == NULL && Q.Last == NULL);
}

void Enqueue(Queue *Q, infotype X) {
    address P;
    Create_Node(&P);
    if (P != NULL) {
        Isi_Node(&P, X);
        
        if (IsQueueEmpty(*Q)) {
            Q->First = P;
        } else {
            Q->Last->next = P;
        }
        Q->Last = P;
        Q->wasEmpty = false;
    }
}

void Dequeue(Queue *Q, infotype *X) {
    if (!IsQueueEmpty(*Q)) {
        address P = Q->First;
        *X = P->info;
        
        Q->First = P->next;
        if (Q->First == NULL) {
            Q->Last = NULL;
            Q->wasEmpty = true;
        }
        
        DeAlokasi(&P);
    }
}

void PrintQueue(Queue Q) {
    printf("Current Queue: ");
    if (IsQueueEmpty(Q)) {
        printf("Empty");
    } else {
        address P = Q.First;
        while (P != NULL) {
            printf("%d ", P->info);
            P = P->next;
        }
    }
    printf("\n");
}

int QueueLength(Queue Q) {
    return NbElmt(Q.First);
}

boolean ShouldResetNumbering(Queue Q) {
    return Q.wasEmpty && IsQueueEmpty(Q);
}
