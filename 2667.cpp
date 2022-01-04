#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main(void) {
    vector<string> town;
    vector<int> answer;
    queue <pair<int,int>> q;
    pair<int, int> idx;
    int N;
    int num = 0;
    string s;

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> s;
        town.push_back(s); 
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (town[i][j] == '1') {
                q.push(make_pair(i, j));

                while (!q.empty()) {
                    idx = q.front();
                    town[idx.first][idx.second] = '0';
                    if (idx.second > 0 && town[idx.first][idx.second - 1] == '1') { q.push(make_pair(idx.first, idx.second - 1)); town[idx.first][idx.second - 1] = '0'; } //예외처리추가
                    if (idx.second < N - 1 && town[idx.first][idx.second + 1] == '1') { q.push(make_pair(idx.first, idx.second + 1)); town[idx.first][idx.second + 1] = '0'; }
                    if (idx.first > 0 && town[idx.first - 1][idx.second] == '1') { q.push(make_pair(idx.first - 1, idx.second)); town[idx.first - 1][idx.second] = '0'; }
                    if (idx.first < N - 1 && town[idx.first + 1][idx.second] == '1') { q.push(make_pair(idx.first + 1, idx.second)); town[idx.first + 1][idx.second] = '0'; }
                    q.pop();
                    num++;
                }

                answer.push_back(num);
                num = 0;

            }
        }
    }


    printf("%d\n", answer.size());
    sort(answer.begin(), answer.end());
    for (auto it = answer.begin(); it < answer.end(); it++) printf("%d\n",*it);
    return 0;
}
