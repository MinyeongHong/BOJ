#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

bool comp(pair<int,string> a, pair<int,string> b) {
	if (a.first == b.first) return a.second < b.second;
	else return a.first< b.first; //오름차순
}

int main(void) {
	int N;
	string s;
	vector <pair<int,string>> word;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s;
		word.push_back(make_pair(s.size(),s));
	}

	sort(word.begin(), word.end(), comp);

	for (int j = 0; j < N-1; j++) {
		if (word[j].second == word[j + 1].second) {
			word.erase(word.begin() + j+1);
			j--;
			N--;
		}
	}

	for(int k=0; k<word.size(); k++)		cout << word[k].second << '\n';
	

	return 0;
}