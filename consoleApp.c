#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const char SUBJECT_1[10] = "MAT123";
const char SUBJECT_2[10] = "AMT456";
const char SUBJECT_3[10] = "CSC789";
const char SUBJECT_4[10] = "STAT012";
const char SUBJECT_5[10] = "PHY345";

struct studentAttendance
{
    char indexNumber[10];
    char subjectCode[10];
    int noOfWeeks;
    int attendanceCount;
    float percentage;
}finalAttendance;

struct studentData
{
    char indexNumber[10];
    char name[50];
    int contactNumber;
    char emailAddress[50];
    char enrolledSubject[50];
}student;

void login(char [], char[], char []);
int confirmIndexNumber(char indexNo[]);
void selectMenu(char indexNo[],char subjectCode[]);         //select the relevant menu according to the index number.
void displayLecturerMenu(char indexNo[],char subjectCode[]);
void displayStudentMenu(char indexNo[],char subjectCode[]);
void displayAdminMenu(char indexNo[],char subjectCode[]);
int searchIndexNumber(char indexNo[]);        //check whether the inserted index number exists.
void insertData(char []);
void markAttendance();
void calculatePercentage(char [], char []);
void searchRecords(char indexNo[]);
void editRecords(char indexNo[]);
void deleteRecords(char indexNo[]);
void viewEligibility(char indexNo[], char subjectCode[]);
void ext();


int main()
{
    char indexNo[10];
    char password[10];
    char subjectCode[10];

    login(indexNo,password,subjectCode);

    return 0;

}

void login(char indexNo[], char password[],char subjectCode[])
{
    printf("\n\n\t\t\t\t\xDD\xDD STUDENT ATTENDANCE RECORDING SYSTEM \xDD\xDD\n\n\n");

    int correctIndex = 0;

    do{
    printf("\t\t\t\xDA\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xBF\n");
    printf("\t\t\t\xB3                                                            \xB3\n");
    printf("\t\t\t\xB3                          Login                             \xB3\n");
    printf("\t\t\t\xB3                                                            \xB3\n");
    printf("\t\t\t\xC0\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xD9\n");
    printf("\n\t\t\t\tEnter your index number : ");
    scanf("%s",indexNo);
    printf("\t\t\t\tEnter the password : ");
    scanf("%s",password);
    printf("\n\n\t\t\t\tPress Enter key to continue\n");

    system("cls");
        correctIndex= confirmIndexNumber(indexNo);
        if(correctIndex==1)
        {
            selectMenu(indexNo, subjectCode);        //displays the relevant menu.
        }

    }while(correctIndex==0);

}

int confirmIndexNumber(char indexNo[])      //The index number of students should start with 'st', the index number of lecturers should start with 'le', the index number of the admin should start with 'ad'.
{
    int confirmed = 0;

    if((indexNo[0]=='s' && indexNo[1]=='t')||(indexNo[0]=='l' && indexNo[1]=='e') || (indexNo[0]=='a' && indexNo[1]=='d'))
    {
        confirmed = 1;
    }
    else{
        printf("\n\n\t\t\tInvalid Index Number!!!  Try Again.\n\n");
    }

    return confirmed;
}

void selectMenu(char indexNo[],char subjectCode[])         //select the relevant menu according to the index number.
{
    if(indexNo[0]=='l' && indexNo[1]=='e')
    {
        displayLecturerMenu(indexNo, subjectCode);
    }
    else if(indexNo[0]=='s' && indexNo[1]=='t')
    {
        displayStudentMenu(indexNo, subjectCode);
    }
    else if(indexNo[0]=='a' && indexNo[1]=='d')
    {
        displayAdminMenu(indexNo, subjectCode);
    }
    else
    {
        printf("\t\t\tInvalid User!\n");
    }
}

void displayLecturerMenu(char indexNo[],char subjectCode[])
{
    int option = 0;

    printf("\t\t\t\tSelect an option\n\n");
    printf("\t\t\t  1. Mark Attendance\n");
    printf("\t\t\t  2. Search a record\n");
    printf("\t\t\t  3. Edit a record\n");
    printf("\t\t\t  4. Delete a record\n");
    printf("\t\t\t  5. View Attendance Rate\n");
    printf("\t\t\t  6. Exit\n");
    printf("\t\t\t  : ");
    scanf("%d",&option);

    switch(option)
    {
        case 1: system("cls");
                markAttendance();
                break;
        case 2: system("cls");
                searchRecords(indexNo);
                break;
        case 3: system("cls");
                editRecords(indexNo);
                break;
        case 4: system("cls");
                deleteRecords(indexNo);
                break;
        case 5: system("cls");
                viewEligibility(indexNo, subjectCode);
                break;
        //case 5: exit();
          //      break;
        default: printf("\n\t\tIncorrect Option!!!");
                 break;
    }
}

void displayStudentMenu(char indexNo[],char subjectCode[])
{
    int option;

    printf("\t\t\t\tSelect an option\n\n");
    printf("\t\t\t  1. Insert Data\n");
    printf("\t\t\t  2. Search a Record\n");
    printf("\t\t\t  3. View Attendance Rate\n");
    printf("\t\t\t  4. Exit\n");
    printf("\t\t\t  : ");
    scanf("%d",&option);

    switch(option)
    {
        case 1: system("cls");
                insertData(indexNo);
                break;
        case 2: system("cls");
                searchRecords(indexNo);
                break;
        case 3: system("cls");
                viewEligibility(indexNo, subjectCode);
                break;
        //case 4: exit();
          //      break;
        default: printf("\n\t\tIncorrect Option!!!");
    }
}

void displayAdminMenu(char indexNo[],char subjectCode[])
{
    int option = 0;

    printf("\t\t\t\tSelect an option\n\n");
    printf("\t\t\t  1. Insert Data\n");
    printf("\t\t\t  2. Search a record\n");
    printf("\t\t\t  3. Edit a record\n");
    printf("\t\t\t  4. Delete a record\n");
    printf("\t\t\t  5. View Attendance Rate\n");
    printf("\t\t\t  6. Exit\n");
    printf("\t\t\t  : ");
    scanf("%d",&option);

    switch(option)
    {
        case 1: system("cls");
                insertData(indexNo);
                break;
        case 2: system("cls");
                searchRecords(indexNo);
                break;
        case 3: system("cls");
                editRecords(indexNo);
                break;
        case 4: system("cls");
                deleteRecords(indexNo);
                break;
        case 5: system("cls");
                viewEligibility(indexNo,subjectCode);
                break;
        //case 5: ext();
          //      break;
        default: printf("\n\t\tIncorrect Option!!!");
                 break;
    }
}

int searchIndexNumber(char indexNo[])        //check whether the inserted index number exists.
{
    FILE *filePointer2;

    int existingIndex = 0;

    filePointer2 = fopen("studentDetails.txt", "r");

    while(!feof(filePointer2))
    {
        fread(&student, sizeof(student), 1, filePointer2);

        if(strcmp(indexNo, student.indexNumber) == 0)
        {
            existingIndex = 1;
            fclose(filePointer2);
            return existingIndex;
        }
    }
    fclose(filePointer2);
    return existingIndex;
}

void insertData(char indexNo[])
{
    char addAnother;

    do
    {
    FILE *filePointer1;

    int existingIndex = 0;

    filePointer1 = fopen("studentDetails.txt", "a");

    printf("\t\t\t\xDA\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xBF\n");
    printf("\t\t\t\xB3                STUDENT ATTENDANCE RECORDING SYSTEM         \xB3\n");
    printf("\t\t\t\xB3                                                            \xB3\n");
    printf("\t\t\t\xB3                     Insert Students' Data                  \xB3\n");
    printf("\t\t\t\xC0\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xD9\n");

        printf("\n\t\t\t > Enter student index number : ");
        scanf("%s",indexNo);

        existingIndex = searchIndexNumber(indexNo);
        if(existingIndex == 1)
        {
            printf("\n\t\t\tIndex number has already been inserted!\n");
            insertData(indexNo);
        }
        else
        {
            strcpy(student.indexNumber,indexNo);

            printf("\n\t\t\t > Enter your name            : ");
            scanf("%s",student.name);
            printf("\n\t\t\t > Enter a contact number     : ");
            scanf("%d",&student.contactNumber);
            printf("\n\t\t\t > Enter your email address   : ");
            scanf("%s",student.emailAddress);
            printf("\n\t\t\t > Enter enrolled subjects    : ");
            scanf("%s",student.enrolledSubject);

            fprintf(filePointer1, "%s\t%s\t%d\t%s\t%s\n", student.indexNumber, student.name, student.contactNumber, student.emailAddress, student.enrolledSubject);
            fclose(filePointer1);

            printf("\n\t\tDo you want to enter another record?\n\t\t> Press y or Y if yes\n\t\t> Press n or N if no : ");
            scanf(" %c",&addAnother);
        }

    }while(addAnother=='y' || addAnother=='Y');
}

void markAttendance()
{
    int attendance = 0;     //1 or 0

    int existingIndex = 0;
    char choice;

    do
    {
        FILE *filePointer3;

        filePointer3 = fopen("studentAttendance.txt", "a");

    printf("\t\t\t\xDA\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xBF\n");
    printf("\t\t\t\xB3                                                            \xB3\n");
    printf("\t\t\t\xB3                     Mark Attendance                        \xB3\n");
    printf("\t\t\t\xB3                                                            \xB3\n");
    printf("\t\t\t\xC0\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xD9\n");

    printf("\n\t\t\t > Enter the subject code : ");
    scanf("%s",finalAttendance.subjectCode);

    if(strcmp(finalAttendance.subjectCode, SUBJECT_1)==0 || strcmp(finalAttendance.subjectCode, SUBJECT_2)==0 || strcmp(finalAttendance.subjectCode, SUBJECT_3)==0 || strcmp(finalAttendance.subjectCode, SUBJECT_4)==0)
    {
        printf("\t\t\t > Enter the number of weeks that lectures were held : ");
        scanf("%d",&finalAttendance.noOfWeeks);

            printf("\t\t\t > Enter the student's index number : ");
            scanf("%s",finalAttendance.indexNumber);

            existingIndex = searchIndexNumber(finalAttendance.indexNumber);

            if(existingIndex == 1)
            {

                printf("\n\t\t\t   Press 1 for present, 0 for absent\n");

                int attendanceCount = 0;
                int i = 1;
                while(i<=finalAttendance.noOfWeeks)
                {
                    printf("\t\t\tWeek %d : ",i);
                    scanf("%d",&attendance);
                    if(attendance == 0 || attendance == 1)
                    {
                        if(attendance==1)
                        {
                            attendanceCount= attendanceCount+1;
                        }
                            i++;
                    }
                    else
                    {
                        printf("\n\t\t\tPress 1 or 0\n");
                        markAttendance();
                    }
                }
                printf("\t\t\tAttendance count : %d\n",attendanceCount);
                finalAttendance.attendanceCount = attendanceCount;

                fprintf(filePointer3, "%s\t%s\t%d\t%d\n", finalAttendance.indexNumber, finalAttendance.subjectCode, finalAttendance.noOfWeeks, finalAttendance.attendanceCount);
                fclose(filePointer3);

                printf("\n\t\t\tTo mark attendance again press 'y' or 'Y'.\n\t\t\tPress 'n' or 'N' to go to the main menu : ");
                scanf(" %c", &choice);
                if(choice == 'n' || choice == 'N')
                {
                    system("cls");
                    displayLecturerMenu(finalAttendance.indexNumber, finalAttendance.subjectCode);
                }
            }
            else{
                system("cls");
                printf("\n\t\t\tIndex Number Not Found!\n");
                markAttendance();
            }

    }
    else{
        system("cls");
        printf("\n\n\t\t\tIncorrect Subject Code!!!\n");
        markAttendance();
        }
        calculatePercentage(finalAttendance.indexNumber, finalAttendance.subjectCode);
    }while(choice == 'y' || choice == 'Y');
}

void calculatePercentage(char indexNo[], char subjectCode[])
{
    FILE *filePointer5;
    FILE *filePointer6;

    filePointer5 = fopen("studentAttendance.txt", "r");
    filePointer6 = fopen("attendanceRate.txt", "w");

    while(!feof(filePointer5))
    {
        fscanf(filePointer5, "%s %s %d %d", finalAttendance.indexNumber, finalAttendance.subjectCode, &finalAttendance.attendanceCount, &finalAttendance.noOfWeeks);

        if((strcmp(indexNo, finalAttendance.indexNumber)== 0) && (strcmp(subjectCode, finalAttendance.subjectCode) == 0))
        {
            finalAttendance.percentage = (finalAttendance.attendanceCount*100)/finalAttendance.noOfWeeks;

            fprintf(filePointer6, "%s\t%s\t%.2f\n", finalAttendance.indexNumber, finalAttendance.subjectCode, finalAttendance.percentage);
            fclose(filePointer6);
        }
    }
    fclose(filePointer5);

}

void searchRecords(char indexNo[])
{
    int existingIndex = 0;

    printf("\t\t\tEnter the index Number : ");
    scanf("%s",indexNo);

    existingIndex = searchIndexNumber(indexNo);

    if(existingIndex == 1)
    {
        FILE *filePointer4;

        filePointer4 = fopen("studentDetails.txt", "r");
//while(fread(&student, sizeof(student), 1, filePointer4))
        while(!feof(filePointer4))
        {
            fscanf(filePointer4, "%s", student.indexNumber);

            if(strcmp(student.indexNumber,indexNo)==0)
            {
                printf("\t\t\t> Index Number     : %s\n",student.indexNumber);
                printf("\t\t\t> Name             : %s\n",student.name);
                printf("\t\t\t> Contact Number   : %10d\n",student.contactNumber);
                printf("\t\t\t> Email Address    : %s\n",student.emailAddress);
                printf("\t\t\t> Enrolled Subjects: %s\n",student.enrolledSubject);
            }
            else
            {
                 printf("\n\t\t\tCan not find the record.\n");
            }
            fclose(filePointer4);
        }
    }
    else
    {
        printf("\t\t\tNo such record!!!\n");
    }
}

void editRecords(char indexNo[])
{
    int existingIndex = 0;

    printf("\t\t\tEnter the index number : ");
    scanf("%s",indexNo);

    existingIndex = searchIndexNumber(indexNo);

    if(existingIndex==1)
    {
        printf("\t\t\tEnter new index number : ");
        scanf("%s",student.indexNumber);
        printf("\t\t\tEnter new name : ");
        scanf("%s",student.name);
        printf("\t\t\tEnter new contact number : ");
        scanf("%d",&student.contactNumber);
        printf("\t\t\tEnter new email address : ");
        scanf("%s",student.emailAddress);
        printf("\t\t\tEnter enrolled subjects : ");
        scanf("%s",student.enrolledSubject);
    }
}

void deleteRecords(char indexNo[])
{

}

void ext()
{

}

void viewEligibility(char indexNo[], char subjectCode[])
{
    FILE *filePointer7;
    FILE *filePointer8;
    //FILE *filePointer9;

    int existingIndex = 0;
    char eligibility[15];

    printf("\t\t\t\xDA\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xBF\n");
    printf("\t\t\t\xB3                                                            \xB3\n");
    printf("\t\t\t\xB3             Student's Attendance Rate                      \xB3\n");
    printf("\t\t\t\xB3                                                            \xB3\n");
    printf("\t\t\t\xC0\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xD9\n");

    printf("\n\t\t\tEnter the Index Number : ");
    scanf("%s",indexNo);
    existingIndex=searchIndexNumber(indexNo);
    if(existingIndex==1)
    {
        printf("\t\t\tEnter the subject Code : ");
        scanf("%s",subjectCode);

        if(strcmp(subjectCode,SUBJECT_1)==0 || strcmp(subjectCode,SUBJECT_2)==0 || strcmp(subjectCode,SUBJECT_3)==0 || strcmp(subjectCode,SUBJECT_4)==0 || strcmp(subjectCode,SUBJECT_5)==0)
            {
                filePointer7 = fopen("studentDetails.txt", "r");
                filePointer8 = fopen("attendanceRate.txt", "r");

                while(!feof(filePointer7))
                {
                    fscanf(filePointer7, "%s %s", student.indexNumber, student.name);
                if(strcmp(indexNo, student.indexNumber) == 0)
                {
                    fscanf(filePointer8, "%s %s %f", finalAttendance.indexNumber, finalAttendance.subjectCode, &finalAttendance.percentage);

                while(indexNo == finalAttendance.indexNumber)
                {
                    if(finalAttendance.percentage>=80)
                    {
                        strcpy(eligibility,"Eligible");
                    }
                    else{
                        strcpy(eligibility,"Not Eligible");
                    }

                printf("\n\t\t\t\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\n");
                printf("\t\t\t  Index Number     Name        Subject Code     Percentage       Eligibility \n");
                printf("\n\t\t\t\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\xC4\n");
                printf("\t\t\t   %s               %s               %s            %.2f %%          %s \n",student.indexNumber,student.name,finalAttendance.subjectCode,finalAttendance.percentage,eligibility);

                }
                fclose(filePointer8);
                }
                fclose(filePointer7);
            }
        }
    }
}

