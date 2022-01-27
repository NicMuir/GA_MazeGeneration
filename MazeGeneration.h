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
struct Gene * Creat_Maze_From_Gene_2(int **Maze);


void Create_Maze_From_Gene(int ** Maze,struct GeneArray *CrossedGenes,int index);
void Create_Maze_From_Gene_Single(int ** Maze,struct GeneArray cGenes);


void Print_Maze(int **Maze);
void Print_Maze_Colour(int **Maze);
void Print_Gene(struct Gene *gene[walls]);
void Print_Gene_Malloc(struct Gene *gene);
void Print_Gene_Array(struct GeneArray *CrossedGenes);



void PushGeneArray(struct GeneArray *Array,struct Gene *value);


#endif