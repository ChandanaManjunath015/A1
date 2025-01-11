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

void  isIdentical(int **matrix1,int **matrix2,int row,int column)
{
    int flag=1;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            if(*(*(matrix1+i)+j)!=*(*(matrix2+i)+j))
            {
                flag=0;
                break;
            }
        }
        if(flag==0)
        break;
    }
    if(flag==0)
    {
        printf("Not identical\n");
    }
    else
    {
        printf("Identical\n");
    }
    
}

int main() 
{
    int row,column;
    printf("Enter row\n");
    scanf("%d",&row);
    printf("Enter column\n");
    scanf("%d",&column);
    int **matrix1=malloc(row*sizeof(int*));
    for(int i=0;i<row;i++)
    {
        matrix1[i]=malloc(column*sizeof(int*));
    }
     int **matrix2=malloc(row*sizeof(int*));
    for(int i=0;i<row;i++)
    {
        matrix2[i]=malloc(column*sizeof(int*));
    }
    printf("Type elements of matrix1\n");
    readMatrix(matrix1,row,column);
    printf("Type elements of matrix2\n");
    readMatrix(matrix2,row,column);
    printf("Elements of matrix1\n");
    printMatrix(matrix1,row,column);
    printf("Elements of matrix2\n");
    printMatrix(matrix2,row,column);
    isIdentical(matrix1,matrix2,row,column);
    return 0;
}
