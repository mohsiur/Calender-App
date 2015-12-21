#include <stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

//Declaring Variables for the months and days
int days_in_month[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int month_offset[]={0, 0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5};
int year_offset[13];
char *months[] = {
    " ",
    "January",
    "February",
    "March",
    "April",
    "May",
    "June",
    "July",
    "August",
    "September",
    "October",
    "November",
    "December"
};

int in_year(void);
int in_month(void);
int century_offset(int year);
void year_offset_calc(int year);
int leap_year(int year);
void prnt_cal(int co, int yo[]);
void view_cal(void);
void add_reminder(void);
int view_reminder(void);
void edit_reminder(void);
void delete_reminder(void);
void load_menu(void);
void reload_menu(void);
void load(void);
void save(void);

//Structure for Storing reminders
struct reminders{

    char date[11];
    char reminder[512];

} rem[MAX];

int top = 0;

int main(void){

    load();
    load_menu();
}

//Inputting the year.
int in_year(void){

    int year;

    printf("Please enter a year (example 1999): ");
    scanf("%d", &year);

    return year;
}

//Inputting the month
int in_month(void){

    int month;
    printf("Please Enter a month (example December is 12): ");
    scanf("%d", &month);

    return month;
}

/* Calculation for use in algorithims */

//Century Offset
int century_offset(int year){

    int century, c, century_offset;

    century=year/100;
    c = century;
    if(c%4==0){
        c=c+4;
    }
    else{
        while(c%4!=0){
            c=c+1;
        }
    }

    century_offset=((c-1)-century)*2;

    return century_offset;

}

//Year Offset
void year_offset_calc(int year){

    int i, y;

    y= year%100;
    for(i=0; i<13; i++){
        year_offset[i]=((y+(y/4))%7);
    }
}

//Adjusting Number of days for leap year and year offset
int leap_year(int year){

    if(year % 4 != 0){
        days_in_month[2] = 28;
    }
    else if(year % 100 != 0){
        days_in_month[2] = 29;
        year_offset[1]=year_offset[1]-1;
        year_offset[2]=year_offset[2]-1;
    }
    else if(year % 400 != 0){
        days_in_month[2] = 28;
    }
    else{
        days_in_month[2] = 29;
        year_offset[1]=year_offset[1]-1;
        year_offset[2]=year_offset[2]-1;
    }
}

//Printing Calender of full year
void prnt_cal(int co, int yo[]){

    int m, d, day_offset;
    char x=' ';

    for(m=1; m<=12; m++){
        printf("\n\n\n  %s", months[m]);
        printf("\n\n  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n\n");

        for(d=1; d<=days_in_month[m]; d++){
            day_offset=(co+yo[m]+month_offset[m]+(d%7))%7;
            if(d==1){
                if(day_offset==1){
                    printf("%5c", x);
                }
                else if(day_offset==2){
                    printf("%10c", x);
                }
                else if(day_offset==3){
                    printf("%15c", x);
                }
                else if(day_offset==4){
                    printf("%20c", x);
                }
                else if(day_offset==5){
                    printf("%25c", x);
                }
                else if(day_offset==6){
                    printf("%30c", x);
                }
            }
            if(day_offset==0){
                printf("%5d", d);
            }
            else if(day_offset==1){
                printf("%5d", d);
            }
            else if(day_offset==2){
                printf("%5d", d);
            }
            else if(day_offset==3){
                printf("%5d", d);
            }
            else if(day_offset==4){
                printf("%5d", d);
            }
            else if(day_offset==5){
                printf("%5d", d);
            }
            else if(day_offset==6){
                printf("%5d\n", d);
            }
        }

    }
}

//Printing Calender of specific month
void prnt_cal_month(int co, int yo[], int month){

    int m, d, day_offset;
    char x=' ';

    printf("\n\n\n  %s", months[month]);
    printf("\n\n  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n\n");

    for(d=1; d<=days_in_month[month]; d++){
        day_offset=(co+yo[month]+month_offset[month]+(d%7))%7;
        if(d==1){
            if(day_offset==1){
                printf("%5c", x);
            }
            else if(day_offset==2){
                printf("%10c", x);
            }
            else if(day_offset==3){
                printf("%15c", x);
            }
            else if(day_offset==4){
                printf("%20c", x);
            }
            else if(day_offset==5){
                printf("%25c", x);
            }
            else if(day_offset==6){
                printf("%30c", x);
            }
        }
        if(day_offset==0){
            printf("%5d", d);
        }
        else if(day_offset==1){
            printf("%5d", d);
        }
        else if(day_offset==2){
            printf("%5d", d);
        }
        else if(day_offset==3){
            printf("%5d", d);
        }
        else if(day_offset==4){
            printf("%5d", d);
        }
        else if(day_offset==5){
            printf("%5d", d);
        }
        else if(day_offset==6){
            printf("%5d\n", d);
        }
    }
}

//To view the calendar
void view_cal(void){

    int  year, co, month;
    char ch;

    printf("To view [C] Calendar of year [D] Calender of specific month");
    do{
        ch = getchar();
        printf("\n");

        switch(ch){
            case 'c':
            case 'C': year = in_year();
                      co=century_offset(year);
                      year_offset_calc(year);
                      leap_year(year);
                      prnt_cal(co, year_offset);
                        break;
            case 'd':
            case 'D': month=in_month();
                      year = in_year();
                      co=century_offset(year);
                      year_offset_calc(year);
                      leap_year(year);
                      prnt_cal_month(co, year_offset, month);
                        break;

            default: printf("Wrong Choice! Enter Again: ");
                    break;
        }
    }while(ch!='C' && ch!='D' && ch!='c' && ch!='d');

}

//Adding a Reminder
void add_reminder(void){

    int i, num, count;
    printf("Number of reminders you want to add: \n");
    scanf("%d", &num);
    count = 0;
    for(i=top; i<MAX; i++){
        printf("\n\nEnter Date (dd/mm/yyyy): ");
        scanf("%s", rem[i].date);
        printf("Enter Reminder: ");
        scanf("%s", rem[i].reminder);
        save();
        count++;
        if(count == num) {
            break;
        }
    }

    top = i;
    save();
}

//Viewing Reminders
int view_reminder(void){

    char date[11];
    int i, found;

    printf("Enter Date (dd/mm/yyyy): ");
    scanf("%s", date);
    found = 0;
    for(i=0; i<top; i++){
        if(!strcmp(date, rem[i].date)){
            printf("Reminder %d. %s - %s", i+1, rem[i].date, rem[i].reminder);
            found =1;
            printf("\n");
        }
    }
    if(!found) printf("\nNo Reminders stored on this date\n");

    return found;
}

//Editing Reminder
void edit_reminder(void){

    int found, i;
    char temp[80];
    found = view_reminder();
    i=0;
    if(found==1){
        printf("Which Reminder do you want to edit: ");
        scanf("%d", &i);
        printf("\nEnter new reminder: ");
        scanf("%s", rem[i].reminder);
    }
    save();
}

//Deleting Reminders
void delete_reminder(void){

    int found, i, j;
    char temp[80];
    found = view_reminder();
    i=0;
    j=0;
    if(found==1){
        printf("Which Reminder do you want to delete: ");
        scanf("%d", &i);
        for(j=i; j<(top-1); j++){
            strcpy(rem[j].date,rem[j+1].date);
            strcpy(rem[j].reminder,rem[j+1].reminder);
        }
        strcpy(rem[top].date,"");
        strcpy(rem[top].reminder,"");
        top=top-1;
    }
    save();
}

// Loading the Menu
void load_menu(void){
    int year;
    char x=' ';
    char ch;
    printf("%25c----------CALENDAR---------\n\n", x);
    printf("%15c[C] View Calendar", x);
    printf("%15c[V] View Reminders\n\n", x);
    printf("%15c[E] Edit Reminders", x);
    printf("%14c[A] Add a Reminder\n\n", x);
    printf("%15c[D] Delete Reminders", x);
    printf("%12c[Q] Quit\n\n", x);

    do{
        ch = getchar();
        printf("\n");

        switch(ch){
            case 'c':
            case 'C': view_cal();
                      reload_menu();
                    break;
            case 'v':
            case 'V': view_reminder();
                      reload_menu();
                    break;
            case 'e':
            case 'E': edit_reminder();
                      reload_menu();
                    break;
            case 'd':
            case 'D': delete_reminder();
                      reload_menu();
                    break;

            case 'a':
            case 'A': add_reminder();
                      reload_menu();
                    break;
            case'q':
            case'Q':printf("%20cMade by Mohsiur Rahman, Razibul Raquib \n%30cand Aqibur Rahman\n\n", x, x);
                    exit(0);
                    break;

            default: printf("Enter Choice: ");
                    break;
        }
    }while(ch!='C' && ch!='V' && ch!='E' && ch!='A' && ch!='D' &&ch!='Q' && ch!='c' && ch!='v' && ch!='e' && ch!='a' && ch!='d' && ch!='Q');

}

//Reloading Menu
void reload_menu(void){

    char x=' ';
    printf("\n\n[R] Return to Main Menu\n\n");
    printf("[Q] Quit Application\n\n");
    char ch;
    do{
        ch = getchar();
        printf("\n");

        switch(ch){
            case'r':
            case'R': system("clear");
                    load_menu();
                    break;
            case'q':
            case'Q':printf("%20cMade by Mohsiur Rahman, Razibul Raquib \n%30cand Aqibur Rahman\n\n", x, x);
                    exit(0);
                    break;
            default: printf("Enter Choice:  ");
                    break;

        }
    }while(ch!='Q' && ch!='R' && ch!='r' && ch!='q');

}

//Loading saved file
void load(void){

    FILE *fp;
    int i;

    if((fp = fopen("Reminders.txt", "rb"))==NULL){
        printf("Reminder file not on disk.\n\n");
        return;
    }

    if(fread(&top, sizeof top, 1, fp) != 1){
        printf("Error reading count");
        exit(1);
    }

    for(i=0; i<=top; i++){
        if(fread(&rem[i], sizeof(struct reminders), 1, fp) != 1){
            printf("Error reading reminder data. \n");
            exit(1);
        }
    }
    fclose(fp);
}

//Saving File
void save(void){

    FILE *fp;
    int i;

    if((fp = fopen("Reminders.txt", "wb"))==NULL){
        printf("Cannot open reminders file.\n");
        exit(1);
    }

    if(fwrite(&top, sizeof top, 1, fp)!=1){
        printf("Error reading count");
        exit(1);
    }

    for(i=0; i<=top; i++){
        if(fwrite(&rem[i], sizeof(struct reminders), 1, fp)!=1){
            printf("Error writing reminder data.\n");
            exit(1);
        }
    }
    fflush(fp);
    fclose(fp);
}
