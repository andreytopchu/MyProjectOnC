#include<stdio.h>
#include <stdlib.h>
#include "Interfaces/DoublyLinkedList.h"
#include "Interfaces/Stack.h"
#include "Interfaces/Queue.h"
#include "Interfaces/Coins.h"

void ShowActionsWithDoubleLinkedList(){
    printf("Show actions with doubly linked list: \n");
    DoublyLinkedList * doublyLinkedList = CreateNewList();
    printf("Doubly linked list is empty before added first element: ");
    printf(ListIsEmpty(doublyLinkedList) ? "true\n" : "false\n");
    InsertFirstElement(doublyLinkedList, 6);
    printf("Doubly linked list is empty after added first element: ");
    printf(ListIsEmpty(doublyLinkedList) ? "true\n" : "false\n");
    InsertLastElement(doublyLinkedList, 4);
    Node* head = doublyLinkedList->Head;
    InsertBeforeElement(doublyLinkedList, head, 5);
    InsertAfterElement(doublyLinkedList, head, 7);
    PrintList(doublyLinkedList);
    Show(doublyLinkedList->Head);
    RemoveHeadElement(doublyLinkedList);
    Show(doublyLinkedList->Head);
    PrintList(doublyLinkedList);
    RemoveNode(doublyLinkedList->Head->Next);
    RemoveTailElement(doublyLinkedList);
    PrintList(doublyLinkedList);
}

void ShowActionsWithStack() {
    printf("\n\nShow actions with stack: \n");

    Stack * stack = CreateStack();
    Push(stack, 10);
    Push(stack, 9);
    Push(stack, 8);
    Push(stack, 7);
    Push(stack, 6);
    printf("Stack is empty after added five elements: ");
    printf(StackIsEmpty(stack) ? "true\n" : "false\n");
    PrintStack(stack);
    Pop(stack);
    PrintStack(stack);
    Pop(stack);
    PrintStack(stack);
    Pop(stack);
    PrintStack(stack);
    Pop(stack);
    PrintStack(stack);
    Pop(stack);
    free(stack);
}

void ShowActionsWithQueue(){
    printf("\n\nShow actions with queue: \n");

    Queue * queue = CreateQueue();
    printf("New queue is empty: ");
    printf(QueueIsEmpty(queue) ? "true\n" : "false\n");

    QueuePush(queue, 1);
    PrintQueue(queue);
    QueuePush(queue, 2);
    PrintQueue(queue);
    QueuePush(queue, 3);
    PrintQueue(queue);
    QueuePush(queue, 4);
    PrintQueue(queue);
    QueuePush(queue, 5);
    PrintQueue(queue);

    printf("Queue is empty: ");
    printf(QueueIsEmpty(queue) ? "true\n" : "false\n");

    QueuePop(queue);
    PrintQueue(queue);
    QueuePop(queue);
    PrintQueue(queue);
    QueuePop(queue);
    PrintQueue(queue);
    QueuePop(queue);
    PrintQueue(queue);
}

int main() {
    ShowActionsWithDoubleLinkedList();
    ShowActionsWithStack();
    ShowActionsWithQueue();
    ChangeCoins(68);
}

