#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

int months[][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
    , {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31} };


void substr(char source[], char result[], int pos, int length){
    for(int i = 0; i < length; i++){
        result[i] = source[pos + i];
    }
    result[pos] = '\0';
}

int is_leap(int year){
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int main(){
    char str_time[10];
    char str_date[10];

    scanf("%s %s", str_time, str_date);

    int hour, sec, min, day, month, year;
    char d[2] = ":";
    char * p;
    p = strtok(str_time, d);
    hour = atoi(p);
    p = strtok(NULL, d);
    min = atoi(p);
    p = strtok(NULL, d);
    sec = atoi(p);
    printf("%d:%d:%d ", hour, min, sec);

    d[0] = '.';
    p = strtok(str_date, d);
    month = atoi(p);
    p = strtok(NULL, d);
    day = atoi(p);
    p = strtok(NULL, d);
    year = atoi(p);
    printf("%d.%d.%d\n", month, day, year);

    int total = 0;
    for(int i = 2000; i < year; i++){
        if(is_leap(i))
            total += 366;
        else
            total += 365;
    }



    int flag;
    if(is_leap(year))
        flag = 1;
    else flag = 0;
    for(int i = 1; i < month; i++){
        total += months[flag][i];
    }
    printf("%d\n", total);

    total += (day - 1);
    printf("%d\n", total);

    long long int total_seconds = hour * 3600 + min * 60 + sec;
    total_seconds = total_seconds * 100000 / 86400;
    sec = total_seconds % 100;
    total_seconds /= 100;
    min = total_seconds % 100;
    total_seconds /= 100;
    hour = total_seconds % 10;
    total_seconds /= 100;
    day = total % 100 + 1;
    printf("%d\n", day);
    total /= 100;
    month = total % 10 + 1;
    printf("%d\n", month);
    total /= 10;
    year = total;

    printf("%d:%d:%d %d.%d.%d\n", hour, min, sec, month, day, year);
}