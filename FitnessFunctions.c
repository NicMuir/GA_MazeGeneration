#include <stdio.h>
#include <stdlib.h>
#define MAX 250


struct Node{
    int x,y;
};

struct Stack{
    struct Node stack[MAX]; //upperbound for max size of path
    int MaxSize;
    int back;
};
struct Stack * initStack(struct Stack *FullStack){
    FullStack->MaxSize = MAX;
    FullStack->back = 0;
    return FullStack;
}

void Push(struct Stack FullStack,struct Node value){
    FullStack.back++;
    FullStack.stack[FullStack.back] = value;
}

struct Node Pop(struct Stack FullStack){
    FullStack.back--;
    return(FullStack.stack[FullStack.back+1]);
}

struct Stack * Path(){
    struct Node start = {0,0};
    struct Node* visited[MAX];
    struct Stack *FullStack = malloc(sizeof(struct Stack * ));
    initStack(FullStack);
}