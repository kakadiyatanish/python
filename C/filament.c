#include<stdio.h>

int main()
{
    char str[100];
    int l=0 ,f=1;
    
    printf("enter any string: ");
    scanf("%s",str);
    
    for(int i = 0;str[i]!='\0';i++)
    {
        l++;
    }
    
    for(int i=0;i<l/2;i++)
    {
        if(str[i]!=str[l-i-1])
        {
            f=0;
        }
    }
    
    if(f)
    {
        printf("the given string is a palindrome. \n");
    }
    else
    {
        printf("not palindrome.");
    }
    
    return 0;
}

---------------------------------------------------------------------------

#include<stdio.h>
#include <string.h>

int main()
{
    char str[100];
    int frequency[256]={0};
    
    printf("enter any string: ");
    fgets(str,sizeof(str),stdin);
    // scanf("%s",str);
    
    for(int i = 0;str[i]!='\0';i++)
    {
        frequency[(int)str[i]]++;
    }
    
    // printf("\ncharacter frequencies:\n");
    for(int i=0;i<256;i++)
    {
        if(frequency[i]>0)
        {
            printf("'%c' = %d\n",i,frequency[i]);
        }
    }
    return 0;
}



