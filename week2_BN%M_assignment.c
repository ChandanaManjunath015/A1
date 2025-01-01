#include <stdio.h>

long long modularExponentiation(int base,int exponent,int modulus) 
{
    long long result=1; 
    long long baseModulus=base%modulus; 
    while(exponent>0) 
    {
        if(exponent%2==1) 
        {
            result=(result*baseModulus)%modulus;
        }
        exponent=exponent>>1; 
        baseModulus=(baseModulus*baseModulus)%modulus; 
    }
    return result;
}

int main() 
{
    int base,exponent,modulus;
    printf("Enter the base(B):");
    scanf("%d",&base);
    
    printf("Enter the exponent(N):");
    scanf("%d",&exponent);
    
    do 
    {
        printf("Enter the modulus(M > 1):");
        scanf("%d",&modulus);
        if(modulus<=1) 
        {
            printf("Invalid input.Modulus must be greater than 1.\n");
        }
    } while (modulus<=1);

    if(exponent < 0) 
    {
        printf("Exponent must be a non-negative .\n");
        return 1;
    }
    long long result = modularExponentiation(base,exponent,modulus);
    printf("Result: %lld\n", result);
    return 0;
}
