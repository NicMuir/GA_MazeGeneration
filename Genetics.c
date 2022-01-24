#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


#define CrossoverLimit 20
#define MutationAmount 20
#define Crossover_Indecies 3


void Mutation(struct Gene * gene, int length_of_Genes){
    int position = 0;
    int x = 0;
    int y = 0;
    for(int i=0;i<MutationAmount;i++){
        position = rand() % length_of_Genes;

        x = rand() % 20;
        y = rand() % 20;

        //Guaranties new coords are not already in the gene
        for(int k =0;k<length_of_Genes;k++){
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


void CrossOver(struct Gene **Genes,int length_of_Genes){
    struct Gene *CrossedGenes[CrossoverLimit];
    int Partition_Lengths = floor(length_of_Genes/Crossover_Indecies);
    
    for(int i=0;i<CrossoverLimit;i=i+2){
        struct Gene *Duplicate1 = malloc(length_of_Genes * sizeof(struct Gene*));
        struct Gene *Duplicate2 = malloc(length_of_Genes * sizeof(struct Gene*));
        memcpy(Duplicate1,Genes[0],length_of_Genes * sizeof(struct Gene*));
        memcpy(Duplicate2,Genes[1],length_of_Genes * sizeof(struct Gene*));
        for(int k =0;k<Crossover_Indecies;k++){
            single_crossover(Duplicate1,Duplicate2,Partition_Lengths,Partition_Lengths*k);
        }
        Mutation(Duplicate1,length_of_Genes);
        Mutation(Duplicate2,length_of_Genes);
        CrossedGenes[i] = Duplicate1;
        CrossedGenes[i+1]=Duplicate2;
    }

}




