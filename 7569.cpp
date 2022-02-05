#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int box[101][101][101] = { -2 };
bool visited[101][101][101] = { false };
int m, n, h, a;
int dx[] = { 1,-1,0,0,0,0 };
int dy[] = { 0,0,1,-1,0,0 };
int dz[] = { 0,0,0,0,1,-1 };
queue<vector<int>> q;
void bfs() {

	while (!q.empty()) {
		vector<int> cur_pos = q.front();
		q.pop();
		for (int i = 0; i < 6; i++) {

			if (cur_pos[0] + dz[i] < h && cur_pos[0] + dz[i] >= 0 && cur_pos[1] + dy[i] < n && cur_pos[1] + dy[i] >= 0 && cur_pos[2] + dx[i] < m && cur_pos[2] + dx[i] >= 0)
			{
				int cur_z = cur_pos[0] + dz[i];
				int cur_y = cur_pos[1] + dy[i];
				int cur_x = cur_pos[2] + dx[i];
				if (box[cur_z][cur_y][cur_x] == 0 && !visited[cur_z][cur_y][cur_x]) {
					q.push({ cur_z,cur_y,cur_x });
					box[cur_z][cur_y][cur_x] = box[cur_pos[0]][cur_pos[1]][cur_pos[2]] + 1;
					visited[cur_z][cur_y][cur_x] = true;
					
				}

			}

		}
	}
}

int main(void) {
	int border_cnt = 0;
	cin >> m >> n >> h;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> a;
				box[i][j][k] = a;
				if (a == 1) {
					visited[i][j][k] = true;
					q.push({ i, j, k });
				}
				else if (a == -1) border_cnt++;
			}
		}
	}

	if (q.size() == m * n * h - border_cnt) {
		cout << 0;
		return 0;
	}

	bfs();

	int answer = 1;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (box[i][j][k] == 0) { cout << -1; return 0; }
				if (box[i][j][k] > answer) { answer = box[i][j][k]; }
			}
		}

	}
	if (answer == 1) answer = 0;
	else if (answer > 1) answer -= 1;
	cout << answer;
	return 0;
}