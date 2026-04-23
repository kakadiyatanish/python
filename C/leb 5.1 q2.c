/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int main()
{
   int a;
   printf("enter any number:-");
   scanf("%d",&a);
  
   if(0<a)
   {
       printf("the number is positive:-%d",a);
   }
   else if(0>a)
   {
      printf("the number is negative:-%d",a);
   }
   else
   {
       printf("the number is 0");
   }
    return 0;
}
