#include <iostream>
#include <fstream>
using namespace std;

typedef struct
{
        int        roll;
        string   name;
        string  branch;
        int         sem;
        string     sec;
        int        sub1;
        int        sub2;
        int        sub3;
}student;

student input()
{
        student st1;
        printf("Student name: ");
        cin>>st1.name;
        printf("Roll No: ");
        cin>>st1.roll;
        printf("Branch: ");
        cin>>st1.branch;
        printf("Semester: ");
        cin>>st1.sem;
        printf("Section: ");
        cin>>st1.sec;
        printf("Marks for Sub1\n");
        cin>>st1.sub1;
        printf("Marks for Sub2\n");
        cin>>st1.sub2;
        printf("Marks for Sub3\n");
        cin>>st1.sub3;
        return st1;
}

int main(){
        student s;
        s = input();
        try
        {
        FILE * f1 = fopen("student.txt","a");
        FILE * f2 = fopen("marks.txt","a");
        FILE * f3 = fopen("student_Info.txt","a");
        student s;
        s = input();
        fprintf(f1,"%d\t%s\t%s\t%d\t%s\n",s.roll,s.name,s.branch,s.sem,s.sec);
        fprintf(f2,"%s\t%d\t%d\t%d\n",s.name,s.sub1,s.sub2,s.sub3);
        fprintf(f3,"%d\t%s\t%s\t%d\t%s\t%d\t%d\t%d\n",s.roll,s.name,s.branch,s.sem,s.sec,s.sub1,s.sub2,s.sub3);
        }
        catch(...)
        {}
        return 0;
}


