#include <stdio.h>
#include <stdlib.h>
#include "MazeGeneration.c"

#define Number_Of_Mazes 10
#define walls 170

struct Gene *Genes[Number_Of_Mazes];
int **Mazes[Number_Of_Mazes];

int main(){
    for(int i=0;i<Number_Of_Mazes;i++){
        
        Mazes[i] = Generate_Random_Maze(walls);
        //printf("here \n");
        Genes[i] = Create_Gene_From_Maze(Mazes[i],walls);
        
    }
    //Print Mazes and wall genetics
    for(int i =0;i< Number_Of_Mazes;i++){
        Print_Maze(Mazes[i]);
        printf("\n");
        Print_Gene(Genes[i],walls);
    }

    
    
    
    return 0;
 }