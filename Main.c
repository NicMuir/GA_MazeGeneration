#include <stdio.h>
#include <stdlib.h>
#include "Main.h"
#include "MazeGeneration.h"
#include "Genetics.h"
#include "FitnessFunctions.h"



struct Gene *Genes[Number_Of_Mazes];
int **Mazes[Number_Of_Mazes];

int main(){
    for(int i=0;i<Number_Of_Mazes;i++){
        Mazes[i] = Generate_Random_Maze(walls);
        Genes[i] = Create_Gene_From_Maze(Mazes[i]); 
    }
    //Print Mazes and wall genetics
    // for(int i =0;i< Number_Of_Mazes;i++){
    //     Print_Maze(Mazes[i]);
    //     printf("\n");
    //     Print_Gene(Genes[i]);
    // }

    CrossOver(Genes);
    return 0;
 }