#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int R, C, T, val;
int room[51][51] = { 0 };

void diffusion() {
	int sub_room[51][51] = { 0 };
	int dx[] = { 1,-1,0,0 };
	int dy[] = { 0,0,1,-1 };

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (room[i][j] > 0) {
				int weight = room[i][j] / 5;
				for (int k = 0; k < 4; k++) {
					if (i + dy[k] >= 0 && i + dy[k] < R && j + dx[k] >= 0 && j + dx[k] < C) {
						if (room[i + dy[k]][j + dx[k]] != -1) {
							sub_room[i + dy[k]][j + dx[k]] += weight;
							sub_room[i][j] -= weight;
						}
					}
				}
			}
		}
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (room[i][j] != -1) room[i][j] += sub_room[i][j];
		}
	}
	return;
}

void upper_clean(int y, int x) {
	queue<int> q;
	for (int i = 1; i < C; i++) {//[y][1]~[y][C-1]
		q.push(room[y][i]);
	}
	for (int j = y - 1; j >= 0; j--) {//[y-1][C-1]~[0][C-1]
		q.push(room[j][C - 1]);
	}
	for (int k = C - 2; k > 0; k--) {//[0][C-2]~[0][1]
		q.push(room[0][k]);
	}
	for (int m = 0; m < y - 1; m++) {//[0][0]~[y-2][0]
		q.push(room[m][0]);
	}
	room[y][1] = 0;
	while (!q.empty()) {
		for (int i = 2; i < C; i++) { //[y][2]~[y][C-1] 
			room[y][i] = q.front();
			q.pop();
		}
		for (int j = y - 1; j >= 0; j--) {//[y-1][C-1]~[0][C-1]
			room[j][C - 1] = q.front();
			q.pop();
		}
		for (int k = C - 2; k > 0; k--) {//[0][C-2]~[0][1]
			room[0][k] = q.front();
			q.pop();
		}
		for (int m = 0; m < y ; m++) {//[1][0]~[y-1][0]
			room[m][0] = q.front();
			q.pop();
		}
	}
	return;
}
void lower_clean(int y, int x) {
	queue<int> q;
	for (int i = 1; i < C; i++) {//[y][1]~[y][C-1]
		q.push(room[y][i]);
	}
	for (int j = y + 1; j < R; j++) {//[y+1][C-1]~[R-1][C-1]
		q.push(room[j][C - 1]);
	}
	for (int k = C - 2; k >= 0; k--) {//[R-1][C-2]~[R-1][0]
		q.push(room[R - 1][k]);
	}
	for (int l = R - 2; l > y + 1; l--) {//[R-2][0]~[y+2][0]
		q.push(room[l][0]);
	}
	room[y][1] = 0;
	while (!q.empty()) {
		for (int i = 2; i < C; i++) {//[y][2]~[y][C-1]
			room[y][i] = q.front();
			q.pop();
		}
		for (int j = y + 1; j < R; j++) {//[y+1][C-1]~[R-1][C-1]
			room[j][C - 1] = q.front();
			q.pop();
		}
		for (int k = C - 2; k >= 0; k--) {//[R-1][C-2]~[R-1][0]
			room[R - 1][k] = q.front();
			q.pop();
		}
		for (int l = R - 2; l > y; l--) {//[R-2][0]~[y+1][0]
			room[l][0] = q.front();
			q.pop();
		}
	}
	return;
}

int main(void) {
	int answer = 0;
	vector<pair<int, int>> idx;
	cin >> R >> C >> T;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> val;
			room[i][j] = val;

			if (val == -1) {
				idx.push_back({ i,j });
			}
		}
	}
	for (int q = 0; q < T; q++) {
		diffusion();
		upper_clean(idx[0].first, idx[0].second);
		lower_clean(idx[1].first, idx[1].second);
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (room[i][j] > 0) answer += room[i][j];
		}
	}
	cout << answer;
	return 0;
}
