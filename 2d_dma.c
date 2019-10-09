#include <stdio.h>
#include <stdlib.h>
 
int main()
{
    int r , c , i, j, count;
    printf("Rows?:");
    scanf("%d",&r);
    printf("Columns?");
    scanf("%d",&c);
 
    int **arr = (int **)malloc(r * sizeof(int *));
    for (i=0; i<r; i++)
         arr[i] = (int *)malloc(c * sizeof(int));
 
    // Note that arr[i][j] is same as *(*(arr+i)+j)
    count = 0;
    for (i = 0; i <  r; i++)
      for (j = 0; j < c; j++)
         arr[i][j] = ++count;  // OR *(*(arr+i)+j) = ++count
 
    for (i = 0; i <  r; i++)
      for (j = 0; j < c; j++)
         printf("%d ", arr[i][j]);
 
   /* Code for further processing and free the 
      dynamically allocated memory */
 
   return 0;
}