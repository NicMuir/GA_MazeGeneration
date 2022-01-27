#include <stdio.h>
#include <stdlib.h>
#include "Main.h"
#include "MazeGeneration.h"
#include "Genetics.h"
#include "FitnessFunctions.h"


int Global_Path_Finnishable = 0;
int Global_Created_Check = 0;


struct Stack * initStack(struct Stack *FullStack){
    FullStack->Front = 0;
    FullStack->back = 0;
    FullStack->Length = 1;
    return FullStack;
}

void Push(struct Stack *FullStack,struct Node value){
    FullStack->back = FullStack->back + 1;
    FullStack->Length = FullStack->Length + 1;
    FullStack->stack[FullStack->back] = value;

}

struct Node Pop(struct Stack *FullStack){
    struct Node temp = FullStack->stack[FullStack->Front];
    FullStack->Front = FullStack->Front+1;
    //FullStack->back = FullStack->back-1;
    FullStack->Length = FullStack->Length-1;
    return(temp);
}

void Path(int **Maze,int *visited_idx){
    Global_Path_Finnishable = 0;

    struct Node start = {.x = 0,
                         .y = 0};

    struct Node goal = {.x = 19,
                        .y = 19};

    
    int vis_idx = 0;
    int visited[size][size] = {0};


    
    struct Stack *FullStack = malloc(sizeof(struct Stack )) ;
    

    initStack(FullStack);

    //add start to visited array
    
    visited[start.x][start.y] = 5; 
    // push start to stack
    Push(FullStack,start);

    while(FullStack->Length > 0){
        vis_idx=vis_idx+1;
        
        struct Node Current = Pop(FullStack);

        if(Current.x == goal.x && Current.y == goal.y){
            printf("Finishable\n");
            free(FullStack);
            //BackTrack_Path(visited,start,goal); // Takes a while to backtrack path to display Not Working ATM
            Global_Path_Finnishable = 1;
            return ;
        }
        //Note the values 1,2,3,4 are inverted for backtracking purposes
        



        if (Current.x < size-1 && Current.y < size-1 && Current.y > -1 && Current.x > 0 && Maze[Current.x-1][Current.y] == 0 ){ 
            if (visited[Current.x-1][Current.y] == 0)
            {
               visited[Current.x-1][Current.y] = 3;
               struct Node temp = {Current.x-1,Current.y};
               Push(FullStack,temp);
            }
            
            
        }

        if (Current.x < size-1 && Current.y > -1 && Current.x > -1 && Maze[Current.x+1][Current.y] == 0 ){ 
            if (visited[Current.x+1][Current.y] == 0)
            {
               visited[Current.x+1][Current.y] = 1;
               struct Node temp = {Current.x+1,Current.y};
               Push(FullStack,temp);  
            }
            
        }

        if (Current.y < size-1 && Current.y > -1 && Current.x > -1 && Maze[Current.x][Current.y+1] == 0 ){ 
            if (visited[Current.x][Current.y+1] == 0)
            {
               visited[Current.x][Current.y+1] = 4;
               struct Node temp = {Current.x,Current.y+1};
               Push(FullStack,temp);
            }
            
        }

        if (Current.x < size-1 && Current.y < size-1 && Current.y > 0 && Current.x > -1 && Maze[Current.x][Current.y-1] == 0 ){ 
            if (visited[Current.x][Current.y-1] == 0)
            {
               visited[Current.x][Current.y-1] = 2;
               struct Node temp = {Current.x,Current.y-1};
               Push(FullStack,temp);
               
            }
            
            
        }

        


    }
    printf("\n");
    printf("NOT Finishable\n");
    Global_Created_Check++;
    *visited_idx = vis_idx;
    
    free(FullStack);
    return;
}

//Not Currently working

void BackTrack_Path(int visited[][size],struct Node Start, struct Node Goal){
    printf("backtrack");
    struct Stack * path = malloc(sizeof(struct Stack ));

    int Current  = visited[Goal.x][Goal.y];
    struct Node Current_In_Maze = Goal;

    Push(path,Goal);
    while(Current != 5){
        if(Current ==  1){
            struct Node temp = {Current_In_Maze.x-1,Current_In_Maze.y};
            Push(path,temp);
            Current = visited[temp.x][temp.y];
            Current_In_Maze = temp;
        }else if(Current==2){
            struct Node temp = {Current_In_Maze.x,Current_In_Maze.y+1};
            Push(path,temp);
            Current = visited[temp.x][temp.y];
            Current_In_Maze = temp;
        }else if(Current==3){
            struct Node temp = {Current_In_Maze.x+1,Current_In_Maze.y};
            Push(path,temp);
            Current = visited[temp.x][temp.y];
            Current_In_Maze = temp;

        }else if(Current==4){
            struct Node temp = {Current_In_Maze.x,Current_In_Maze.y-1};
            Push(path,temp);
            Current = visited[temp.x][temp.y];
            Current_In_Maze = temp;
        }
    }
}

double Fitness(int **Maze){
    //fitness calculations
    int visited_idx = 0 ;
    Path(Maze,&visited_idx);
    Print_Maze(Maze);
    if(Global_Path_Finnishable == 0){
        return((double)visited_idx/(double)walls);
    }else{
        return 1;
    }
}
