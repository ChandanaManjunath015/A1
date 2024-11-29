#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {

	
    char a[100];
    printf("Enter your expression\n");
    fgets(a, sizeof(a), stdin);

    int len = strlen(a);
    int cur = 0;
    int  res = 0;
    int temp = 0;
    char end_op = '+';
    int last=1;
    int i=0;
    while (i < len)
    {
        if(isspace(a[i]))
        {
            i++;
            continue;
        }

        if (isdigit(a[i]))
        {
            cur = 0;
	        last=0;
            while (a[i] >= '0' && a[i] <= '9' && i<len)
            {
                int d = a[i] - '0';
                cur = cur * 10 + d;

                i++;
            }
            if (end_op == '*')
            {
                temp = temp*cur;
            }


           else if (end_op == '/')
	        {
                if (cur == 0)
		        {

                    printf("Error: Division by zero.\n");
                    return 1;
                }
                temp = temp/cur;
            }
            else if (end_op == '+')
            {
                res = res+temp;
                temp = cur;
            }
            else if (end_op == '-')
            {
                res = res+temp;
                temp = -cur;
            }

        }
	    else if (a[i] == '+' || a[i] == '-' || a[i] == '*' || a[i] == '/')
	    {
		if(last)
        {
            printf("Error: Invalid expression.\n");
            return 1;
        }
        last=1;
        end_op = a[i];
        i++;
        }
        else
        {
            printf("Error: Invalid expression.\n");
            return 1;
        }
    }
    if(last)
    {
        printf("Error: Invalid expression.\n");
        return 1;
    }
    res=res+temp;

    printf("%d\n", res);
    return 0;
}
