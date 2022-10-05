struct DoublyLinkedList {
    struct Node *Head;
    struct Node *Tail;
};

struct Node {
    int Value;
    struct Node *Next;
    struct Node *Previous;
};

typedef struct DoublyLinkedList DoublyLinkedList;
typedef struct Node Node;

//Создание двусвязного списка
DoublyLinkedList *CreateNewList(void);

//Проверка на пустоту списка
unsigned ListIsEmpty(DoublyLinkedList *);

//Вставка элемента в начало
void InsertFirstElement(DoublyLinkedList *, int);

//Вставка элемента в конец
void InsertLastElement(DoublyLinkedList *, int);

//Вставка элемента до передаваемого элемента
void InsertBeforeElement(DoublyLinkedList *, Node *, int key);

//Вставка элемента после передаваемого элемента
void InsertAfterElement(DoublyLinkedList *, Node *, int key);

//Показать ключ элемента
void Show(Node *);

//Удалить элемент из списка
void RemoveNode(Node *);

//Удалить элемент с начала списка
void RemoveHeadElement(DoublyLinkedList *);

//Удалить элемент с конца списка
void RemoveTailElement(DoublyLinkedList *);

//Вывести все элементы списка от начала до конца
void PrintList(DoublyLinkedList *);
