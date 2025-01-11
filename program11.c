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

int exchangeRows(int **resultMatrix,int **matrix,int row,int column,int col1,int col2)
{
    for(int i=0;i<row;i++)
        {
          int temp=*(*(matrix+i)+col1-1);
          *(*(resultMatrix+i)+col1-1)=*(*(matrix+i)+col2-1);
          *(*(resultMatrix+i)+col2-1)=temp;
        }
    
}

int main() 
{
    int row,column,col1,col2;
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
    printf("Elements of matrix1\n");
    printMatrix(matrix,row,column);
    printf("Enter the columns to interchange\n");
    scanf("%d %d",&col1,&col2);
    int **resultMatrix=malloc(row*sizeof(int*));
    for(int i=0;i<row;i++)
    {
        resultMatrix[i]=malloc(column*sizeof(int*));
    }
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            *(*(resultMatrix+i)+j)=*(*(matrix+i)+j);
        }
    }
    exchangeRows(resultMatrix,matrix,row,column,col1,col2);
    printMatrix(resultMatrix,row,column);
    for(int i=0;i<row;i++)
    {
        free(matrix[i]);
    }
    free(matrix);
    for(int i=0;i<row;i++)
    {
        free(resultMatrix[i]);
    }
    free(resultMatrix);
    
    return 0;
}
