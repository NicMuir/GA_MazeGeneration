#include <stdio.h>
#include <stdlib.h>
#define MAX 250
#define size 20


struct Node{
    int x,y;
};

struct Stack{
    struct Node stack[MAX]; //upperbound for max size of path
    int MaxSize;
    int Length;
    int back;
};
struct Stack * initStack(struct Stack *FullStack){
    FullStack->MaxSize = MAX;
    FullStack->back = 0;
    FullStack->Length = 0;
    return FullStack;
}

void Push(struct Stack FullStack,struct Node value){
    FullStack.back++;
    FullStack.Length++;
    FullStack.stack[FullStack.back] = value;
}

struct Node Pop(struct Stack FullStack){
    FullStack.back--;
    return(FullStack.stack[FullStack.back+1]);
}

struct Stack * Path(){
    struct Node start = {.x = 0,
                         .y = 0};

    struct Node goal = {.x = 19,
                        .y = 19};

    
    int visited_idx = 0;
    struct Node visited[MAX];
    struct Node Path[MAX];
    struct Stack *FullStack = malloc(sizeof(struct Stack * ));
    initStack(FullStack);

    //add start to visited array
    visited[visited_idx] = start;
    visited_idx++;

    // push start to stack
    Push(*FullStack,start);
    printf("%d,%d",FullStack->stack[FullStack->back-1].x,FullStack->stack[FullStack->back-1].y);

    while(FullStack->Length > 0){
        struct Node Current = Pop(*FullStack);

        if(Current.x == goal.x && Current.y == goal.y){
            BackTrack_Path(Path,visited,start,goal);
        }


    }
}
void BackTrack_Path(struct Node Path[],struct Node visited[],struct Node Start, struct Node Goal){

}
