#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
	
vector<int> arr[100001];
bool visited[100001] = { false };
int n;

int search() {
	int floor = 0;
	while (1) {
		for (int i = 0; i < arr[floor].size(); i++) {
			int K = arr[floor][i];
			if (K == n) return floor;
			if (K % 2 == 0) {
				if (!visited[K / 2]) {
					arr[floor + 1].push_back(K / 2);
					visited[K / 2] = true;
				}
			}
			if (K - 1 >= 0) {
				if (!visited[K - 1]) {
					arr[floor + 1].push_back(K - 1);
					visited[K - 1] = true;
				}
			}
			if (K + 1 <= 100000) {
				if (!visited[K + 1]) {
					arr[floor + 1].push_back(K + 1);
					visited[K + 1] = true;
				}
			}

		}
		floor++;
	}

}
int main(void) {
	int k;
	cin >> n >> k;
	arr[0].push_back(k);
	visited[k] = true;
	cout << search();
	return 0;
}