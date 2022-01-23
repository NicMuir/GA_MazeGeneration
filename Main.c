#include <stdio.h>
#include "MazeGeneration.c"
#define Number_Of_Mazes 10
#define walls 150

struct Gene *Genes[Number_Of_Mazes];
int **Mazes[Number_Of_Mazes];

int main(){
    for(int Maze_Count=0;Maze_Count<Number_Of_Mazes;Maze_Count++){
        
        Mazes[Maze_Count] = Generate_Random_Maze();
        //printf("here \n");
        Genes[Maze_Count] = Create_Gene_From_Maze(Mazes[Maze_Count],walls);
        Print_Maze(Mazes[Maze_Count]);
        Print_Gene(Genes[Maze_Count],walls);
    }
    
    
    
    return 0;
 }