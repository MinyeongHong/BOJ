#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int count_island(vector<vector<int>> island) {
    int cnt = 0;
    int dx[] = { -1,0,1, -1,1,  -1,0,1 };
    int dy[] = { 1,1,1,  0,0,  -1,-1,-1 };

    stack <pair<int, int >> st;
    pair<int,int> idx;
    int width = island[0].size();
    int height = island.size();

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (island[i][j] == 1) {
                st.push(make_pair(i, j));
                while (!st.empty()) {
                    idx = st.top();
                    i = idx.first;
                    j = idx.second;
                    st.pop();
                    island[i][j] = 0;
                    for (int k = 0; k < 8; k++) {
                        if ((i + dy[k] >= 0 && i + dy[k] < height) && (j + dx[k] >= 0 && j + dx[k] < width)) {
                            if (island[i + dy[k]][j + dx[k]] == 1) {
                                idx = make_pair(i + dy[k], j + dx[k]);
                                st.push(idx);
                            }
                        }

                    }
                }
                cnt++;
                i = 0;
                j = 0;
            }
        }
    }
    return cnt;
}

int main(void) {
    vector<vector<int>> island;
    vector <int> one_line;
    vector <int> answer;
    int w, h,a;
    while (1) {
        cin >> w >> h;
        if (w == 0 && h == 0) break;
        else {
            for (int j = 0; j < h; j++) {
                for (int i = 0; i < w; i++) {
                    cin >> a;
                    one_line.push_back(a);
                }
                island.push_back(one_line);
                one_line.clear();
            }
            answer.push_back(count_island(island));
            island.clear();
        }
    }

    for (auto it = answer.begin(); it < answer.end(); it++) printf("%d\n", *it);

    return 0;
}
