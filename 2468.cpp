#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
	
int region[101][101] = { 0 };
int n;

int search(int height) {
	bool visited[101][101] = { false };
	int dx[] = { 1,-1,0,0 };
	int dy[] = { 0,0,1,-1 };
	int cnt = 0;
	stack <pair<int,int>> st;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (region[i][j] > height && !visited[i][j]) {
				st.push({ i,j });
				visited[i][j] = true;
				cnt++;
			}
			while (!st.empty()) {
				int x = st.top().second;
				int y = st.top().first;
				st.pop();
				for (int k = 0; k < 4; k++) {
					if (y + dy[k] >= 0 && y + dy[k] < n && x + dx[k] >= 0 && x + dx[k] < n) {
						if (region[y + dy[k]][x + dx[k]] > height && !visited[y + dy[k]][x + dx[k]]) {
							st.push({ y + dy[k], x + dx[k] });
							visited[y + dy[k]][x + dx[k]] = true;
						}
					}
				}

			}

		}
	}

	return cnt;
}

int main(void) {
	int a;
	int answer = 1;
	int max_rain = 1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a;
			region[i][j] = a;
			if (a > max_rain) max_rain = a;
		}
	}

	for (int h = max_rain-1; h > 0; h--) {
		int tmp = search(h);
		if (answer < tmp) answer = tmp;
	}

	cout << answer;
	return 0;
}