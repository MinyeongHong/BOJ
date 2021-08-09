#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int n[100001], m[100001] = { 0 };

void binary(int start,int end, int mid,int pivot) {
	int len = end - start + 1;
	int mid_left = mid / 2;
	int mid_right = (end + mid + 1) / 2;

	if (start > end) {
		printf("0\n");
		return;
	}

	else {
		if (n[mid] > pivot) {
			binary(start, mid - 1,mid_left, pivot);
		}

		else if (n[mid] < pivot) {
			binary(mid + 1, end, mid_right, pivot);
		}

		else {
			printf("1\n");
			return;
		}
	}
	
}

int main(void) {

	scanf("%d", &N);
	for (int i = 1; i < N+1; i++) scanf("%d", &n[i]);

	scanf("%d", &M);
	for (int i = 1; i < M+1; i++) scanf("%d", &m[i]);

	sort(n, n + N + 1);

	for (int i = 1; i < M+1; i++) {
		binary(1, N, (N+1)/2, m[i]);
	}
	
	return 0;
}
