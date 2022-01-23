#include <stdio.h>
#include <stdlib.h>

#define size 20
 
struct Gene{
    int x,y;
};

int** Generate_Random_Maze(){
    int **Maze;
    Maze = malloc(sizeof(int*)*size);
    for(int width_of_Maze=0;width_of_Maze<size;width_of_Maze++){
        Maze[width_of_Maze] = malloc(sizeof(int*)*size);
    }
    for(int width = 0 ; width<size ; width++){
        for(int height = 0;height<size;height++){
            int temp = rand() % 2;
            Maze[height][width] = temp;
            
        }
    }

    return(Maze);
}

struct Gene* Create_Gene_From_Maze(int **Maze,int walls){
    
    struct Gene *Chromosome = malloc(walls * sizeof(struct Gene * ));
    for(int i =0;i<walls;i++){
        Chromosome[i].x = malloc(sizeof(int));
        Chromosome[i].y = malloc(sizeof(int));
    }
    int GeneCounter = 0;
    for(int width = 0 ; width<size ;width++){
        for(int height = 0;height<size;height++){
            if(Maze[height][width] == 1){
                Chromosome[GeneCounter].x = width;
                Chromosome[GeneCounter].y = height;
                GeneCounter++;
                }
            }
        }
    
    return(Chromosome);
}

void Print_Maze(int **Maze){
    for(int width = 0 ; width<size ; width++){
        for(int height = 0;height<size;height++){
            printf("%d",Maze[width][height]);
        }
        printf("\n");
    }
}

void Print_Gene(struct Gene *gene,int walls){
    
    for(int length_of_Gene = 0 ; length_of_Gene<walls ; length_of_Gene++){
        printf("%d , %d",gene[length_of_Gene].x , gene[length_of_Gene].y);
        printf("\n");
    }
}
