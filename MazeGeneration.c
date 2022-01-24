#include <stdio.h>
#include <stdlib.h>

#define size 20
 
struct Gene{
    int x,y;
};

int** Generate_Random_Maze(int Number_Of_Walls){
    int **Maze;
    int wall_Counter = 0;
    Maze = malloc(sizeof(int*)*size);

    for(int width_of_Maze=0;width_of_Maze<size;width_of_Maze++){
        Maze[width_of_Maze] = calloc(1, sizeof(int*)*size);
    }
    int x = 0;
    int y = 0;
    for(int i=0;i<Number_Of_Walls;i++){
        x = rand() % 20;
        y = rand() % 20;
        int loopexit = 0;
        while(loopexit == 0){
            if(Maze[y][x] == 0){
                Maze[y][x] = 1;
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
    //         if(wall_Counter >= Number_Of_Walls && temp == 1){
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
    
    for(int k = 0 ; k<walls ; k++){
        printf("%d , %d",gene[k].x , gene[k].y);
        printf("\n");
    }
}
