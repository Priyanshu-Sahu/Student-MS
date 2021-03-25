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