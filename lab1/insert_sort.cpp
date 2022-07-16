#include <cstdio>
#include <cstdlib>
#include <ctime>
#define MAXSIZE 100
int a[MAXSIZE];

void insert_sort(int a[], int n){
    for(int i = 1; i < n; i++){
        int tmp = a[i];
        int j;
        for(j = i - 1; j >= 0; j--){
            if(a[j] > tmp){
                a[j + 1] = a[j];
            }
            else{
                break;
            }
        }
        a[j + 1] = tmp;
    }
}

int main(){
    printf("input n: ");
    int n;
    scanf("%d", & n);
    srand((unsigned int)time(NULL));
    for(int i = 0; i < n; i++){
        a[i] = rand();
    }
    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
    insert_sort(a, n);
    for(int i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}