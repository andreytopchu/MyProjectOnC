#include <malloc.h>
#include <stdio.h>
#include "../Interfaces/DoublyLinkedList.h"
#include "../Interfaces/Queue.h"

Node *CreateNode(int value, Node *previous) {
    Node *node = (Node *) malloc(sizeof(Node));
    if (node == NULL) {
        return NULL;
    }
    node->Value = value;
    node->Next = NULL;
    node->Previous = previous;
    return node;
}

Queue *CreateQueue() {
    Queue *queue = (Queue *) malloc(sizeof(Queue));
    if (queue == NULL) {
        return NULL;
    }
    queue->Front = NULL;
    queue->Rear = NULL;
    queue->Size = 0;
    return queue;
}

void QueuePush(Queue *queue, int value) {
    Node *node = CreateNode(value, queue->Rear);
    if (queue->Front == NULL) {
        queue->Front = node;
        queue->Size = 1;
    } else {
        queue->Rear->Next = node;
        queue->Size = queue->Size + 1;
    }
    queue->Rear = node;
}

int QueueIsEmpty(Queue *queue) {
    if (queue->Size == 0) {
        return 1;
    } else {
        return 0;
    }
}

int Peek(Queue *queue) {
    if (QueueIsEmpty(queue) == 1) {
        printf("\n Empty Queue");
        return -1;
    } else {
        return queue->Front->Value;
    }
}

int QueueSize(Queue *queue) {
    return queue->Size;
}

int QueuePop(Queue *queue) {
    if (QueueIsEmpty(queue) == 1) {
        return -1;
    } else {
        int data = Peek(queue);
        Node *temp = queue->Front;
        if (queue->Front == queue->Rear) {
            queue->Rear = NULL;
            queue->Front = NULL;
        } else {
            queue->Front = queue->Front->Next;
            queue->Front->Previous = NULL;
        }
        queue->Size--;
        return data;
    }
}

void PrintQueue(Queue *queue) {
    Node *node = queue->Front;
    printf("\nElements of queue: ");
    while (node != NULL) {
        printf(" %d", node->Value);
        node = node->Next;
    }
    printf("\n");
}