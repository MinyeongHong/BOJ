#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    int N, a;
    vector <int> Pi;
    int answer = 0;

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &a);
        Pi.push_back(a);
    }

    sort(Pi.begin(), Pi.end());

    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++)
            answer += Pi[j];
    }


    printf("%d", answer);

    return 0;
}

