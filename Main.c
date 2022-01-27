#include <stdio.h>
#include <stdlib.h>
#include "Main.h"
#include "MazeGeneration.h"
#include "Genetics.h"
#include "FitnessFunctions.h"


int **Mazes[Number_Of_Mazes];


int main(){

    struct GeneArray *Genes = malloc(Number_Of_Mazes+1*sizeof(struct GeneArray));//Array of GeneArray structs : therefor Array that contains chromosomes
    double OriginalFitnesses[CrossoverLimit] ;

    struct GeneArray *BestGenes = malloc(Number_Of_Mazes*sizeof(struct GeneArray));

    
    for(int i=0;i<Number_Of_Mazes;i++){
        Mazes[i] = Generate_Random_Maze(walls);
        //Genes[i] = *Create_Gene_From_Maze(Mazes[i]);
        BestGenes->Array[i] = Creat_Maze_From_Gene_2(Mazes[i]);
        OriginalFitnesses[i] = Fitness(Mazes[i]);
        
    }
    // calculate fitnesses of Original Mazes
    
    //sort fitnesses 
    sortFitnessArray(OriginalFitnesses,BestGenes);
    
    int ** Maze1 = malloc(size* sizeof(int*));
    for(int width_of_Maze=0;width_of_Maze<size;width_of_Maze++){
        Maze1[width_of_Maze] = malloc(size*sizeof(int*));
    }

    for(int width = 0 ; width<size ; width++){
        for(int height = 0;height<size;height++){
            Maze1[height][width] = 0;
        }
    }

    double Fitneses[CrossoverLimit];
    int ** Maze = malloc(size* sizeof(int*));
    for(int width_of_Maze=0;width_of_Maze<size;width_of_Maze++){
        Maze[width_of_Maze] = malloc(size*sizeof(int*));
    }


    for(int MainCrossLoop=0;MainCrossLoop<MutationSteps;MainCrossLoop++){
        struct GeneArray *CrossedGenes = CrossOver(BestGenes);

        if(OriginalFitnesses[0] == 1){
            printf("\n Found Solvable Maze");

            break;
        }

        //Calculate the fitnesses of the crossed genes
        for(int t = 0; t<CrossoverLimit;t++){
            for(int width = 0 ; width<size ; width++){
                for(int height = 0;height<size;height++){
                    Maze[height][width] = 0;
                }
            }
            Create_Maze_From_Gene(Maze,CrossedGenes,t);
            //Print_Maze(Maze);
            Fitneses[t]=Fitness(Maze); 
        }

        InsertFitness(OriginalFitnesses , Fitneses ,BestGenes, CrossedGenes);
        
    }
 
    for(int width = 0 ; width<size ; width++){
        for(int height = 0;height<size;height++){
            Maze[height][width] = 0;
        }
    }
    printf("\n Best Generated Maze :\n");
    Create_Maze_From_Gene(Maze,BestGenes,0);
    printf("\n%f\n",Fitness(Maze));
    Maze[0][0] = 5;
    Maze[19][19] = 6;
    Print_Maze_Colour(Maze);
    free(Maze);
    return 0;
 }





