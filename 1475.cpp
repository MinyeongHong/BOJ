#include <iostream>
#include <vector>
#include <stack>
#include<string>
#include <algorithm>
using namespace std;


int main(void) {
	int result = 1;
	int cnt = 0;
	vector<int> arr;
	stack<int> one_set;
	string num_str;
	getline(cin, num_str);
	bool used_set[7][10] = { false };

	for (int i = 0; i < num_str.size(); i++) {
		int num = num_str[i] - '0';
		for (int cnt = 0; cnt < 8; cnt++) {
			if (!used_set[cnt][num]) {
				used_set[cnt][num] = true;
				break;
			}
			else {
				if (num == 6 && !used_set[cnt][9]) {
					used_set[cnt][9] = true;
					break;
				}
				else if (num == 9 && !used_set[cnt][6]) {
					used_set[cnt][6] = true;
					break;
				}
			}
		}
	}
	
	bool flag;

	for (int j = 0; j < 7; j++) {
		flag = true;
		for (int k = 0; k < 10; k++) {
			if (used_set[j][k]) flag = false;
		}
		if (flag) {
			printf("%d", j);
			break;
		}
	}

	return 0;
}
