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

void isArrangeMatrix(int **matrix,int row,int column)
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            for(int k=j;k<column;k++)
            {
                if(*(*(matrix+i)+j)>*(*(matrix+i)+k))
                {
                    int temp=*(*(matrix+i)+j);
                    *(*(matrix+i)+j)=*(*(matrix+i)+k);
                    *(*(matrix+i)+k)=temp;
                }
            }
        }
    }
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
    isArrangeMatrix(matrix,row,column);
    printf("Arranged Matrix is:\n");
    printMatrix(matrix,row,column);
    for(int i=0;i<row;i++)
    {
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}
