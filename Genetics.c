#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Main.h"
#include "MazeGeneration.h"
#include "Genetics.h"
#include "FitnessFunctions.h"
extern int Global_Path_Finnishable;


void Mutation(struct Gene * gene){
    int position = 0;
    int x = 0;
    int y = 0;
    for(int i=0;i<MutationAmount;i++){
        position = rand() % walls;

        x = rand() % 20;
        y = rand() % 20;

        //Guaranties new coords are not already in the gene
        for(int k =0;k<walls;k++){
            if(gene[k].x == x && gene[k].y == y){
                x = rand() % 20;
                y = rand() % 20;
                k=0;
            }
        }
        gene[position].x = x;
        gene[position].y = y;
        
    }
}


void single_crossover(struct Gene * gene1,struct Gene * gene2 ,int partition_size,int partition_index){
    struct Gene *temp = malloc((partition_size+1) * sizeof(struct Gene*));
    //coppy to temp array 
    for(int i = 0;i<partition_size;i++){
        temp[i] = gene1[partition_index+i];
    }
    for(int i = 0;i<partition_size;i++){
        gene1[partition_index+i] = gene2[partition_index+i];
        gene2[partition_index+i] = temp[i];
    } 

    free(temp);
}


void CrossOver(struct Gene **Genes){
    int ** temp;
    struct Gene *CrossedGenes[CrossoverLimit];
    double Fitneses[CrossoverLimit];
    int Partition_Lengths = floor(walls/Crossover_Indecies);
    
    for(int i=0;i<CrossoverLimit;i=i+2){
        struct Gene *Duplicate1 = malloc(walls * sizeof(struct Gene*));
        struct Gene *Duplicate2 = malloc(walls * sizeof(struct Gene*));
        memcpy(Duplicate1,Genes[0],walls * sizeof(struct Gene*));
        memcpy(Duplicate2,Genes[1],walls * sizeof(struct Gene*));
        for(int k =0;k<Crossover_Indecies;k++){
            single_crossover(Duplicate1,Duplicate2,Partition_Lengths,Partition_Lengths*k);
        }
        Mutation(Duplicate1);
        Mutation(Duplicate2);
        CrossedGenes[i] = Duplicate1;
        CrossedGenes[i+1]=Duplicate2;
    }
    // temp = Create_Maze_From_Gene(CrossedGenes[0]);
    // Print_Maze(temp);
    // printf("\n");
    // temp = Create_Maze_From_Gene(CrossedGenes[1]);
    // Print_Maze(temp);

    for(int t = 0; t<CrossoverLimit-1 ;t++){
        int ** Maze;
        if(t==0){
            Maze = malloc(sizeof(int*)*size);
            for(int width_of_Maze=0;width_of_Maze<size;width_of_Maze++){
                Maze[width_of_Maze] = malloc(sizeof(int*)*size);
            }
        }else{
            Maze = realloc(Maze,sizeof(int*)*size); 
        }


        //Print_Gene(CrossedGenes[t]);
        temp = Create_Maze_From_Gene(Maze,CrossedGenes[t]);
        Print_Maze(temp);
        double fit = Fitness(temp);
        Fitneses[t]=fit;
        
        printf("%lf\n",Fitneses[t]);
        
        
    }
    
    

}




