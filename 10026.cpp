#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

char pos[101][101];
char pos2[101][101];
bool visit[101][101] = { false };
bool visit2[101][101] = { false };
int N, x, y, next_x, next_y;
int cur_x = 0;
int cur_y = 0;
queue <pair<int, int>> q;
string s;

int dx[] = { 0,0,-1,1 };
int dy[] = { -1,1,0,0 };
bool flag = false;

bool bfs(char c,char pos[101][101],bool visit[101][101]) {
    flag = false;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (pos[i][j] == c && visit[i][j] == false) {
                cur_y = i;
                cur_x = j;
                flag = true;
                break;
            }
        }

        if (flag == true) break;
    }

    if (flag == false) return flag;

    q.push({ cur_y,cur_x });
    visit[cur_y][cur_x] = true;

    while (!q.empty()) {
        y = q.front().first;
        x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            next_x = x + dx[i];
            next_y = y + dy[i];

            if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= N) continue;
            if (pos[next_y][next_x] != c || visit[next_y][next_x] == true) continue;
            if (pos[next_y][next_x] == c && visit[next_y][next_x] == false) {
                pos[next_y][next_x] = pos[y][x] + 1;
                q.push({ next_y,next_x });
                visit[next_y][next_x] = true;
            }
        }

    }

    return flag;
}



int main(void) {
    int answer = 0;
    int answer2 = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> s;
        for (int j = 0; j < N; j++) {
            pos[i][j] = s[j];
            if(s[j]=='R') pos2[i][j] = 'G';
            else pos2[i][j] = s[j];
        }
    }

    while (bfs('R',pos,visit)) answer++;
    while (bfs('G',pos,visit)) answer++;
    while (bfs('B',pos,visit)) answer++;

    while (bfs('G', pos2, visit2)) answer2++;
    while (bfs('B', pos2, visit2)) answer2++;

    printf("%d %d", answer,answer2);

    return 0;

}