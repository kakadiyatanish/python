#include<stdio.h>

int main()
{
    char ch;
    printf("enter any character:");
    scanf("%c",&ch);
    
    ch = (ch>='A' && ch<='Z')?ch+32:ch;
    
    switch(ch)
    {
        case'a':
            printf("%c is a vowel.\n",ch);
            break;
            
        case'e':    
            printf("%c is a vowel.\n",ch);
            break;
            
        case'i':
            printf("%c is a vowel.\n",ch);
            break;
            
        case'o':
            printf("%c is a vowel.\n",ch);
            break;
            
        case'u':
            printf("%c is a vowel.\n",ch);
            break;
            
        default:
            if((ch>='a' && ch<='z'))
            {
                printf("%c is consonant.\n",ch);
            }
            else
            {
                printf("invalid character");
            }
            
    }
    
    return 0;
}

-------------------------------------------------------------------------------------


#include <stdio.h>

int main()
{
    int n,max;
    printf("enter the number of elements:");
    scanf("%d",&n);
    
int a[n];

  for (int i=0;i<n;i++)
  {
      scanf("%d",&a[i]);
  }
  
  max = a[0];

  for(int i=1;i<n;i++)
  {
      if(a[i]>max)
      {
          max = a[i];
      }
  }
  
    printf("the largest element is: %d\n",max);

    return 0;
}

-------------------------------------------------------------------------------------

#include <stdio.h>
int main() 
{
    char str[100];
    char reverser[100];
    int cnt = 0;
    printf("Enter your string : ");
    scanf("%99s",str);
    for(int i=0;i<100;i++)
    {
        int cvt = str[i];
        if (cvt>=65&&cvt<=122)
        {
            cnt++;
        }
        else
        {
            break;
        }
    }
    int temp = 0;
    for(int i = cnt;i>=0;i--)
    {   
        reverser[i]=str[temp];
        temp++;
    }
    for (int i = 0; i < cnt; i++) 
    {
        reverser[i] = str[cnt - i - 1];
    }
    reverser[cnt] = '\0';
    for (int i=0;i<cnt;i++)
    {    int a = str[i];
         int b = reverser[i];
         int c = a-b;
        
        printf("%c",reverser[i]);
    }
    return 0;
}


-------------------------------------------------------------------------------------

#include <stdio.h>

int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];  
    int *ptr = a;  

    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Squares of elements: ");
    for (int i = 0; i < n; i++)
        printf("%d ", (*(ptr + i)) * (*(ptr + i)));   

    printf("\n");
    return 0;
}

-------------------------------------------------------------------------------------

#include <stdio.h>

struct car 
{
    char name[50];
    int year;
    int avrege;
    char color[50];  
    int price;
};

int main() 
{
    int N, i;

    printf("Enter the number of cars: ");
    scanf("%d", &N);

    
    struct car car[N];

    
    for (i = 0; i < N; i++) 
    {
        printf("\nEnter details for car %d:\n", i + 1);
        
        printf("name: ");
        scanf(" %[^\n]s", car[i].name); 
        
        printf("Year: ");
        scanf("%d", &car[i].year);
        
        printf("Average (mileage): ");
        scanf("%d", &car[i].avrege);
        
        printf("Color: ");
        scanf(" %[^\n]s", car[i].color);  
        
        printf("Price of the car: ");
        scanf("%d", &car[i].price);
    }

    printf("\n--- Car Details ---\n");
    for (i = 0; i < N; i++) 
    {
        printf("\nCar %d:\n", i + 1);
        printf("name: %s\n", car[i].name);
        printf("Year: %d\n", car[i].year);
        printf("Average mileage: %d\n", car[i].avrege);
        printf("Color: %s\n", car[i].color);
        printf("Price: %d\n", car[i].price);
    }

    return 0;
}

-------------------------------------------------------------------------------------

#include <stdio.h>

struct Student 
{
    char name[100];
    char course[100];
};

int main() 
{
    struct Student students[3];
    FILE *file = fopen("data.txt", "w");

    if (file == NULL) 
    {
        printf("Error opening file!\n");
        return 1;
    }

    for (int i = 0; i < 3; i++) 
    {
        printf("Enter student %d's name and course: ", i + 1);
        scanf("%s", students[i].name);
        scanf("%s",students[i].course);
        fprintf(file, "Name: %s, Course: %s\n", students[i].name, students[i].course);
    }

    fclose(file);
    printf("Data successfully written \n");
    return 0;
}

-------------------------------------------------------------------------------------

#include <stdio.h>

int main()
{

for (int i = 1; i <=4; i++) 
    {
        for (int j = 1; j <= 4; j++)
        {
            if(j<=i)
            {
            printf("%d ", i * i);
            }
        }    
        printf("\n");
    }

    return 0;
}

-------------------------------------------------------------------------------------