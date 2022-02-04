#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;

vector<int> block[51];
int direction;

void changedirection(void) {

    if (direction >= 4) {
        while (direction >= 4) {
            direction %= 4;
        }
    }

    if (direction == 0) direction = 3;
    else if (direction == 1) direction = 0;
    else if (direction == 2) direction = 1;
    else direction = 2;

    return;
}

int bfs(int r, int c) {
    int answer = 0;
    stack <pair<int,int>> st;
    int dx[] = { -1, 0, 1, 0 };
    int dy[] = { 0, -1, 0, 1 }; //북 동 남 서 방향에서 왼쪽 블럭 위치

    int dx_back[] = { 0, -1, 0, 1 };
    int dy_back[] = { 1, 0, -1, 0 };//북 동 남 서 방향에서 후진 블럭 위치

    int try_cnt = 0;

    st.push({ r,c });
    block[r][c] = -1;
    answer++;

    while (!st.empty()) {
        
        if ((block[r + dy[direction]][c + dx[direction]]) == 0) {
            st.pop();       
            
            r = r + dy[direction];
            c = c + dx[direction];

            st.push({ r,c });
            block[r][c] = -1;
            answer++;
            try_cnt = 0;
            changedirection();
        }
        // (block[r + dy[direction]][c + dx[direction]] == 1) || (block[r + dy[direction]][c + dx[direction]] == -1) 
        else{
            changedirection();
            try_cnt++;

            if (try_cnt == 4) {
                try_cnt = 0;
                if ((block[r + dy_back[direction]][c + dx_back[direction]]) == 1) break;
                else {
                    r = r + dy_back[direction];
                    c = c + dx_back[direction];
                }

            }
        }
    }
    return answer;
}

int main(void) {
    int cur_r, cur_c;
    int r,c,a;

    cin >> r >> c;

    cin >> cur_r >> cur_c >> direction;

    for (int j = 0; j < r; j++) {
        for (int i = 0; i < c; i++) {
            cin >> a;
            block[j].push_back(a);
        }
    }
    int result=bfs(cur_r,cur_c);
    cout << result;

    return 0;

}

