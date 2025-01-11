#include <stdio.h>
#include <stdlib.h>

void readMatrix(int **matrix,int row,int column)
{
    for(int i=0;i<row;i++)
    {
        for (int j=0;j<column;j++)
        {
            scanf("%d",(*(matrix+i)+j));
        }
    }
}

void printMatrix(int **matrix,int row,int column)
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            printf("%d",*(*(matrix+i)+j));
        }
        printf("\n");
    }
}

void evenFrequency(int **matrix,int row,int column)
{
    int evenfrequency=0;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            if((*(*(matrix+i)+j)%2)==0)
            {
                evenfrequency++;
            }
        }
    }
    printf("Number of even elements:%d",evenfrequency);
}

int main() 
{
    int row,column,row1,row2;
    printf("Enter row\n");
    scanf("%d",&row);
    printf("Enter column\n");
    scanf("%d",&column);
    int **matrix=malloc(row*sizeof(int*));
    for(int i=0;i<row;i++)
    {
        matrix[i]=malloc(column*sizeof(int*));
    }
    printf("Type elements of matrix1\n");
    readMatrix(matrix,row,column);
    printf("Elements of matrix\n");
    printMatrix(matrix,row,column);
    evenFrequency(matrix,row,column);
    for(int i=0;i<row;i++)
    {
        free(matrix[i]);
    }
    free(matrix);
    return 0;
}
