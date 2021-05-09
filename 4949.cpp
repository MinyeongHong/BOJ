#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stack>

using namespace std;

int main(void) {
	char input[105];
	while (1) {
		stack <char> st;
		int flag = 0;
		cin.getline(input, 101,'.');
		int Len = strlen(input);
		if (Len != 1) {
			for (int i = 0; i < Len; i++) {
				if (input[i] == '(' || input[i] == '[') st.push(input[i]);

				else if (input[i] == ')') {
					if (!st.empty() && (st.top() == '(')) st.pop();
					else {
						flag = 1;
						break;
					}
				}

				else if (input[i] == ']') {
					if (!st.empty() && (st.top() == '[')) st.pop();
					else {
						flag = 1;
						break;
					}
				}

			}

			if (!st.empty()) flag = 1;

			if (flag == 1) printf("no\n");
			else printf("yes\n");
		}
 	else break;
	}


	return 0;
}