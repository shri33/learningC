#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100
#define MAX_COURSES 5

struct student
{
    int id;
    char name[50];
    char courses[MAX_COURSES][20];
    int numCourses;
};

// Function to swap two students for sorting
void swap(struct student *a, struct student *b)
{
    struct student temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform Selection Sort based on student names
void selectionSort(struct student st[], int n)
{
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++)
    {
        min_idx = i;
        for (j = i + 1; j < n; j++)
        {
            if (strcmp(st[j].name, st[min_idx].name) < 0)
                min_idx = j;
        }
        if (min_idx != i)
            swap(&st[i], &st[min_idx]);
    }
}

int main()
{
    int n, i, j, in, sid, found = 0;
    char course[20], name[50];
    printf("Enter the number of students: ");
    scanf("%d", &n);
    struct student st[MAX_STUDENTS];

    // Read details of the students into the corresponding student variables
    for (i = 0; i < n; i++)
    {
        printf("Enter Student ID: ");
        scanf("%d", &st[i].id);
        printf("Enter Name of the Student: ");
        scanf("%s", st[i].name);
        printf("Enter the number of courses registered for student %s (up to %d): ", st[i].name, MAX_COURSES);
        scanf("%d", &st[i].numCourses);
        printf("Enter the courses registered for student %s:\n", st[i].name);
        for (j = 0; j < st[i].numCourses; j++)
        {
            scanf("%s", st[i].courses[j]);
        }
    }

    while (1)
    {
        printf("\nMENU\n1. Find students registered in a course\n2. Print students in alphabetical order\n3. Find a student by ID\n4. Exit\n");
        scanf("%d", &in);

        switch (in)
        {
        case 1:
            printf("Enter a course to search: ");
            scanf("%s", course);
            printf("The students registered in the course %s are:\n", course);
            for (i = 0; i < n; i++)
            {
                for (j = 0; j < st[i].numCourses; j++)
                {
                    if (strcmp(st[i].courses[j], course) == 0)
                    {
                        printf("%s\n", st[i].name);
                        break;
                    }
                }
            }
            break;

        case 2:
            // Sort students in alphabetical order and print their names
            selectionSort(st, n);
            printf("The students in alphabetical order are:\n");
            for (i = 0; i < n; i++)
            {
                printf("%s\n", st[i].name);
            }
            break;

        case 3:
            printf("Enter a Student ID to search: ");
            scanf("%d", &sid);
            found = 0;
            for (i = 0; i < n; i++)
            {
                if (st[i].id == sid)
                {
                    printf("%s\n", st[i].name);
                    for (j = 0; j < st[i].numCourses; j++)
                    {
                        printf("%s\n", st[i].courses[j]);
                    }
                    found = 1;
                    break;
                }
            }
            if (!found)
                printf("Student with ID %d not found\n", sid);
            break;

        case 4:
            printf("Exiting...\n");
            return 0;

        default:
            printf("Invalid input\n");
            break;
        }
    }
}
