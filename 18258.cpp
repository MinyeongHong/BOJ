#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>
#include <queue>

using namespace std;

int main(void) {
	string order;
	int N;
	queue <int> result,answer;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		cin>>order;

		if (order == "push") {
			int Data = 0;
			scanf(" %d", &Data);
			result.push(Data);
		}
		else if (order == "pop") {
			if (result.empty()) {
				answer.push(-1);

			}
			else {
				answer.push(result.front());
				result.pop();
			}
		}
		else if (order == "size") {
			answer.push(result.size());

		}
		else if (order == "empty") {
			if (result.empty()) {
				answer.push(1);

			}
			else {
				answer.push(0);

			}
		}
		else if (order == "front") {
			if (result.empty()) {
				answer.push(-1);

			}
			else {
				answer.push(result.front());

			}
		}
		else if (order == "back") {
			if (result.empty()) {
				answer.push(-1);
			}
			else 
				answer.push(result.back());
		}
		else break;
	}


	while (!answer.empty()) {
		printf("%d\n", answer.front());
		answer.pop();
	}

		return 0;
}