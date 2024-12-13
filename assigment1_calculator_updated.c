#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char a[100];
    printf("Enter your expression\n");
    fgets(a, sizeof(a), stdin);

    int len = strlen(a);
    char processed[100] = {0};
    int end_op = 1;
    int j=0;
    for (int i=0;i<len;i++)
    {
        if (isspace(a[i]))
        {
            continue;
        }
        else if(isdigit(a[i]))
        {
            processed[j++] = a[i];
            end_op= 0;
        }
        else if (a[i] == '+'|| a[i]=='-'||a[i]=='*'||a[i]=='/')
        {
            if (end_op)
            {
              printf("Error: Invalid expression.\n");
              return 1;
            }
            processed[j++] = a[i];
            end_op= 1;
        }


        else
        {

            printf("Error: Invalid expression.\n");
            return 1;
        }
    }



    if (end_op)
    {

        printf("Error: Invalid expression.\n");
        return 1;
    }

    processed[j] = '\0';


    int temp = 0;
    int res = 0;
    char op = '+';
    int num = 0;
    char prev_op = '+';

    len = strlen(processed);
    for (int i = 0; i <= len; i++)
    {
        if (isdigit(processed[i]))
        {
            num=num*10+(processed[i]-'0');
        }
        else if (processed[i]=='+'||processed[i]=='-'||processed[i]=='*'||processed[i]=='/'||processed[i]=='\0')
        {

            if (op=='*')
            {
                temp=temp*num;
            }
            else if (op=='/')
            {
                if (num == 0)
                {
                    printf("Error: Division by zero.\n");
                    return 1;
                }
                temp=temp/num;
            }
            else
            {
                if (prev_op=='+')
                {
                    res=res+temp;
                }
                else if (prev_op=='-')
                {
                    res-= temp;
                }
                temp = num;
                prev_op = op;
            }


            op = processed[i];
            num = 0;
        }
    }


    if (prev_op=='+')
    {
        res=res+temp;
    }
    else if (prev_op=='-')
    {
        res=res-temp;
    }

    printf("%d\n",res);
    return 0;
}
