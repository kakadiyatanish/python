
#include <stdio.h>

int main()
{
    int n,num=0;
    printf("enter array size:");
    scanf("%d",&n);
    
int a[n];

  for (int i=0;i<n;i++)
  {
      scanf("%d",&a[i]);
  }
  
  
  printf("negative number:");

  for (int i=0;i<n;i++)
  {
      if(a[i]<0)
      {
      printf("%d",a[i]);
      }
      else
      {
          printf(" ");
      }
  }
 
  return 0;
}


--------------------------------------------------------------------

#include <stdio.h>

int main() 
{
    int row,column,n=0;
    int d=0;
    int b=0 , c;
    printf("enter the array row size:");
    scanf("%d",&row);
    printf("enter the array column size:");
    scanf("%d",&column);
    
    int a [row][column];

    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            printf("please enter value a[%d][%d]:",i,j);
            scanf("%d",&a[i][j]);

        }
        
    }
    
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
           d=a[i][j];
           if(b>=d)
            {
                c=b;
            }
            else
            {
                c=d;
            }
        }
        
    }
    printf("the largest element:- %d \n ",c);

        return 0;
}

--------------------------------------------------------------------

#include <stdio.h>

int main() 
{
    int row,column,n=0;
    printf("enter the array row size:");
    scanf("%d",&row);
    printf("enter the array column size:");
    scanf("%d",&column);
    
    int a [row][column];

    for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            printf("please enter value a[%d][%d]:",i,j);
            scanf("%d",&a[i][j]);
        }
        
        // printf("\n");
    }
    
     for(int i=0;i<row;i++)
    {
        for(int j=0;j<column;j++)
        {
            printf("%d",a[j][i]);
        }
        printf("\n");
    }
    return 0;
}

--------------------------------------------------------------------

#include <stdio.h>

int main() 
{
    int row, column, sum = 0;
    int choice;

    printf("Enter number of rows: ");
    scanf("%d", &row);
    printf("Enter number of columns: ");
    scanf("%d", &column);
    
    int a[row][column]; 
    for (int i = 0; i < row; i++) 
    {
        for (int j = 0; j < column; j++) 
        {
            printf("a[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    
    printf("Enter 1 for row sum, 0 for column sum: ");
    scanf("%d", &choice);

    if (choice == 1) 
    {
        int r;
        printf("Enter row number: ");
        scanf("%d", &r);
        
        if (r >= 0 && r < row) 
        {  
            sum = 0;  
            printf("Elements in row %d: ", r);
            
            for (int j = 0; j < column; j++) 
            {
                printf("%d, ", a[r][j]);
                sum += a[r][j];
            }
            printf("\nSum of row %d is: %d\n", r, sum);
        } else {
            printf("Invalid row number\n");
        }
    } else if (choice == 0) {
        int c;
        printf("Enter column number: ");
        scanf("%d", &c);
        
        if (c >= 0 && c < column) 
        {  
            sum = 0;  
            printf("Elements in column %d: ", c);
            for (int i = 0; i < row; i++) 
            {
                printf("%d, ", a[i][c]);
                sum += a[i][c];
            }
            printf("\nSum of column %d is: %d\n", c, sum);
        } else 
        {
            printf("Invalid column number\n");
        }
    } else {
        printf("Invalid choice\n");
    }

    return 0;
}
