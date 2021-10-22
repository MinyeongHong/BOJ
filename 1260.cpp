#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <stack>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

vector <vector<int>> graph(1001);
bool check[1001] = { false };
bool check2[1001] = { false };

bool comp(pair<int, int>a, pair<int, int> b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    else return a.first < b.first;
}

void dfs(int start) {
    printf("%d ", start);
    check[start] = true;

    for (int i = 0; i < graph[start].size(); i++) {
        int near = graph[start][i];
        if (!check[near]) {
            dfs(near);
        }
    }

    return;
}

void bfs(int start) {
    queue <int> q;
    check2[start] = true;
    q.push(start);
    while (!q.empty()) {
        int x = q.front();
        printf("%d ", x);
        q.pop();
        for (int i = 0; i < graph[x].size(); i++) {
            int near = graph[x][i];
            if (!check2[near]) {
                q.push(near);
                check2[near] = true;
            }
        }
    }
}

int main (void) {
    int N, M;
    int a, b;

    cin >> N;
    cin >> M;

    vector<pair<int,int>> num;

    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        if (a > b)num.push_back(make_pair(a, b));
        else num.push_back(make_pair(b, a));
    }

    sort(num.begin(), num.end(), comp);

    for (int j = 0; j < num.size(); j++) {
        a = num[j].first;
        b = num[j].second;
        graph[a].push_back(b);
        graph[b].push_back(a);

    }

    return 0;

}