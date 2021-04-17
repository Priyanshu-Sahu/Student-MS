
/* This Program shows the use of file system to store
*  Data. This project deals with merits and demerits of file system
*  over DBMS - Data base and management system.
*
*  This project is made by Priyanshu Sahu for educational purpose 
*  in C programing language. You are welcome to made any changes or modification 
*  in this project.    
*/

#include<stdio.h>
#include<conio2.h>
#include<conio.c>
#include<stdlib.h>

struct student
{
    /* data */
    char PRN[10];
    char name[50];
    char dept[8];
    char branch[10];
    char batch[5];
    long unsigned int mobn; 
};

struct student stu;

void addS_det(){
    printf("Add Record\n");
    FILE *fp;
    fp = fopen("record.txt","ab+");
    if(fp == NULL){
        printf("Error in opening file\n");
    }
    else{
        fflush(stdin);
        printf("PRN: ");gets(stu.PRN);
        printf("Name: ");gets(stu.name);
        printf("Department: ");gets(stu.dept);
        printf("Branch: ");gets(stu.branch);
        printf("Batch: ");gets(stu.batch);
        printf("Phone Number: ");scanf("%ld",&stu.mobn);
        fwrite(&stu, sizeof(stu), 1, fp);
        
        textcolor(YELLOW);printf("Record added successfully");   
    }
    fclose(fp);
    return;
}

void modS_det(){
    printf("Modify Record\n");
    char s_id[15];
    int isFound = 0;
    printf("Enter PRN to Modify: ");fflush(stdin);
    gets(s_id);
    FILE *fp;
    fp = fopen("record.txt","rb+");

    while(fread(&stu, sizeof(stu),1,fp) == 1){
        if(strcmp(s_id, stu.PRN) == 0){
            fflush(stdin);
            printf("PRN: ");gets(stu.PRN);
            printf("Name: ");gets(stu.name);
            printf("Department: ");gets(stu.dept);
            printf("Branch: ");gets(stu.branch);
            printf("Batch: ");gets(stu.batch);
            printf("Phone Number: ");scanf("%ld",&stu.mobn);
            fseek(fp,-sizeof(stu), SEEK_CUR);
            fwrite(&stu,sizeof(stu), 1, fp);
            isFound = 1;
            break;
        }
    }
    if(!isFound){
        printf("No Record Found");
    }
    fclose(fp);
    return;
}

void delS_det(){
    printf("Delete Record");
    char s_id[15];
    int isFound = 0;
    printf("Enter PRN to Modify: ");fflush(stdin);
    gets(s_id);
    FILE *fp, *temp;
    fp = fopen("record.txt","rb");
    temp = fopen("temp.txt", "wb");
    
    while(fread(&stu, sizeof(stu),1,fp) == 1){
        if(strcmp(s_id, stu.PRN) == 0){
            fwrite(&stu,sizeof(stu),1,temp);
        }
    }
    fclose(fp);
    fclose(temp);
    remove("record.txt");
    rename("temp.txt","record.txt");
    printf("The record is sucessfully deleted");
    return;
}

void search_det(){
    printf("Search Record\n");
    char s_id[15];
    int isFound = 0;
    printf("Enter PRN to Search: ");fflush(stdin);
    gets(s_id);
    FILE *fp;
    fp = fopen("record.txt","rb");
    
    while(fread(&stu,sizeof(stu),1,fp) == 1){
        if(strcmp(s_id,stu.PRN) == 0){
            isFound = 1;
            break;
        }
    }

    if(isFound == 1){
        printf("The record is Found");
        printf("PRN: ");gets(stu.PRN);
        printf("Name: ");gets(stu.name);
        printf("Department: ");gets(stu.dept);
        printf("Branch: ");gets(stu.branch);
        printf("Batch: ");gets(stu.batch);
        printf("Phone Number: ");scanf("%ld",&stu.mobn);
    }else{
        printf("Sory, No record found in the database");
    }
    fclose(fp);
    return;
}

int main()
{
    char ch;
    clrscr();
    
    textcolor(WHITE);
    textbackground(BLUE);
    printf("+------------------------------------+\n");
    printf("|                                    |\n");
    printf("|      This project is made by       |\n");
    printf("|          -Priyanshu Sahu           |\n");
    printf("|             Version 1.1            |\n");
    printf("|                                    |\n");
    printf("+------------------------------------+\n");
    
    printf("\n1) Add Student details\n2) Modify Student details \n3) Delete Student details \n4) Search Student \n5) Exit\n");
    do
    {
        /* code */
        printf("Select any operation you want\n");
        ch= getche();
    } while(ch<='0' || ch>'5');
    
    switch(ch)
    {
        case '1':
            printf("\nYou have selected option 1");
            delay(800);
            addS_det();
            main();
        
        case '2':
            printf("\nYou have selected option 2");
            delay(800);
            modS_det();
            main();

        case '3':
            printf("\nYou have selected option 3");
            delay(800);
            delS_det();
            main();

        case '4':
            printf("\nYou have selected option 4");
            delay(800);
            search_det();
            delay(2000);
            main();

        case '5':
            printf("\nYou have selected option 5");
            textcolor(RED);
            delay(800);
            gotoxy(25,25);
            cprintf("\nA PROJECT BY PRIYANSHU SAHU");
            delay(1500);
            exit(1);

    }
    return 0;
}

/* This Program shows the use of file system to store
*  Data. This project deals with merits and demerits of file system
*  over DBMS - Data base and management system.
*
*  This project is made by Priyanshu Sahu for educational purpose 
*  in C programing language. You are welcome to made any changes or modification 
*  in this project.    
*/

#include<stdio.h>
#include<conio2.h>
#include<conio.c>
#include<stdlib.h>

/* int addS_det();
int modS_det();
int delS_det();
int disAS_det();
int disSS_det();
 */

typedef struct student
{
    /* data */
    char name[62];
    char dept[8];
    char city[26];
    int mobn; 
}s[100];

int main()
{
    char ch;
    clrscr();
    
    textcolor(WHITE);
    textbackground(BLUE);
    printf("+------------------------------------+\n");
    printf("|                                    |\n");
    printf("|      This project is made by       |\n");
    printf("|          -Priyanshu Sahu           |\n");
    printf("|             Version 1.0            |\n");
    printf("|                                    |\n");
    printf("+------------------------------------+\n");
    
    printf("\n1) Add Student details\n2) Modify Student details \n3) Delete Student details \n4) Display all details \n5) Search Student \n6) Exit\n");
    do
    {
        /* code */
        printf("Select any operation you want\n");
        ch= getche();
    } while(ch<='0' || ch>'6');
    switch(ch)
    {
        case '1':
            printf("\nYou have selected option 1");
            delay(800);
            //addS_det();
            main();
        
        case '2':
            printf("\nYou have selected option 2");
            delay(800);
            //modS_det();
            main();

        case '3':
            printf("\nYou have selected option 3");
            delay(800);
            //delS_det();
            main();

        case '4':
            printf("\nYou have selected option 4");
            delay(800);
            //disAS_det();
            main();

        case '5':
            printf("\nyou have selected option 5");
            delay(800);
            //disSS_det();
            main();

        case '6':
            printf("\nYou have selected option 6");
            textcolor(RED);
            delay(800);
            gotoxy(25,25);
            cprintf("\nA PROJECT BY PRIYANSHU SAHU");
            delay(1500);
            exit(1);

    }
    return 0;
}

