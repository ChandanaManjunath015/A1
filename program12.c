#include <stdio.h>
#include <stdlib.h>

void readMatrix(int **matrix,int row,int column)
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            scanf("%d",*(matrix+i)+j);
        }
    }
}

void printMatrix(int **matrix,int row,int column)
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            printf("%d ",*(*(matrix+i)+j));
        }
        printf("\n");
    }
    
}

void isSparxMatrix(int **matrix,int row,int column)
{
    int zeroCount=0,nonZeroCount=0;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            if((*(*(matrix+i)+j))==0)
            {
                zeroCount++;
            }
            else
            {
                nonZeroCount++;
            }
        }
    }
    if(nonZeroCount>zeroCount)
        printf("Non sparx matrix\n");
    else
        printf("Sparx matrix\n");
}

int main()
{
    int row,column;
    printf("Enter row\n");
    scanf("%d",&row);
    printf("Enter column\n");
    scanf("%d",&column);
    int **matrix=malloc(row*sizeof(int*));
    if(matrix==NULL)
    {
        printf("Memory allocation failed");
        return 1;
    }
    for(int i=0;i<row;i++)
    {
        matrix[i]=malloc(column*sizeof(int));
    }
    printf("Enter matrix elements:\n");
    readMatrix(matrix,row,column);
    printf("Matrix is:\n");
    printMatrix(matrix,row,column);
    isSparxMatrix(matrix,row,column);
    for(int i=0;i<row;i++)
    {
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}
