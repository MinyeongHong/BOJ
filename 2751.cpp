#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int list[1000001];
int main(void) {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		scanf("%d", &list[i]);

	sort(list, list + N);

	for (int i = 0; i < N; i++)
		printf("%d\n", list[i]);


	return 0;
}