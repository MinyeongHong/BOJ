#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int arr_cnt[10000];

int main(void) {
    int N, a;
    scanf("%d", &N);
    
    for (int i = 0; i < N; i++) {
        scanf("%d",&a);
        arr_cnt[a]++;
    }

    for (int i = 0; i < 10001; i++) {
        while (arr_cnt[i] > 0) {
            printf("%d\n", i);
            arr_cnt[i]--;
        }
    }

    return 0;
}

