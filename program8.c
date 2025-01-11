#include <stdio.h>
#include <stdlib.h>

void readMatrix(int **matrix,int size)
{
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            scanf("%d",(*(matrix+i)+j));
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

void isIdenticalMatrix(int **matrix,int size)
{
    int flag=1;
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            if(i==j&&(*(*(matrix+i)+j)==1))
            {
                flag=1;
            }
            else if(*(*(matrix+i)+j)==0)
            {
                flag=1;
            }
            else
            {
                flag=0;
                break;
            }
        }
        if(flag==0) break;
    }
    if(flag==1)
    {
        printf("Identical matrix\n");
    }
    else
    {
         printf("Non Identical matrix\n");
    }
}

int main() 
{
    int size;
    printf("Enter size\n");
    scanf("%d",&size);
    int **matrix=malloc(size*sizeof(int*));
    for(int i=0;i<size;i++)
    {
        matrix[i]=malloc(size*sizeof(int));
    }
    printf("Enter the elements of matrix\n");
    readMatrix(matrix,size);
    printf("The matrix is :\n");
    printMatrix(matrix,size);
    isIdenticalMatrix(matrix,size);
    free(matrix);
    return 0;
}
