#include <stdio.h>
#define max 100
int main() {
    int row,column;
    scanf("%d",&row);
     scanf("%d",&column);
     int arr[max][max];
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
             printf("%d ",arr[i][j]);
         }
         printf("\n");
     }
     
    return 0;
}
