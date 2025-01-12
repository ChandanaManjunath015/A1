#include <stdio.h>
#include <stdlib.h>

void readMatrix(int **matrix,int size)
{
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            scanf("%d",*(matrix+i)+j);
        }
    }
}

void printMatrix(int **matrix,int size)
{
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            printf("%d ",*(*(matrix+i)+j));
        }
        printf("\n");
    }
    
}

void printUpperMatrix(int **matrix,int size)
{
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            if(i<=j)
            {
                printf("%d ",*(*(matrix+i)+j));
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
    
}


void  isFindUpperTriangularMatrix(int **matrix,int size)
{
   for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            if(i<=j)
              continue;
             else
              *(*(matrix+i)+j)=0;
              
        }
    }
}

int main()
{
    int size;
    printf("Enter size\n");
    scanf("%d",&size);
    int **matrix=malloc(size*sizeof(int*));
    if(matrix==NULL)
    {
        printf("Memory allocation failed");
        return 1;
    }
    for(int i=0;i<size;i++)
    {
        matrix[i]=malloc(size*sizeof(int));
    }
    printf("Enter matrix elements:\n");
    readMatrix(matrix,size);
    printf("Matrix is:\n");
    printMatrix(matrix,size);
    isFindUpperTriangularMatrix(matrix,size);
    printf("Upper triangular matrix elements with space:\n");
    printUpperMatrix(matrix,size);
    printf("Upper triangular matrix elements with zero:\n");
    printMatrix(matrix,size);
    for(int i=0;i<size;i++)
    {
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}
