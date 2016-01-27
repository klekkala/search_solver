// C++ program to check if a given instance of 8 puzzle is solvable or not
#include <iostream>
using namespace std;
 #include<stdio.h>
// A utility function to count inversions in given array 'arr[]'
int getInvCount(int arr[])
{
    int inv_count = 0;
    for (int i = 0; i < 9 - 1; i++)
        for (int j = i+1; j < 9; j++)
             // Value 0 is used for empty space
             if (arr[j] && arr[i] &&  arr[i] > arr[j])
                  inv_count++;
    return inv_count;
}
 
// This function returns true if given 8 puzzle is solvable.
bool isSolvable(int puzzle[3][3])
{
    // Count inversions in given 8 puzzle
    int invCount = getInvCount((int *)puzzle);
 
    // return true if inversion count is even.
    return (invCount%2 == 0);
}
 
/* Driver progra to test above functions */
int main()
{
  int puzzle[3][3] =  {{1, 8, 2},
                      {0, 4, 3},  // Value 0 is used for empty space
                      {7, 6, 5}};
  if(isSolvable(puzzle)==1){
    for(int i=0;i<3;i++){
      for(int j=0;j<3;j++){
        printf("%d ", puzzle[i][j]);
      }
      printf("\n");
    }
  }
  return 0;
}