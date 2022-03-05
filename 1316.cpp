#include <iostream>
#include<string>

using namespace std;

int main(void) {
	int T,answer;
	string str;
	cin >> T;
	answer = T;

	while (T--) {
		bool check[150] = { false };
		cin >> str;
		check[str[0]] = true;
		for (int i = 1; i < str.size(); i++) {
			if (str[i] != str[i - 1]) {
				if (check[str[i]]) {
					answer--;
					break;
				}
				else check[str[i]] = true;
			}
		}
	}

	cout << answer;
	return 0;
}
