#include <stdio.h>
#include <stdbool.h>
#include <mem.h>
#include <stdlib.h>

struct student{
    char Name [30];
    long long int StudentId;
    float MidtermGrade;
    float FinalGrade;
    float CourseGrade;
    bool Fail_Pass_Status;
};
void Menu(){
    printf("                ---MENU---                   \n");
    printf("For Add a new record please press 'a' or 'A'.\n");
    printf("For Find a new record please press 'f' or 'F'.\n");
    printf("For Show basic statistics please press 's' or 'S'.\n");
    printf("For Exit to program please press 'q' or 'Q'.\n");
    printf("Your choice :");
}

int main() {
    printf("Program name: MyRepo6\n");
    printf("By Egemen Bahtiyar 182010010070\n");
    printf("My program is simple grade calculator for a set of students together with statistics and search functions.\n");
    printf("To run the program, you need to write a,f,s or q letters expression to the input.\n");
    printf("If you chose the letter a, enter the student's name, student's id, midterm grade, final grade one by one.\n");
    printf("If you choose the letter f, you must enter the number of the student you want to find.\n");
    printf("If you choose the letter q, you will exit the program.\n");
    printf("If you select the letter S, it will show you the average grade,number of students and \n");
    printf("Who passed and which one failed in the system.\n");

    struct student students[250];
    int i=0;
    Menu();
    do {
        char choose[250];
        gets(choose);
        if (*choose=='a' || *choose=='A'){
            printf("Please enter student name\n");
            gets(students[i].Name);
            printf("Please enter student id\n");
            scanf("%lld",&students[i].StudentId);
            printf("Please enter midterm grade\n");
            scanf("%f",&students[i].MidtermGrade);
            printf("Please enter final grade\n");
            scanf("%f",&students[i].FinalGrade);
            students[i].CourseGrade = (students[i].MidtermGrade*0.4)+(students[i].FinalGrade*0.6);
            if (students[i].CourseGrade>60){
                students[i].Fail_Pass_Status=true;
                i++;
            }
            else{
                students[i].Fail_Pass_Status=false;
                i++;
            }
            memset(choose,0,i);
            Menu();
        }
        else if (*choose=='f'||*choose=='F'){
            printf("Enter a student id:\n");
            long long int studentId;
            int ControlStudent=0;
            scanf("%lld",&studentId);
            for (int j = 0; j < i; ++j) {
                if (studentId== students[j].StudentId){
                    printf("Student's name: %s\nStudent's id: %lld\nStudent's midterm grade: %.2f\n",students[j].Name,students[j].StudentId,students[j].MidtermGrade);
                    printf("Student's final grade: %.2f\nStudent's course grade: %.2f\nStatus: ",students[j].FinalGrade,students[j].CourseGrade);
                    if (students[j].Fail_Pass_Status){
                        printf("Passed.\n");
                        ControlStudent++;
                    }
                    else{
                        printf("Failed.\n");
                        ControlStudent++;
                    }
                }
            }
            if (ControlStudent==0){
                printf("No student with such number was found.\n");
            }
            memset(choose,0,i);
            Menu();
        }
        else if (*choose=='s'||*choose=='S'){
            if (i==0){
                printf("There are no students enrolled.\n");
                memset(choose,0,i);
                Menu();
            }
            if (i>0){
                int CountPassed = 0;
                int CountFailed = 0;
                int TotalPoint=0;
                int AveragePoint;
                for (int j = 0; j < i; ++j) {
                    if (students[j].Fail_Pass_Status==true){
                        CountPassed++;
                    }
                    if (students[j].Fail_Pass_Status==false){
                        CountFailed++;
                    }
                }
                for (int j = 0; j < i; ++j) {
                    TotalPoint+= students[j].CourseGrade;
                }
                AveragePoint = TotalPoint/i;
                printf("Number of passed students:%d\n",CountPassed);
                printf("Number of failed students:%d\n",CountFailed);
                printf("Average course grade:%d\n",AveragePoint);
                printf("Number of students:%d\n",i);
                memset(choose,0,i);
                Menu();
            }
        }
        else if (*choose=='q'||*choose=='Q'){
            printf("Exiting..");
            exit(0);
        }
    } while (1);
    return 0;
}
