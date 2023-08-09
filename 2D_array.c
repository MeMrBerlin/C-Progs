// this programme shows number of students and their numbers of 3 subjects
#include <stdio.h>
int main()
{
    int marks[2][3];
    int n_student = 2, n_number = 3;
    // printf("Enter the number of student %d\n");
    // scanf("%d", &n_student);
    // printf("Enter the number in subject of student %d\n");
    // scanf("%d", &n_number);
    // for (int i = 0; i < n_student; i++)
    //{
    //  printf("The number of student: %d\n", i + 1);
    // for (int j = 0; j < n_number; j++)
    //{
    //  printf("The number in subject of student: %d\n", j + 1);
    //}
    // }
    for (int i = 0; i < n_student; i++)
    {
        for (int j = 0; j < n_number; j++)
        {
            printf("The number of student %d and their marks %d\n", i + 1, j + 1);
            scanf("%d", &marks[i][j]);
        }
    }
    for (int i = 0; i < n_student; i++)
    {
        for (int j = 0; j < n_number; j++)
        {
            printf("The number of student %d and their marks %d\n", i + 1, j + 1, marks[i][j]);
            
        }
    }
    return 0;
}