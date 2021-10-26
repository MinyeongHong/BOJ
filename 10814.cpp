#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

bool comp(pair<int,string> a, pair<int,string> b) {
	return a.first < b.first;
}

int main(void) {
	int N,age;
	string name;
	vector <pair <int, string>> person;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >>age >>name;
		person.push_back(make_pair(age,name));
	}
	stable_sort(person.begin(), person.end(), comp);
	for(int j=0; j<N; j++) 	cout << person[j].first <<' '<< person[j].second <<'\n';
}