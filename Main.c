#include <stdio.h>
#include <stdlib.h>
#include "Main.h"
#include "MazeGeneration.h"
#include "Genetics.h"
#include "FitnessFunctions.h"


int **Mazes[Number_Of_Mazes];


int main(){
    struct GeneArray *Genes = malloc(Number_Of_Mazes*sizeof(struct GeneArray));//Array of GeneArray structs : therefor Array that contains chromosomes
    

    for(int i=0;i<Number_Of_Mazes;i++){
        Mazes[i] = Generate_Random_Maze(walls);
        Genes[i] = *Create_Gene_From_Maze(Mazes[i]);
        
    }

    
    CrossOver(Genes);
    return 0;
 }