#include <stdio.h>
#include <stdlib.h>
int main() 
{
    int row,column;
    printf("Hello");
    scanf("%d",&row);
     scanf("%d",&column);
     int** arr=malloc(row*(sizeof(int*)));
     for(int i=0;i<row;i++)
     {
         arr[i]=malloc(column*sizeof(int*));
     }
     for(int i=0;i<row;i++)
     {
         for(int j=0;j<column;j++)
         {
             scanf("%d",&arr[i][j]);
         }
     }
     for(int i=0;i<row;i++)
     {
         for(int j=0;j<column;j++)
         {
             printf("%d",arr[i][j]);
         }
         printf("\n");
     }
     for(int i=0;i<row;i++)
     {
         free(arr[i]);
     }
     free(arr);
     return 0;
}
