/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int main()
{
    int p , r , n;
    printf("enter principal amount :- ");
    scanf("%d", &p);
    printf("enter rate amount :- ");
    scanf("%d", &r);
    printf("enter number of month amount :- ");
    scanf("%d", &n);
    
    float s  = (float)(p * r * n) / 100; ;
    printf("simple interest is :-%.2f ", s);
    return 0;
}