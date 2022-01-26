#ifndef GENETICS_H
#define GENETICS_H




void Mutation(struct Gene * gene);
void single_crossover(struct Gene * gene1,struct Gene * gene2 ,int partition_size,int partition_index);
struct GeneArray * CrossOver(struct GeneArray *Genes);


#endif