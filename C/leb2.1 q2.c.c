 # include <stdio.h>

int main()
{
   int a;
   printf("enter number:-");
   scanf("%d",&a);
   int b = a*a;
    printf("----------");
    printf("\n|         |");
    printf("\n| %d*%d=%d|",a,a,b);
    printf("\n|         |");
    printf("\n----------");

    return 0;
}