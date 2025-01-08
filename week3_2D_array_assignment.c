#include <stdio.h>
#include <stdlib.h>
#define MAX_ROWS 10
#define MAX_COLUMNS 101
#define MAX_NAME_LENGTH 50

int my_strlen(const char *str) 
{
    int length=0;
    while(str[length]!='\0') 
    {
        length++;
    }
    return length;
}

int my_isVowel(char character) 
{
    char lower=(character>='A' && character<='Z') ? (character+32): character;
    return (lower=='a' || lower=='e' || lower=='i' || lower=='o' || lower=='u');
}

int main() 
{
    int numberOfRows,numberOfColumns;
    int returnStatus=0; 
    printf("Enter number of rows(1-10):");
    scanf("%d",&numberOfRows);
    if(numberOfRows<1||numberOfRows>MAX_ROWS) 
    {
        printf("Invalid number of rows. Please enter a value between 1 and 10.\n");
        returnStatus=1;
    }
    else 
    {
        printf("Enter number of columns(1-100):");
        scanf("%d",&numberOfColumns);
        if(numberOfColumns<1||numberOfColumns>MAX_COLUMNS)
        {
            printf("Invalid number of columns. Please enter a value between 1 and 100.\n");
            returnStatus=1;
        } 
        else 
        {
            char nameArray[MAX_ROWS][MAX_COLUMNS][MAX_NAME_LENGTH];
            printf("Enter the names:\n");
            for(int rowIndex=0;rowIndex<numberOfRows;rowIndex++)
            {
                for(int columnIndex=0;columnIndex<numberOfColumns;columnIndex++)
                {
                    printf("Name at (%d,%d):",rowIndex,columnIndex);
                    scanf("%s",nameArray[rowIndex][columnIndex]);
                }
            }
            printf("\nThe 2D array of names is:\n");
            for(int rowIndex=0;rowIndex<numberOfRows;rowIndex++)
            {
                for(int columnIndex=0;columnIndex<numberOfColumns;columnIndex++)
                {
                    printf("%-10s",nameArray[rowIndex][columnIndex]);
                }
                printf("\n");
            }
            int vowelStartingNameCount=0;
            char longestName[MAX_NAME_LENGTH]="";
            for(int rowIndex=0;rowIndex<numberOfRows;rowIndex++)
            {
                for(int columnIndex=0;columnIndex<numberOfColumns;columnIndex++)
                {
                    if(my_isVowel(nameArray[rowIndex][columnIndex][0]))
                    {
                        vowelStartingNameCount++;
                    }
                    if(my_strlen(nameArray[rowIndex][columnIndex])>my_strlen(longestName)) 
                    {
                        for(int i=0;i<=my_strlen(nameArray[rowIndex][columnIndex]);i++) 
                        {
                            longestName[i]=nameArray[rowIndex][columnIndex][i];
                        }
                    }
                }
            }
            printf("\nNumber of names starting with a vowel: %d\n",vowelStartingNameCount);
            printf("The longest name: %s\n",longestName);
        }
    }
    return returnStatus;
}
