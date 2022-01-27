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
    // calculate fitnesses of Original Mazes
    double OriginalFitnesses[CrossoverLimit] = {0};
    

    for(int i=0;i<Number_Of_Mazes;i++){
        OriginalFitnesses[i] = Fitness(Mazes[i]);
    }

    //sort fitnesses 
    sortFitnessArray(OriginalFitnesses);
    
    //perform crossover until fitness is good

    struct GeneArray *CrossedGenes = CrossOver(Genes);
    double Fitneses[CrossoverLimit];
    


    int ** Maze = malloc(size* sizeof(int*));
    for(int width_of_Maze=0;width_of_Maze<size;width_of_Maze++){
        Maze[width_of_Maze] = malloc(size*sizeof(int*));
    }
    for(int t = 0; t<CrossoverLimit;t++){
        

        for(int width = 0 ; width<size ; width++){
            for(int height = 0;height<size;height++){
                Maze[height][width] = 0;
            }
        }
        
        
        Create_Maze_From_Gene(Maze,CrossedGenes,t);
        //Print_Maze(Maze);
        
        Fitneses[t]=Fitness(Maze);
        // printf("%lf\n",Fitneses[t]);
          
    }

    sortFitnessArray(Fitneses);
    return 0;
 }



