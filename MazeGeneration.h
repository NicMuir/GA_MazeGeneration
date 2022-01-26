#ifndef MAZEGENERATION_H
#define MAZEGENERATION_H


 
struct Gene {
    int x,y;
};

struct GeneArray{
    struct Gene *Array[walls];
    int back;
};


int** Generate_Random_Maze();
struct GeneArray* Create_Gene_From_Maze(int **Maze);
// void Create_Maze_From_Gene(int ** Maze,struct GeneArray *CrossedGenes);
void Create_Maze_From_Gene(int ** Maze,struct GeneArray *CrossedGenes);
void Print_Maze(int **Maze);
void Print_Gene(struct Gene *gene[walls]);
void Print_Gene_Malloc(struct Gene *gene);
void Print_Gene_Array(struct GeneArray *CrossedGenes);
void PushGeneArray(struct GeneArray *Array,struct Gene *value);

#endif