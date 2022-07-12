#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main(){
    char str[100];
    // fgets(str, 100, stdin);
    // str[strlen(str) - 1] = '\0';
    // puts(str);
    int nums[20];
    int i = 0;
    int temp;
    while(scanf("%d", & temp) == 1){
        nums[i++] = temp;
    }
    for(int j = 0; j < i; j++){
        printf("%d ", nums[j]);
    }
    // char * p;
    // p = strtok(str, " ");
    // while(p){
    //     nums[i++] = atoi(p);
    //     p = strtok(NULL, " ");
    // }

    sort(nums, nums + i);
    int ans = 0;
    for(int j = 0; j < i; j++){
        if(binary_search(nums, nums + i, nums[j] * 2))
            ans++;
    }

    printf("%d\n", ans);
}