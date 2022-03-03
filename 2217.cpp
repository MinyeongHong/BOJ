#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int main(void) {
	int N, value;
	vector<int> A, answer;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> value;
		A.push_back(value);
	}
	sort(A.begin(), A.end());
	for (int j = 0; j < N; j++) {
		answer.push_back(A[j] * (N - j));
	}
	int result = *max_element(answer.begin(), answer.end());
	cout << result;

	return 0;
}
