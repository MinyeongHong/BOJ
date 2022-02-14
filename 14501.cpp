#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	int T[25] = { 0 };
	int P[25] = { 0 };
	int answer[16] = { 0 };
	int max_price[16] = { 0 };
	int M = 0;
	int N, day, cost;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> day >> cost;
		T[i] = day;
		P[i] = cost;
	}

	for (int j = N; j > 0; j--) {
		if (j + T[j] > N + 1) {
			answer[j] = 0;
			max_price[j] = M;
		}
		else {
			answer[j] = P[j] + max_price[j + T[j]];
			if (answer[j] < M) max_price[j] = M;
			else {
				M = answer[j];
				max_price[j] = M;
			}
		}
	}
	printf("%d", max_price[1]);
	return 0;
}
