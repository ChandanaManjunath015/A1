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

void isFindDiagonalSum(int **matrix,int size)
{
    int mainDiagonalSum=0,oppositeDiagonalSum=0;
     for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            if(i==j)
              mainDiagonalSum+=*(*(matrix+i)+j);
            if(i+j==size-1)
             oppositeDiagonalSum+=*(*(matrix+i)+j);
              
        }
    }
    printf("Main diagonal sum:%d \n",mainDiagonalSum);
    printf("Opposite diagonal sum:%d \n",oppositeDiagonalSum);
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
    isFindDiagonalSum(matrix,size);
    for(int i=0;i<size;i++)
    {
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}
