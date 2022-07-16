#include <cstdio>
#include <cstdlib>
#include <time.h>
#define MAXSIZE 100
int a[MAXSIZE];

void InsSort(int a[], int n, int incr){ //对间距为incr的元素排序
    for(int i = incr; i < n; i += incr){
        int tmp = a[i];
        int j;
        for(j = i; (j > 0) && (a[j - incr] > tmp); j -= incr){
            a[j] = a[j - incr];
        }
        a[j] = tmp;
    }
}

void shell_sort(int a[], int n){
    int i;
    int j;
    for(i = n / 2; i > 2; i /= 2) //增量
        for(j = 0; j < i; j++) //起始元素下标
            InsSort(&a[j], n - j, i);
    InsSort(a, n, 1);
}

int main(){
    printf("input n: ");
    int n;
    scanf("%d", & n);
    srand((unsigned int)time(NULL));
    for(int i = 0; i < n; i++){
        a[i] = rand();
    }
    shell_sort(a, n);
    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
}