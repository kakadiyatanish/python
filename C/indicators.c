#include <stdio.h>
#include <string.h>

int stringLength(char *ptr)
{
    int length = 0;
    while (*ptr != '\0') 
    {
        length++;
        ptr++; 
    }
    return length;
}

int main() 
{
    char str[100];  

    printf("Enter any string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    printf("The length of the string is: %d\n", stringLength(str));

    return 0;
}

--------------------------------------------------------------------------------------------------------------

#include <stdio.h>

int cube(int num) 
{
    return num * num * num;
}

int main() 
{
    int rows, cols;
    printf("Enter the rows and columns of the 2D array: ");
    scanf("%d %d", &rows, &cols);

    int array[rows][cols];
    printf("Enter the elements of the 2D array:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &array[i][j]);
        }
    }

    printf("Cubes of the elements in the 2D array:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", cube(array[i][j]));
        }
        printf("\n");
    }

    return 0;
}