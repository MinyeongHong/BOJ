#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, x, y, target_A, target_B;
int arr[101][101] = { 0 };
vector<int> relation(101, -1);

int bfs() {
	int answer = 0;
	queue <int> q;
	relation.resize(n + 1);
	relation[target_A] = 0;

	for (int i = 1; i <= n; i++) {
		if (arr[i][target_A] == 1 || arr[target_A][i] == 1) {
			q.push(i);
			relation[i] = relation[target_A] + 1;
		}
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int i = 1; i <= n; i++) {
			if (arr[i][cur] == 1 && relation[i] == -1) {
				relation[i] = relation[cur] + 1;
				q.push(i);
			}
		}
	}
	return relation[target_B];
}

int main(void) {
	cin >> n;
	cin >> target_A >> target_B;
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		arr[x][y] = 1;
		arr[y][x] = 1;

	}
	cout << bfs();
	return 0;
}