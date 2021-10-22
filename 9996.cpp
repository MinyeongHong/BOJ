#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include <regex>

using namespace std;

int main(void)
{
	int N;
	int j = 0;
	string pattern;
	vector<string> arr;

	cin >> N;
	arr.resize(N);
	cin >> pattern;


	regex ex("([a-z]+)\\*([a-z]+)");
	smatch match;

	regex_match(pattern, match, ex);

	string head = match[1].str();
	int head_len = head.size();

	string tail=match[2].str();
	int tail_len = tail.size();

	while (N--) {
		cin >> arr[j];
		j++;
	}
	for (int i = 0; i < arr.size(); i++) {

		int arr_len = arr[i].size();
		int tail_idx = arr_len - tail_len;
		if (arr[i].find(head) == 0){
			if (arr[i].find(tail, tail_idx) == tail_idx) {
				if (head_len - 1 < tail_idx) printf("DA\n");
				else printf("NE\n");
			}
			else printf("NE\n");
		}
		else printf("NE\n");
	}
	return 0;
}
