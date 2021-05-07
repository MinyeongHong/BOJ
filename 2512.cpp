#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main(void) {
    int N, M, a;
    vector<int> Budget;
    int answer = 0;

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d",&a);
        Budget.push_back(a);
    }
    scanf("%d", &M);

    sort(Budget.begin(), Budget.end());

    int average = M /N;
    int sum = accumulate(Budget.begin(), Budget.end(), 0);
    int min = Budget[0];
    int max = Budget[N - 1];
    int idx = 0;

    if (M >= sum) { printf("%d", max); }

    else if (average <= min) { printf("%d", average); }

    else {
        while (M > 0) {
            if (M > min && M >= min * Budget.size()) {

                for (int i = 0; i < Budget.size(); i++) {
                    Budget[i] -= min;
                    M -= min;
                }
                answer += min;
                Budget.erase(Budget.begin());
                min = Budget[0];

            }
            else {
                answer += M / Budget.size();
                break;
            }
        }

        printf("%d",answer);

    }


    return 0;
}

