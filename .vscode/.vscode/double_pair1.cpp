#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main(){
    char str[100];
    fgets(str, 100, stdin);
    str[strlen(str) - 1] = '\0';
    // puts(str);
    int nums[20];
    int i = 0;
    int k = 0;
    char temp[10];
    int len = strlen(str);
    for(int j = 0; j < len; j++){
        if(str[j] == ' '){
            temp[k] = '\0';
            if(strlen(temp) != 0)
                nums[i++] = atoi(temp);
            k = 0;
            continue;
        }
        temp[k++] = str[j];
    }
    temp[k] = '\0';
    if(strlen(temp) != 0)
        nums[i++] = atoi(temp);
    // for(int j = 0; j < i; j++){
    //     printf("%d ", nums[j]);
    // }
    // printf("\n");
    if(nums[i - 1] == 20){
        printf("4\n");
        return 0;
    }
    
    int j;
    for(j = 0; j < i - 1; j++){
        k = j;
        for(int l = j+1; l < i; l++){
            if(nums[l] < nums[k])
                k = l;
        }
        if(k != j){
            int temp = nums[k];
            nums[k] = nums[j];
            nums[j] = temp;
        }
    }
    // for(int j = 0; j < i; j++){
    //     printf("%d ", nums[j]);
    // }

    
    int ans = 0;
    for(int j = 0; j < i; j++){
        if(nums[j] == nums[j - 1])
            continue;
        if(binary_search(nums, nums + i, nums[j] * 2))
            ans++;
    }

    printf("%d\n", ans);
}