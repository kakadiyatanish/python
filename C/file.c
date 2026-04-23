#include <stdio.h>

int main()
{
    FILE *evenFile, *oddFile;
    
    evenFile = fopen("even_file.txt", "w");
    oddFile = fopen("odd_file.txt", "w");
    
    if (evenFile == NULL || oddFile == NULL) 
    {
        printf("Error opening files!\n");
        return 1;
    }
    
    for (int i = 50; i <= 70; i++)
    {
        if (i % 2 == 0)
        {
            fprintf(evenFile, "%d\n", i); 
        }    
        else
        {
            fprintf(oddFile, "%d\n", i);  
        }
    }
    
    fclose(evenFile);
    fclose(oddFile);
    
    printf("files successfully.\n");
    return 0;
}
--------------------------------------------------------------------

#include <stdio.h>

struct Student 
{
    int roll_no;
    char name[50];
    float chem_marks;
    float maths_marks;
    float phy_marks;
    float percentage;
    float total;
};

int main() 
{
    struct Student students[5];
    int i;

    // Input student details
    for (i = 0; i < 5; i++) 
    {
        printf("\nEnter details for Student %d\n", i + 1);
        printf("Roll Number: ");
        scanf("%d", &students[i].roll_no);

        printf("Name: ");
        scanf(" %[^\n]", students[i].name);  

        printf("Chemistry Marks (out of 100): ");
        scanf("%f", &students[i].chem_marks);

        printf("Mathematics Marks (out of 100): ");
        scanf("%f", &students[i].maths_marks);

        printf("Physics Marks (out of 100): ");
        scanf("%f", &students[i].phy_marks);

        students[i].total = students[i].chem_marks + students[i].maths_marks + students[i].phy_marks;
        students[i].percentage = students[i].total / 3;
    }

    printf("\n--------- Student Mark Sheets ---------\n");
    printf("Roll No\tName\t\tChem\tMaths\tPhysics\tTotal\tPercentage\n");

    for (i = 0; i < 5; i++)
    {
        printf("%d\t%-15s%.2f\t%.2f\t%.2f\t%.2f\t%.2f%%\n",
               students[i].roll_no,
               students[i].name,
               students[i].chem_marks,
               students[i].maths_marks,
               students[i].phy_marks,
               students[i].total,
               students[i].percentage);
    }

    return 0;
}