#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int tri[501][501] = { 0 };
int max_sum[501][501] = { 0 };

int main(void) {
	int T,num;
	cin >> T;
	for (int i = 0; i < T; i++) {
		for(int j=0; j<=i; j++){
			cin >> num;
			tri[i][j] = num;
		}
	}
	max_sum[0][0] = tri[0][0];

	for (int k = 1; k < T; k++) {
		for (int l = 0; l <= k; l++) {
			if (l == 0) max_sum[k][l] = tri[k][l] + max_sum[k - 1][l];
			else if (l == k) max_sum[k][l] = tri[k][l] + max_sum[k - 1][l - 1];
			else max_sum[k][l] = tri[k][l]+max(max_sum[k - 1][l], max_sum[k - 1][l - 1]);
		}
	}
	int result = max_sum[T - 1][0];
	for (int i = 1; i < T; i++) {
		if (max_sum[T - 1][i] > result) result = max_sum[T - 1][i];
	}

	printf("%d", result);
	return 0;
}
