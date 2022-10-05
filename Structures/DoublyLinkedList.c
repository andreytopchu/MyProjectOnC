#include <stdio.h>
#include <stdlib.h>
#include "../Interfaces/DoublyLinkedList.h"


DoublyLinkedList *CreateNewList() {
    DoublyLinkedList *doublyLinkedList;
    doublyLinkedList = malloc(sizeof(DoublyLinkedList));
    doublyLinkedList->Head = NULL;
    doublyLinkedList->Tail = NULL;
    return doublyLinkedList;
}

unsigned ListIsEmpty(DoublyLinkedList *doublyLinkedList) {
    return (doublyLinkedList->Head == NULL) && (doublyLinkedList->Tail == NULL);
}

void InsertFirstElement(DoublyLinkedList *doublyLinkedList, int key) {
    Node *node;
    node = malloc(sizeof(Node));
    node->Value = key;
    node->Next = doublyLinkedList->Head;
    node->Previous = NULL;
    if (ListIsEmpty(doublyLinkedList))
        doublyLinkedList->Tail = node;
    else
        doublyLinkedList->Head->Previous = node;
    doublyLinkedList->Head = node;
}

void InsertLastElement(DoublyLinkedList *doublyLinkedList, int key) {
    Node *node;
    node = malloc(sizeof(Node));
    node->Value = key;
    node->Next = NULL;
    if (ListIsEmpty(doublyLinkedList)) {
        node->Previous = NULL;
        doublyLinkedList->Head = node;
        doublyLinkedList->Tail = node;
    } else {
        node->Previous = doublyLinkedList->Tail;
        doublyLinkedList->Tail->Next = node;
        doublyLinkedList->Tail = node;
    }


}

void InsertAfterElement(DoublyLinkedList *doublyLinkedList, Node *node, int key) {
    Node *tempNode;
    tempNode = malloc(sizeof(Node));
    tempNode->Value = key;
    tempNode->Previous = node->Previous;
    if (tempNode->Previous != NULL)
        node->Previous->Next = tempNode;
    node->Previous = tempNode;
    tempNode->Next = node;

    if (tempNode->Previous == NULL)
        doublyLinkedList->Head = tempNode;
}

void InsertBeforeElement(DoublyLinkedList *doublyLinkedList, Node *node, int key) {
    Node *tempNode;
    tempNode = malloc(sizeof(Node));
    tempNode->Value = key;
    tempNode->Next = node->Next;
    if (tempNode->Next != NULL)
        node->Next->Previous = tempNode;

    node->Next = tempNode;
    tempNode->Previous = node;
    if (tempNode->Next == NULL)
        doublyLinkedList->Tail = tempNode;
}

void Show(Node *node) {
    printf("%d, ", node->Value);
}

void RemoveNode(Node *node) {
    if (node->Next != NULL)
        node->Next->Previous = node->Previous;
    if (node->Previous != NULL)
        node->Previous->Next = node->Next;
    free(node);
}

void RemoveHeadElement(DoublyLinkedList *doublyLinkedList) {
    Node *node;
    node = doublyLinkedList->Head;
    doublyLinkedList->Head = node->Next;
    free(node);
    if (doublyLinkedList->Head == NULL)
        doublyLinkedList->Tail = NULL;
    else
        doublyLinkedList->Head->Previous = NULL;
}

void RemoveTailElement(DoublyLinkedList *doublyLinkedList) {
    Node *node;
    if (doublyLinkedList->Head == doublyLinkedList->Tail)
        RemoveHeadElement(doublyLinkedList);
    else {
        node = doublyLinkedList->Head;
        while (node->Next != doublyLinkedList->Tail)
            node = node->Next;
        node->Next = NULL;
        free(doublyLinkedList->Tail);
        doublyLinkedList->Tail = node;
    }
}

void PrintList(DoublyLinkedList *doublyLinkedList) {
    Node *temp = doublyLinkedList->Head;
    printf("\nElements of doubly linked list: ");
    while (temp != NULL) {
        printf("%d ", temp->Value);
        temp = temp->Next;
    }
    printf("\n");
}