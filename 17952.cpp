#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(void) {
    int N,score,t;
    int result = 0;
    stack<int> hw;
    vector<int> time;

    scanf("%d", &N);


    for (int i = 0; i < N; i++) {
        int flag;
        scanf("%d",&flag);

        if (flag) {
            scanf("%d %d", &score, &t);
            time.push_back(t);
            hw.push(score);
            time[time.size() - 1]--;

        }
        else {
            if (i > 0 && !(hw.empty()))
                time[time.size()-1]--;
            else continue;
        }


        if (!hw.empty()) {
            if (time[time.size() - 1] == 0) {
                result += hw.top();
                hw.pop();
                time.pop_back();
            }
        }
    }

    printf("%d",result);
    return 0;
}