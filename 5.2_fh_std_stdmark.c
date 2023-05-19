#include <stdio.h>
#include <string.h>
typedef struct
{
        int        roll;
        char   name[10];
        char  branch[10];
        int         sem;
        char     sec[1];
        int        sub1;
        int        sub2;
        int        sub3;
}student;

student input()
{
        student st1;
        printf("Student name: ");
        scanf("%s",st1.name);
        printf("Roll No: ");
        scanf("%d",&st1.roll);
        printf("Branch: ");
        scanf("%s",st1.branch);
        printf("Semester: ");
        scanf("%d",&st1.sem);
        printf("Section: ");
        scanf("%s",st1.sec);
        printf("Marks for Sub1\n");
        scanf("%d",&st1.sub1);
        printf("Marks for Sub2\n");
        scanf("%d",&st1.sub2);
        printf("Marks for Sub3\n");
        scanf("%d",&st1.sub3);
        return st1;
}

int main()
{
        FILE * f1 = fopen("student.txt","a");
        FILE * f2 = fopen("marks.txt","a");
        FILE * f3 = fopen("student_Info.txt","a");
        if(f1==NULL ||f2==NULL||f3==NULL)
        {
                printf("File not found");
                return 1;
        }
        student s;
        s = input();
        fprintf(f1,"%d\t%s\t%s\t%d\t%s\n",s.roll,s.name,s.branch,s.sem,s.sec);
        fprintf(f2,"%s\t%d\t%d\t%d\n",s.name,s.sub1,s.sub2,s.sub3);
        fprintf(f3,"%d\t%s\t%s\t%d\t%s\t%d\t%d\t%d\n",s.roll,s.name,s.branch,s.sem,s.sec,s.sub1,s.sub2,s.sub3);
        return 0;
}
