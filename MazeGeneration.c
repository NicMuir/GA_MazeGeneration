#include <stdio.h>
#include <stdlib.h>

#define size 20
 
int** Generate_Random_Array(){
    int **Maze;

    Maze = malloc(sizeof(int*)*size);
    for(int width_of_Maze=0;width_of_Maze<size;width_of_Maze++){
        Maze[width_of_Maze] = malloc(sizeof(int*)*size);
    }

    for(int width = 0 ; width<size ; width++){
        for(int height = 0;height<size;height++){
            Maze[width][height] = rand() % 2;
        }
    }
    return(Maze);
}

void Print_Maze(int **Maze ){
    for(int width = 0 ; width<size ; width++){
        for(int height = 0;height<size;height++){
            printf("%d",Maze[width][height]);
        }
        printf("\n");
    }
}
