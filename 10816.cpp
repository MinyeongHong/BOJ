#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M,low,high;
vector <int> belonging;
vector <int> card;

int main(void) {
	int a;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &a);
		belonging.push_back(a);
	}
	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &a);
		card.push_back(a);
	}
	sort(belonging.begin(), belonging.end());
	for (int j = 0; j < M; j++) {
		auto range = equal_range(belonging.begin(), belonging.end(), card[j]);
		auto low = range.first;
		auto high = range.second;
		printf("%d ", high - low);
	}


	return 0;
}
