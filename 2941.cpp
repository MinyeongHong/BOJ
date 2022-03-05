#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include<string>
#include <algorithm>
using namespace std;

int main(void) {
	string str,copy_str;
	string dic[] = { "c=","c-","dz=","d-","lj","nj","s=","z=" };
	cin >> str;
	int answer = str.size();
	int cnt_d = 0;
	int cnt = 0;
	bool flag = true;

	while (flag) {
		flag = false;
		for (auto s : dic) {
			auto idx = str.find(s);
			if (idx != string::npos) {
				str[idx] = 'A';
				answer -= 1;
				flag = true;
			}
		}
	}
	cout << answer;
	return 0;
}
