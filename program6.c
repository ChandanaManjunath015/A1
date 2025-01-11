// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

void readMatrix(int *matrix,int row,int column)
{
    for(int i=0;i<row;i++)
    {
        for (int j=0;j<column;j++)
        {
            scanf("%d",matrix+i*column+j);
        }
    }
}

void printMatrix(int *matrix,int row,int column)
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            printf("%d",*(matrix+i*column+j));
        }
        printf("\n");
    }
}

void  addMatrix(int *resultMatrix,int *matrix1,int *matrix2,int row,int column)
{
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            *(resultMatrix+i*column+j)=*(matrix1+i*column+j)+*(matrix2+i*column+j);
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
    int *matrix1=malloc(row*column*sizeof(int*));
    int *matrix2=malloc(row*column*sizeof(int*));
    int *resultMatrix=malloc(row*column*sizeof(int*));
    printf("Type elements of matrix1\n");
    readMatrix(matrix1,row,column);
    printf("Type elements of matrix2\n");
    readMatrix(matrix2,row,column);
    printf("Elements of matrix1\n");
    printMatrix(matrix1,row,column);
    printf("Elements of matrix2\n");
    printMatrix(matrix2,row,column);
    addMatrix(resultMatrix,matrix1,matrix2,row,column);
    printf("Elements of result matrix\n");
    printMatrix(resultMatrix,row,column);
    return 0;
}
