#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int gap(pair<int, int>a, pair<int, int>b) {
	int result;
	result = abs(a.first - b.first) +abs(a.second- b.second);
	return result;
}

int main(void) {
	int t, n, x, y;
	vector<string> answer;
	cin >> t;
	while (t--) {
		bool visited[103] = { false };
		queue <pair <int, int>> q;
		pair<int, int> cur;
		vector<pair <int, int>> d;

		cin >> n;

		for (int i = 0; i < n + 2; i++) {
			cin >> x >> y;
			d.push_back({x,y});
		}

		q.push(d[0]);
		visited[0] = true;
		cur = q.front();
		while (!q.empty()) {
			if (cur == d[n + 1]) break;
			int len = q.size();
			for (int j = 0; j < len; j++) {
				cur = q.front();
				if (cur == d[n + 1]) break;
				q.pop();
				for (int i = 1; i < n + 2; i++) {
					if (!visited[i] && gap(cur, d[i]) <= 1000) {
						q.push(d[i]);
						visited[i] = true;
					}
				}
			}
		}

		if (cur == d[n + 1]) answer.push_back("happy");
		else answer.push_back("sad");
		d.clear();
	}

	for (auto itr = answer.begin(); itr < answer.end(); itr++) cout << *itr << endl;
	return 0;
}