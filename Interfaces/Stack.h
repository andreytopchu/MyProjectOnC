struct StackNode {
    int key;
    struct StackNode * prev;
};

struct Stack {
    struct StackNode * head;
};

typedef struct StackNode StackNode;
typedef struct Stack Stack;

//Создание стека
Stack * CreateStack(void);

//Провка стека на пустоту
unsigned StackIsEmpty(Stack *);

//Добавить элемент в верх стека
void Push(Stack *stack, int key);

//Удалить элемент с верха стека
int Pop(Stack *stack);

//Вывести элементы стека
void PrintStack(Stack *stack);
