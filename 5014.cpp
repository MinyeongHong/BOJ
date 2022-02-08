#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int F[1000001] = { 0 };
bool visited[1000001] = { false };

int main(void) {

	int answer = 0;
	queue <int> q;
	int f,s,g,u,d;
	cin >> f >> s >> g >> u >> d; 
	if (s != g) {
		q.push(g);
		visited[g] = true;

		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			if (cur - u > 0 && cur - u <= f) {
				if (!visited[cur - u]) {
					F[cur - u] = F[cur] + 1;
					visited[cur - u] = true;
					q.push(cur - u);
				}
			}
			if (cur + d > 0 && cur + d <= f) {
				if (!visited[cur + d]) {
					F[cur + d] = F[cur] + 1;
					visited[cur + d] = true;
					q.push(cur + d);
				}
			}
		}

		if (F[s] == 0) printf("use the stairs");
		else printf("%d", F[s]);
	}
	else printf("%d", 0);
	return 0;
}