#include <cstdio>

int months[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main(){
    int w;
    scanf("%d", & w);
    int days = 13;
    for(int i = 1; i <= 12; i++){
        if((days - 1 + w) % 7 == 5){
            printf("%d\n", i);
        }
        days += months[i];
    }
    return 0;
}