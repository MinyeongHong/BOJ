#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(void) {
    int N;
    char order[10];
    stack<int> result;
    vector<int> answer;

    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%s", &order);

        if (!strcmp(order, "push")) {
            int NData = 0;
            scanf("%d", &NData);
            result.push(NData);

        }

        else if (!strcmp(order, "pop")) {
            if (!result.empty()) {
                int PData = result.top();
                result.pop();
                answer.push_back(PData);
            }
            else answer.push_back(-1);
        }

        else if (!strcmp(order, "size")) {
            answer.push_back(result.size());

        }

        else if (!strcmp(order, "empty")) {
            if (result.empty()) answer.push_back(1);
            else answer.push_back(0);

        }

        else if (!strcmp(order, "top")) {
            if (!result.empty()) answer.push_back(result.top());
            else answer.push_back(-1);
        }

    }

    for (int j = 0; j < answer.size(); j++) {
        printf("%d\n", answer[j]);
    }

    return 0;
}