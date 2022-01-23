#include <stdio.h>
#include "MazeGeneration.c"
#define Number_Of_Mazes 10


int **Mazes[Number_Of_Mazes];

int main(){
    for(int Maze_Count=0;Maze_Count<Number_Of_Mazes;Maze_Count++){
        Mazes[Maze_Count] = Generate_Random_Array();
    }
    Print_Maze(Mazes[0]);
    return 0;
 }