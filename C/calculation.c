#include<stdio.h>

int add(int a , int b)
{
    return a + b;
}

int sub(int a , int b) 
{
    return a - b;
}

int multi(int a , int b) 
{
    return a * b;
}

int division(int a , int b) 
{
    if (b != 0) 
    {
        return a / b;
    } else 
    {
        printf("Error: Division by zero\n");
        return 0;  
    }
}

int modulo(int a , int b)
{
    if (b != 0) 
    {
        return a % b;
    } else {
        printf("Error: Division by zero\n");
        return 0;  
    }
}

int calculation() 
{
    int choice;
    int x, y;
    int d;

    while (1) 
    {  
        printf("Press 1 for addition\n");
        printf("Press 2 for subtraction\n");
        printf("Press 3 for multiplication\n");
        printf("Press 4 for division\n");
        printf("Press 5 for modulo\n");
        printf("Press 0 to exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 0) 
        {
            return 0;   
        }

        printf("Enter the first number: ");
        scanf("%d", &x);

        printf("Enter the second number: ");
        scanf("%d", &y);

        switch (choice) {
            case 1:
                d = add(x, y);
                printf("Addition of %d and %d is %d\n", x, y, d);
                break;
            case 2:
                d = sub(x, y);
                printf("Subtraction of %d and %d is %d\n", x, y, d);
                break;
            case 3:
                d = multi(x, y);
                printf("Multiplication of %d and %d is %d\n", x, y, d);
                break;
            case 4:
                d = division(x, y);
                printf("Division of %d and %d is %d\n", x, y, d);
                break;
            case 5:
                d = modulo(x, y);
                printf("Modulo of %d and %d is %d\n", x, y, d);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}

int main() {
    calculation();  
    return 0;
}
