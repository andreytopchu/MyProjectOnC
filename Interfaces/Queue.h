struct Queue {
    struct Node *Front;
    struct Node *Rear;
    int Size;
};

typedef struct Queue Queue;

//Создание узла
Node *CreateNode(int value, Node *previous);

//Создание очереди
Queue *CreateQueue();

//Добавление элемента в конец очереди
void QueuePush(Queue *queue, int value);

//Проверка очереди на пустоту
int QueueIsEmpty(Queue *queue);

//Возвращение элемента с начала очереди
int Peek(Queue *queue);

//Получение размера очереди
int QueueSize(Queue *queue);

//Удаление элемента с начала очереди и получение его
int QueuePop(Queue *queue);

//Вывести данные, содержащиеся в очереди
void PrintQueue(Queue *queue);
