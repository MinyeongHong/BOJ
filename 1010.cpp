#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int answer_arr[31][31] = { 0 };

void DP(int n, int m) {
	int ans;
	if (n == 1) answer_arr[n][m] = m;

	if (n > 1 && n == m) answer_arr[n][m] = 1;
	else if (n > 1) {
		if(answer_arr[n-1][m-1]==0) DP(n - 1, m - 1);
		if(answer_arr[n][m-1]==0) DP(n, m - 1);
		answer_arr[n][m] = answer_arr[n - 1][m - 1] + answer_arr[n][m - 1];
	}
	return;
}

int main(void) {
	int T,n,m;
	vector <int> answer;
	
	cin >> T;
	while (T--) {
		cin >> n >> m;
			DP(n, m);
			answer.push_back(answer_arr[n][m]);
			answer_arr[31][31] = { 0 };
	}

	for (auto itr = answer.begin(); itr != answer.end(); itr++) printf("%d\n", *itr);
	return 0;
}

