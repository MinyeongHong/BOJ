#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int Coin[1000001];

int main(void) {
    int N, K;

    int answer = 0;
    scanf("%d %d", &N, &K);

    for (int i = 0; i<N; i++)
        scanf("%d", &Coin[i]);

    int max_value=N-1;

    while (Coin[max_value] > K) max_value--;

    while (K > 0){
        while (Coin[max_value] <= K) {
            K -= Coin[max_value];
            answer++;
        }
        max_value--;
    }

    printf("%d", answer);
    return 0;
}

