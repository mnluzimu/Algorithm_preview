#include <cstdio>
#include <stdlib.h>
#include <time.h>
#define MAX_SIZE 100

void bubble_sort(int a[], int n){
    for(int i = 0; i < n - 1; i++){
        for(int j = n - 1; j > i; j--){
            if(a[j] < a[j - 1]){
                int tmp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = tmp;
            }
        }
    }
}


int main(){
    int n;
    printf("input n: ");
    scanf("%d", & n);
    int a[MAX_SIZE];
    srand((unsigned)time(NULL));
    for(int i = 0; i < n; i++){
        a[i] = rand();
        //printf("%d ", a[i]);
    }
    bubble_sort(a, n);
    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
}