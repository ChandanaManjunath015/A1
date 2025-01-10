#include <stdio.h>
#include <stdlib.h>
int main() 
{
    int row,column;
    scanf("%d",&row);
    scanf("%d",&column);
    char*** a=malloc(row*sizeof(char**));
    for(int i=0;i<row;i++)
    {
        a[i]=malloc(column*sizeof(char*));
        for(int j=0;j<column;j++)
        {
             a[i][j]=malloc(100*sizeof(char*));
        }
        
    }
    for(int i=0;i<row;i++)
     {
         for(int j=0;j<column;j++)
        {
            scanf("%s",a[i][j]);
        }
     }
     for(int i=0;i<row;i++)
     {
         for(int j=0;j<column;j++)
        {
            printf("%s",a[i][j]);
        }
        printf("\n");
     }
     int dsum=0;
     for(int i=0;i<row;i++)
     {
         for(int j=0;j<column;j++)
        {
            if(i==j)
            {
                dsum+=atoi(a[i][j]);
            }
        }
     }
     printf("%d",dsum);
     for (int i = 0; i < row; i++) 
     {
        for (int j = 0; j < column; j++) 
        {
            free(a[i][j]); 
        }
        free(a[i]); 
    }
    free(a);

    return 0;
}
