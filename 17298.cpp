#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <stack>

using namespace std;

int main(void) {
	int N, num, bigger_n;
	stack <int> st,st2,answer;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		st.push(num);
	}

	answer.push(-1);
	st2.push(st.top());
	st.pop();

		while (!st.empty()) {
			if (st.top() < st2.top()) {
				answer.push(st2.top());
				st2.push(st.top());
				st.pop();
			}

			else {
				st2.pop();

				while (!st2.empty()) {
					if (st.top() < st2.top()) {
						answer.push(st2.top());
						st2.push(st.top());
						st.pop();
						break;
					}
					st2.pop();
				}

				if (st2.empty()) {
					answer.push(-1);
					st2.push(st.top());
					st.pop();
				}
			}
		}


		while (!answer.empty()) {
			printf("%d ", answer.top());
			answer.pop();
		}

		return 0;


}