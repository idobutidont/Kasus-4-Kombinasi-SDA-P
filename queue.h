#ifndef QUEUE_H
#define QUEUE_H

#include "linked.h"

typedef struct {
    address First;
    address Last;
    boolean wasEmpty;
} Queue;

void CreateQueue(Queue *Q);
// Create an empty queue

boolean IsQueueEmpty(Queue Q);
// Check if the queue is empty

void Enqueue(Queue *Q, infotype X);
// Add a new element to the back of the queue

void Dequeue(Queue *Q, infotype *X);
// Remove the front element from the queue and return its value

void PrintQueue(Queue Q);
// Print all elements in the queue

int QueueLength(Queue Q);
// Return the number of elements in the queue

boolean ShouldResetNumbering(Queue Q);
// Check if numbering should be reset (queue was empty)

#endif
