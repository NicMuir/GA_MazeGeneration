#include <iostream>
#include <random>


using namespace std;
 
int* Generate_Random_Array(int size){
    int Maze = new int[size][size];
    for(int width = 0 ; width<size ; width++){
        for(int height = 0;height<size;height++){
            Array[width][height] = rand() % 2;
        }
    }
    return(&Array);
}

void Print_Maze(int size , int* Array ){
    for(int width = 0 ; width<size ; width++){
        for(int height = 0;height<size;height++){
            cout << Array[width][height];
        }
        cout << endl;
    }
}

int PopulateMazes(Mazes){

 }