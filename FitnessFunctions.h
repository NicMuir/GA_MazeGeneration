#ifndef FITNESSFUNCTIONS_H
#define FITNESSFUNCTIONS_H


struct Node{
    int x,y;
};

struct Stack{
    struct Node stack[MAX]; //upperbound for max size of path
    int MaxSize;
    int Length;
    int back;
};


struct Stack * initStack(struct Stack *FullStack);
void Push(struct Stack FullStack, struct Node value);
struct Node Pop(struct Stack FullStack);
struct Stack * Path(int **Maze);
void BackTrack_Path(struct Stack Path,int visited[size][size],struct Node Start,struct Node Goal);


#endif