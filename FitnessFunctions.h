#ifndef FITNESSFUNCTIONS_H
#define FITNESSFUNCTIONS_H


struct Node{
    int x,y;
};

struct Stack{
    struct Node stack[1000]; //upperbound for max size of path
    int Front;
    int Length;
    int back;
};


struct Stack * initStack(struct Stack *FullStack);
void Push(struct Stack *FullStack, struct Node value);
struct Node Pop(struct Stack *FullStack);
void Path(int **Maze,int *visited_idx);
void BackTrack_Path(int visited[size][size],struct Node Start,struct Node Goal);
double Fitness(int **Maze);

void sortFitnessArray(double Fitneses[CrossoverLimit]);
void InsertFitness(double BestFits[CrossoverLimit] , double NewFits[CrossoverLimit], struct GeneArray *OrigGenes, struct GeneArray *CrosseGenes);



#endif