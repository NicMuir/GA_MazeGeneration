#ifndef MAZEGENERATION_H
#define MAZEGENERATION_H


 
struct Gene {
    int x,y;
};


int** Generate_Random_Maze();
struct Gene* Create_Gene_From_Maze(int **Maze);
int** Create_Maze_From_Gene(int ** Maze,struct Gene *gene);
void Print_Maze(int **Maze);
void Print_Gene(struct Gene *gene);

#endif