#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int matrix[128][128];
int blue, white = 0;

int same_color(int row_start, int col_start, int len) {
	int flag = 1;
	int pivot = matrix[col_start][row_start];
	for (int j = col_start; j < col_start+len; j++) {
		for (int i = row_start; i < row_start+len; i++) {
			if (pivot != matrix[j][i]) flag = 0;
		}
	}

	return flag;
}

void check(int row_start, int col_start, int n) {
	int mid = n / 2;

	if (n == 0) return;

	while (n > 1) {
		if (!same_color(row_start, col_start, n)) {
			check(row_start, col_start, n/2);
			check(row_start + mid, col_start, n/2);
			check(row_start, col_start + mid, n/2);
			check(row_start + mid, col_start + mid, n/2);
			return;
		}

		break;
	}

	if (matrix[col_start][row_start]) blue++;
	else white++;
	return;
}

int main(void) {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &matrix[i][j]);
		}
	}

	check(0, 0, N);
	printf("%d\n%d", white,blue);
}
