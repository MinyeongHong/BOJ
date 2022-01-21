#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;

bool visited[100001] = { false };
int result[100001] = { 0 };
vector <int> connection[100001];
queue <int> q;
void bfs() {
    int start = q.front();
    visited[start] = true;
    q.pop();
    
    for (int i = 0; i < connection[start].size(); i++) {
        

        if (!visited[connection[start][i]]) {
            visited[connection[start][i]] = true;
            result[connection[start][i]] = start;
            q.push(connection[start][i]);
        }
        
    }
    while(!q.empty()){
        bfs();
    }
    return;
}

int main(void) {

    int n,a,b;

    cin >> n;

    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        connection[a].push_back(b);
        connection[b].push_back(a);
    }

    q.push(1);
    bfs();

    for (int j = 2; j <= n; j++)  printf("%d\n", result[j]);

    return 0;

}