
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> first_card;
vector<int> answer;

void ck(int start_idx, int end_idx, int val) {
    int mid_idx = (end_idx + start_idx) / 2;
    if (start_idx <= end_idx) {
        if (first_card[mid_idx] == val) {
            answer.push_back(1);
            return;
        }
        else if (first_card[mid_idx] < val) {
            ck(mid_idx + 1, end_idx, val);
        }
        else {
            ck(start_idx, mid_idx - 1, val);
        }
    }
    else {
        answer.push_back(0);
        return;
    }

    return;
}

int main(void) {
    int N, M, a, b;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> a;
        first_card.push_back(a);
    }
    sort(first_card.begin(), first_card.end());

    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> b;
        ck(0, first_card.size() - 1, b);
    }

    for (auto it = answer.begin(); it < answer.end(); it++) cout << *it << ' ' ;
    return 0;
}
