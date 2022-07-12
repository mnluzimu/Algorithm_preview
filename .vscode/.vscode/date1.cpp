#include <cstdio>
#include <cstring>
#include <cstdlib>

int months[][13] = {{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
    , {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31} };

int is_leap(int year){
    return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
}

void get_time(char str[], int & hour, int & min, int & sec){
    char * p;
    p = strtok(str, ":");
    hour = atoi(p);
    p = strtok(NULL, ":");
    min = atoi(p);
    p = strtok(NULL, ":");
    sec = atoi(p);
    // printf("%d:%d:%d ", hour, min, sec);
}

void get_date(char str[], int & mon, int & day, int & year){
    char * p;
    p = strtok(str, ".");
    day = atoi(p);
    p = strtok(NULL, ".");
    mon = atoi(p);
    p = strtok(NULL, ".");
    year = atoi(p);
    // printf("%d.%d.%d \n", mon, day, year);
}


int main(){
    char time_str[30];
    char date_str[30];
    scanf("%s%s", time_str, date_str);
    int hour, min, sec, day, mon, year;
    get_time(time_str, hour, min, sec);
    get_date(date_str, mon, day, year);
    int m_hour, m_min, m_sec, m_day, m_mon, m_year;
    long long total_sec = 0;
    total_sec = (double)(hour * 3600 + min * 60 + sec) / 86400.0 * 100000;
    m_sec = total_sec % 100;
    total_sec /= 100;
    m_min = total_sec % 100;
    total_sec /= 100;
    m_hour = total_sec;
    int total_day = 0;
    for(int i = 2000; i < year; i++){
        if(is_leap(i))
            total_day += 366;
        else
            total_day += 365;
    }
    int leap_flag;
    leap_flag = is_leap(year);
    for(int i = 1; i < mon; i++){
        total_day += months[leap_flag][i];
    }
    total_day += day - 1;
    m_day = total_day % 100 + 1;
    total_day /= 100;
    m_mon = total_day % 10 + 1;
    total_day /= 10;
    m_year = total_day;

    printf("%d:%d:%d %d.%d.%d\n", m_hour, m_min, m_sec, m_day, m_mon, m_year);
    return 0;
}