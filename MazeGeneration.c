#include <stdio.h>
#include <stdlib.h>
#include "Main.h"
#include "MazeGeneration.h"
#include "Genetics.h"
#include "FitnessFunctions.h"

int** Generate_Random_Maze(){
    int **Maze = malloc(sizeof(int*)*size);
    int wall_Counter = 0;

    for(int width_of_Maze=0;width_of_Maze<size;width_of_Maze++){
        Maze[width_of_Maze] = calloc(1, sizeof(int*)*size);
    }
    int x = 0;
    int y = 0;
    for(int i=0;i<walls;i++){
        x = rand() % 20;
        y = rand() % 20;
        int loopexit = 0;
        while(loopexit == 0){
            if(Maze[x][y] == 0){
                Maze[x][y] = 1;
                loopexit = 1;
            }else{
                x = rand() % 20;
                y = rand() % 20;
            }
        
        }
        
    }

    //Optimized to above generation
    // for(int width = 0 ; width<size ; width++){
    //     for(int height = 0;height<size; height++){
    //         int temp = rand() % 2;
    //         if(wall_Counter >= walls && temp == 1){
    //             Maze[height][width] = 0;
    //         }else{
    //         Maze[height][width] = temp;
    //         }
    //         if(temp == 1){
    //             wall_Counter++;
    //         }
    //     }
    // }

    return(Maze);
}

struct GeneArray* Create_Gene_From_Maze(int **Maze){
    
    struct GeneArray *Chromosome = malloc(sizeof(struct GeneArray ));
    struct Gene  *savegene;
    int GeneCounter = 0;
    for(int width = 0 ; width<size ;width++){
        for(int height = 0;height<size;height++){
            if(Maze[height][width] == 1){
                savegene = malloc(sizeof(struct Gene *));
                savegene->x = width;
                savegene->y = height;
                Chromosome->Array[GeneCounter] = savegene;
                GeneCounter++;
                Chromosome->back++;
                }
            }
        }
    
    return(Chromosome);
}

void Create_Maze_From_Gene(int ** Maze,struct GeneArray *cGenes,int index){
    for(int i =0;i<walls;i++){
        int tmp1 = cGenes->Array[index][i].x;
        int tmp2 = cGenes->Array[index][i].y;
       Maze[cGenes->Array[index][i].x][cGenes->Array[index][i].y] = 1;
    }
    
}

void Create_Maze_From_Gene_Single(int ** Maze, struct GeneArray cGenes){
    
    for(int i = 0;i<walls;i++){
        int tmp1 = cGenes.Array[i]->x;
        int tmp2 = cGenes.Array[i]->y;
       Maze[tmp2][tmp1] = 1;
    }
}




void Print_Maze_Colour(int **Maze){
    for(int width = 0 ; width<size ; width++){
        for(int height = 0;height<size;height++){
            if(Maze[width][height] == 0 ){
                printf(" ");
            }else if(Maze[width][height] == 1 ){
                printf("\u2588");
            }else{
                printf("\033[1;35m");
                printf("\u2588");
                printf("\033[0m");
            }
            
        }
        printf("\n");
    }
}

void Print_Maze(int **Maze){
    for(int width = 0 ; width<size ; width++){
        for(int height = 0;height<size;height++){
            printf("%d",Maze[width][height]); 
        }
        printf("\n");
    }
}

void Print_Gene(struct Gene *gene[walls]){
    for(int k = 0 ; k<walls ; k++){
        printf("%d , %d , %d",k,gene[k]->x , gene[k]->y);
        printf("\n");
    }
}

void Print_Gene_Malloc(struct Gene *gene){
    for(int k = 0 ; k<walls ; k++){
        printf("%d , %d",gene[k].x , gene[k].y);
        printf("\n");
    }
}

void Print_Gene_Array(struct GeneArray *CrossedGenes){
    //Currently all the genes
    for(int m=0;m<CrossoverLimit;m++){
        for(int n=0;n<walls;n++){
            printf("%d,%d\n",CrossedGenes->Array[m][n].x,CrossedGenes->Array[m][n].y);
        }
        printf("########################################\n");
        
    }
}


void PushGeneArray(struct GeneArray *Array, struct Gene *value){
    Array->Array[Array->back] = value;
    ++Array->back;
}


struct Gene * Creat_Maze_From_Gene_2(int **Maze){

    struct Gene *SaveGeneArray = malloc(walls * sizeof(struct Gene));
    int GeneCounter = 0;
    for(int width = 0 ; width<size ;width++){
        for(int height = 0;height<size;height++){
            if(Maze[height][width] == 1){
                struct Gene  *savegene = malloc(sizeof(struct Gene *));
                savegene->x = width;
                savegene->y = height;
                SaveGeneArray[GeneCounter] = *savegene;
                GeneCounter++;
                }
            }
        }
    return(SaveGeneArray);
}
