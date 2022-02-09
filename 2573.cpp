#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int iceberg[301][301] = { 0 };
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int n, m;

void melt() {
	int melted_amount[301][301] = { 0 };
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (iceberg[i][j] > 0) {
				for (int k = 0; k < 4; k++) {
					if (i + dy[k] >= 0 && i + dy[k] < n && j + dx[k] >= 0 && j + dx[k] < m) {
						if (iceberg[i + dy[k]][j + dx[k]] == 0) {
							melted_amount[i][j]++;
						}
					}
				}
			}
		}
	}

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < m; j++) {
			if (iceberg[i][j] - melted_amount[i][j] >= 0) iceberg[i][j] -= melted_amount[i][j];
			else iceberg[i][j] = 0;
		}
	}

	return;
}

int bfs(){
	stack<pair<int,int>> st;
	int visited[301][301] = { false };
	int islands = 0; 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (iceberg[i][j] > 0 && !visited[i][j]) {
				st.push({ i, j });
				visited[i][j] = true;

				while (!st.empty()) {
					pair<int, int> cur = st.top();
					st.pop();
					for (int k = 0; k < 4; k++) {
						if (i + dy[k] >= 0 && i + dy[k] < n && j + dx[k] >= 0 && j + dx[k] < m) {
							if (iceberg[cur.first + dy[k]][cur.second + dx[k]] > 0 && !visited[cur.first + dy[k]][cur.second + dx[k]]) {
								st.push({ cur.first + dy[k],cur.second + dx[k] });
								visited[cur.first + dy[k]][cur.second + dx[k]] = true;
							}
						}
					}
				}
				islands++;
			}
		}
	}
	return islands;
}

int main(void) {
	int a,cnt;
	int answer=0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a;
			iceberg[i][j] = a;
		}
	}
	while (1) {
		answer++;
		melt();
		cnt = bfs();

		if (cnt > 1) break;
		else if (cnt == 0) {
			answer = 0;
			break;
		}
	}

	cout << answer;
	return 0;
}