#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;
#define MAX_SIZE 1000

void HeapAdjust(int a[], int s, int t){
    int w = a[s];
    int i;
    for(i = 2 * s; i <= t; i *= 2){
        if(i < t)
            i = (a[i] > a[i + 1]) ? i : i + 1;
        if(w >= a[i]) break;
        a[s] = a[i];
        s = i;
    }
    a[s] = w;
}

void HeapSort(int a[], int n){
    for(int i = n / 2; i >= 0; i--)
        HeapAdjust(a, i, n - 1);
    for(int i = n - 1; i >= 1; i--){
        swap(a[0], a[i]);
        HeapAdjust(a, 0, i - 1);
    }
}

int main(){
    int n;
    int a[MAX_SIZE];
    srand((unsigned int)time(NULL));
    printf("input n: ");
    scanf("%d", & n);
    for(int i = 0; i < n; i++){
        a[i] = rand();
    }
    HeapSort(a, n);
    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    return 0;
}