#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;
#define MAX_SIZE 1000

int partition(int a[], int i, int r, int pivot){
    int l = i - 1;
    do{
        while(a[++l] < pivot);
        while(r >= i && a[--r] > pivot);
        swap(a[l], a[r]);
    }while(l < r);
    swap(a[l], a[r]);
    return l;
}

void QuickSort(int a[], int i, int j){
    int pivotIndex = (i + j) / 2;
    swap(a[pivotIndex], a[j]);
    int k = partition(a, i, j, a[j]);
    swap(a[k], a[j]);
    if(k - i > 1) QuickSort(a, i, k - 1);
    if(j - k > 1) QuickSort(a, k + 1, j);
}

int main(){
    srand((unsigned int)time(NULL));
    printf("input n: ");
    int n;
    scanf("%d", & n);
    int a[MAX_SIZE];
    for(int i = 0; i < n; i++){
        a[i] = rand();
    }
    QuickSort(a, 0, n - 1);
    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}