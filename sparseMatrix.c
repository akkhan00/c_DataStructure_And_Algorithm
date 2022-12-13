#include <stdio.h>

void printArray(int size, int compactMatrix[][size]);

int main(){
  // Assume 4x5 matrix
  int sparseMatrix[4][5] = {
    {0,0,3,0,4},{1,0,0,4,0},{0,0,0,0,0},{5,3,2,0,6}
  };

  int size = 0;
  for (int i = 0; i<4; i++){
    for(int j = 0; j<5; j++){
      if(sparseMatrix[i][j] != 0)
        size ++;
    }
  }
  
  // Making of new matrix
  int compactMatrix[3][size];

  int k = 0;
  for(int i = 0; i < 4; i++){
    for (int j=0; j < 5; j++){
      if (sparseMatrix[i][j] != 0){
        compactMatrix[0][k] = i; // row
        compactMatrix[1][k] = j; // column
        compactMatrix[2][k] = sparseMatrix[i][j]; // value
        k ++;
      }
    }
  }

  // print the compactMatrix
  printArray(size, compactMatrix);
  
  return 0;
}

void printArray(int size, int compactMatrix[][size]){
for (int i = 0; i<3; i++){
    for (int j = 0; j<size; j++){
      if(i == 0 && j == 0)
        printf("Row:    ");
      else if(i == 1 && j == 0)
        printf("Column: ");
      else if(i == 2 && j == 0)
        printf("Value:  ");
      printf("| %d", compactMatrix[i][j]);
    }
    printf("\n");
    printf("___________________________________________________\n");
}}
