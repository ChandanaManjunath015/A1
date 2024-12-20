#include <stdio.h>
#include <stdlib.h>
int isDigit(char c) 
{
    return c >= '0' && c <= '9';
}
int stringLength(char* str)
 {
    int length = 0;
    while (str[length] != '\0') 
    {
        length++;
    }
    return length;
}
int stringCompare(char* str1, char* str2) 
{
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') 
    {
        if (str1[i] != str2[i]) 
        {
            return 0; 
        }
        i++;
    }
    return str1[i] == str2[i];  
}
void removeNewline(char* str) 
{
    int len = stringLength(str);
    if (str[len - 1] == '\n') 
    {
        str[len - 1] = '\0';
    }
}
int processExpression(char* expression, char* processedExpression) 
{
    int len = stringLength(expression);
    int endOp = 1; 
    int j = 0;
    int invalid = 0;  
    for (int i = 0; i < len; i++) 
    {
        if (expression[i] == ' ') 
        {
            continue; 
        } 
        else if (isDigit(expression[i])) 
        {
            processedExpression[j++] = expression[i];
            endOp = 0;
        } 
        else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') 
        {
            if (endOp) 
            {
                invalid = 1;
                break;  
            }
            processedExpression[j++] = expression[i];
            endOp = 1;
        }
        else 
        {
            invalid = 1;
            break; 
        }
    }
    processedExpression[j] = '\0';
    if (endOp || invalid) 
    {
        return 1; 
    }
    return 0; 
}
int evaluateExpression(char* processedExpression) 
{
    int temp = 0;
    int result = 0;
    char op = '+';
    int num = 0;
    char prevOp = '+';
    int len = stringLength(processedExpression);
    int errorOccurred = 0; 
    for (int i = 0; i <= len; i++) 
    {
        if (isDigit(processedExpression[i])) 
        {
            num = num * 10 + (processedExpression[i] - '0');
        } 
        else if (processedExpression[i] == '+' || processedExpression[i] == '-' || processedExpression[i] == '*' || processedExpression[i] == '/' || processedExpression[i] == '\0')
        {
            if (op == '*') 
            {
                temp = temp * num;
            } 
            else if (op == '/') 
            {
                if (num == 0) 
                {
                    printf("Error: Division by zero.\n");
                    errorOccurred = 1;
                    break; 
                }
                temp = temp / num;
            }
            else
            {
                if (prevOp == '+') 
                {
                    result = result + temp;
                } 
                else if (prevOp == '-') 
                {
                    result = result - temp;
                }
                temp = num;
                prevOp = op;
            }
            op = processedExpression[i];
            num = 0;
        }
    }
    if (errorOccurred) 
    {
        return -1;  
    }
    if (prevOp == '+') 
    {
        result = result + temp;
    } 
    else if (prevOp == '-') 
    {
        result = result - temp;
    }
    return result;
}
int main() 
{
    char expression[100];  
    int continueRunning = 1;  

    while (continueRunning) 
    {
        printf("Enter your expression (or type 'exit' to quit):\n");
        int i = 0;
        char ch;
        while ((ch = getchar()) != '\n' && ch != EOF) 
        {
            expression[i++] = ch;
        }
        expression[i] = '\0';
        if (stringCompare(expression, "exit") == 1) 
        {
            continueRunning = 0; 
            break;
        }
        char processedExpression[100] = {0};
        if (processExpression(expression, processedExpression)) 
        {
            printf("Error: Invalid expression.\n");
            continue;  
        }
        int result = evaluateExpression(processedExpression);
        if (result == -1) 
        {
            continue; 
        }
        printf("Result: %d\n", result);
    }
    return 0;
}
