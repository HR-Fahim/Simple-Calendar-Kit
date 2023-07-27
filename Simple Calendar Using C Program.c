#include <stdio.h>
#include <stdlib.h>

int main()
{
    system("Color 5F");
    int year;
    char choice;
    char ch;

    printf("1. Press Y to see the calendar of a year.\n");
    printf("2. Press N to exit application.\n");

    printf("\nENTER YOUR CHOICE: ");
    scanf("%c", &choice);

    switch(choice)
    {
        case 'y':
        case 'Y':
            printf("\nENTER YEAR: ");
            scanf("%d", &year);

            calendar(year);
            break;
        case 'n':
        case 'N':
            exit(0);
            break;
        default:
            printf("\nINVALID INPUT\n");
            break;
    }
}
int get_first_weekDay(int year)
{
    int day;
    day=(((year - 1) * 365) + ((year - 1) / 4) - ((year - 1) / 100) + ((year) / 400) + 1) % 7;
    return day;
}

void calendar(int year)
{
    char *months[]={"January",
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
                    "December"};
    int monthDays[]={31,
                     28,
                     31,
                     30,
                     31,
                     30,
                     31,
                     31,
                     30,
                     31,
                     30,
                     31};

    if((year%4==0 && year%100!=0) || (year%400==0))
    {
        monthDays[1]=29;
    }

    int month;
    int dayInMonth;
    int day=0;
    int weekDay=0;
    int startingDay;

    startingDay=get_first_weekDay(year);

    for(month=0;month<12;month++)
    {
        dayInMonth=monthDays[month]+1;

        printf("\n\n==============%s=================\n", months[month]);
        printf("\n  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

        for(weekDay=0;weekDay<startingDay;weekDay++)
        {
            printf("     ");
        }

        for(day=1;day<dayInMonth;day++)
        {
            printf("%5d",day);
            if(++weekDay>6)
            {
                printf("\n");
                weekDay=0;
            }
            startingDay=weekDay;
        }
    }
}

