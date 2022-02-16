#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int main(void) {
	int N,value;
	vector<int> A,B;
	int sum = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> value;
		A.push_back(value);
	}
	sort(A.begin(), A.end());
	for (int i = 0; i < N; i++) {
		cin >> value;
		B.push_back(value);
	}
	sort(B.rbegin(), B.rend());

	for (int j = 0; j < N; j++) {
		sum += A[j] * B[j];
	}
	cout << sum;

	return 0;
}
