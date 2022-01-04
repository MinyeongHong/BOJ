#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int count_day(vector<vector<int>> box) {
    int cnt = -1;
    int unripe = 0;
    int dx[] = { -1,1,0,0 };
    int dy[] = {0, 0, 1, -1};
    queue<pair<int, int >> q;
    queue <pair<int, int >> ripe;
    pair<int,int> idx;
    int width = box[0].size();
    int height = box.size();

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (box[i][j] == 1) {
                ripe.push(make_pair(i, j));
            }
            else if (box[i][j] == 0) unripe++;
        }
    }

    if (unripe==0) return 0;

    while (1) {
        while (!ripe.empty()) {
            int x = ripe.front().second;
            int y = ripe.front().first;
            ripe.pop();

            for (int l = 0; l < 4; l++) {
                if ((y + dy[l] >= 0 && y + dy[l] < height) && (x + dx[l] >= 0 && x + dx[l] < width)) {
                    if (box[y + dy[l]][x + dx[l]] == 0) {
                        idx = make_pair(y + dy[l], x + dx[l]);
                        q.push(idx);
                        box[y + dy[l]][x + dx[l]] = 1;
                    }
                }

            }
        }
        cnt++;
        if (q.empty()) break;
        while (!q.empty()) {
            int x = q.front().second;
            int y = q.front().first;
            q.pop();
            for (int l = 0; l < 4; l++) {
                if ((y + dy[l] >= 0 && y + dy[l] < height) && (x + dx[l] >= 0 && x + dx[l] < width)) {
                    if (box[y + dy[l]][x + dx[l]] == 0) {
                        idx = make_pair(y + dy[l], x + dx[l]);
                        ripe.push(idx);
                        box[y + dy[l]][x + dx[l]] = 1;
                    }
                }

            }

        }
        cnt++;
        if (ripe.empty()) break;
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (box[i][j] == 0) return -1;
        }
    }

    return cnt;
}

int main(void) {
    vector<vector<int>> box;
    vector <int> one_line;
    vector <int> answer;
    int w, h,a;
    cin >> w >> h;
    for (int j = 0; j < h; j++) {
        for (int i = 0; i < w; i++) {
            cin >> a;
            one_line.push_back(a);
        }
        box.push_back(one_line);
        one_line.clear();
    }
    printf("%d",count_day(box));

    return 0;
}
