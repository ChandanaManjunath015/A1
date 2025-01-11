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

int exchangeRows(int **resultMatrix,int **matrix,int row,int column,int row1,int row2)
{
    
    
        for(int j=0;j<column;j++)
        {
          int temp=*(*(matrix+row1-1)+j);
          *(*(resultMatrix+row1-1)+j)=*(*(matrix+row2-1)+j);
          *(*(resultMatrix+row2-1)+j)=temp;
        }
    
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
    printf("Elements of matrix1\n");
    printMatrix(matrix,row,column);
    printf("Enter the rows to interchange\n");
    scanf("%d %d",&row1,&row2);
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
    exchangeRows(resultMatrix,matrix,row,column,row1,row2);
    printMatrix(resultMatrix,row,column);
    return 0;
}
