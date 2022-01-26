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
        temp[i].x = gene1[partition_index+i].x;
        temp[i].y = gene1[partition_index+i].y;

        gene1[partition_index+i].x = gene2[partition_index+i].x;
        gene1[partition_index+i].y = gene2[partition_index+i].y;


        gene2[partition_index+i].x = temp[i].x;
        gene2[partition_index+i].y = temp[i].y;
    } 
    
    free(temp);
}


 struct GeneArray * CrossOver(struct GeneArray *Genes){
    
    int rnd1,rnd2;
    int ** temp;
    int idx_counter = 0;

    struct GeneArray *CrossedGenes = malloc(CrossoverLimit * sizeof(struct GeneArray));
    
    
    int Partition_Lengths = floor(walls/Crossover_Indecies);

    
    //Loop for generating child Genes via crossover method
    for(int i=0;i<CrossoverLimit;i++){

        struct Gene *Duplicate1 = malloc(walls * sizeof(struct Gene));
        struct Gene *Duplicate2 = malloc(walls * sizeof(struct Gene));

        rnd1 = rand() % Number_Of_Mazes;
        rnd2 = rand() % Number_Of_Mazes;

        for(int j=0;j<walls;j++){
            Duplicate1[j] = *Genes[rnd1].Array[j];
            Duplicate2[j] = *Genes[rnd2].Array[j];
        }
    
        for(int k =0;k<Crossover_Indecies;k++){
            single_crossover(Duplicate1,Duplicate2,Partition_Lengths,Partition_Lengths*k);
        }

        Mutation(Duplicate1);
        Mutation(Duplicate2);
        
    
        PushGeneArray(CrossedGenes,Duplicate1);
        PushGeneArray(CrossedGenes,Duplicate2);  
        
        
    }
    
    return CrossedGenes;
    
    

}




