#include <stdio.h>
#include <stdlib.h>
#include "Main.h"
#include "MazeGeneration.h"
#include "Genetics.h"
#include "FitnessFunctions.h"


int Global_Path_Finnishable = 0;


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

struct Stack * Path(int **Maze){
    Global_Path_Finnishable = 0;

    struct Node start = {.x = 0,
                         .y = 0};

    struct Node goal = {.x = 19,
                        .y = 19};

    
    int visited_idx = 0;
    int visited[size][size];
    struct Stack *Path = malloc(sizeof(struct Node *));
    struct Stack *FullStack = malloc(sizeof(struct Stack * ));
    initStack(FullStack);

    //add start to visited array
    visited_idx++;
    visited[start.x][start.y] = 5; //Visited being 1 for N ; 2 for E ; 3 for S ; 4 for W ; 5 for the start
    // push start to stack
    Push(*FullStack,start);
    printf("%d,%d",FullStack->stack[FullStack->back-1].x,FullStack->stack[FullStack->back-1].y);

    while(FullStack->Length > 0){
        struct Node Current = Pop(*FullStack);

        if(Current.x == goal.x && Current.y == goal.y){
            BackTrack_Path(*Path,visited,start,goal);
            Global_Path_Finnishable = 1;
            return Path;
        }
        //Note the values 1,2,3,4 are inverted for backtracking purposes

        if (Current.x > 0 && Current.y < size-1 && Maze[Current.x-1][Current.y] == 0 ){ //North
            if (visited[Current.x-1][Current.y] == 0)
            {
               visited[Current.x-1][Current.y] = 3;
               struct Node temp = {Current.x-1,Current.y};
               Push(*FullStack,temp);
            }
            
        }

        else if (Current.x > size-1 && Current.y < size-1 && Maze[Current.x+1][Current.y] == 0 ){ //South
            if (visited[Current.x+1][Current.y] == 0)
            {
               visited[Current.x-1][Current.y] = 1;
               struct Node temp = {Current.x+1,Current.y};
               Push(*FullStack,temp);
            }
            
        }

        else if (Current.x < size-1 &&  Maze[Current.x][Current.y+1] == 0 ){ //East
            if (visited[Current.x+1][Current.y] == 0)
            {
               visited[Current.x-1][Current.y] = 4;
               struct Node temp = {Current.x,Current.y+1};
               Push(*FullStack,temp);
            }
            
        }

        else if (Current.x > 0 &&  Maze[Current.x][Current.y-1] == 0 ){ //East
            if (visited[Current.x+1][Current.y] == 0)
            {
               visited[Current.x-1][Current.y] = 2;
               struct Node temp = {Current.x,Current.y+1};
               Push(*FullStack,temp);
            }
            
        }


    }

    return Path;
}
void BackTrack_Path(struct Stack Path,int visited[size][size],struct Node Start, struct Node Goal){
    int Current  = visited[Goal.x][Goal.y];
    struct Node Current_In_Maze = Goal;
    Push(Path,Goal);
    while(Current != 5){
        if(Current ==  1){
            struct Node temp = {Current_In_Maze.x-1,Current_In_Maze.y};
            Push(Path,temp);
            Current = visited[temp.x][temp.y];
            Current_In_Maze = temp;
        }else if(Current==2){
            struct Node temp = {Current_In_Maze.x,Current_In_Maze.y+1};
            Push(Path,temp);
            Current = visited[temp.x][temp.y];
            Current_In_Maze = temp;
        }else if(Current==3){
            struct Node temp = {Current_In_Maze.x+1,Current_In_Maze.y};
            Push(Path,temp);
            Current = visited[temp.x][temp.y];
            Current_In_Maze = temp;

        }else if(Current==4){
            struct Node temp = {Current_In_Maze.x,Current_In_Maze.y-1};
            Push(Path,temp);
            Current = visited[temp.x][temp.y];
            Current_In_Maze = temp;
        }
    }
}


