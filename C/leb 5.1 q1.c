/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int main()
{
   int a,b;
   printf("enter a value of the first number:-");
   scanf("%d",&a);
   printf("enter a value of the second number:-");
   scanf("%d",&b);
   
   if(a<=b)
   {
       printf("the minimum value is:-%d",a);
   }
   else
   {
      printf("the minimum value is:-%d",b);
   }
    return 0;
}
