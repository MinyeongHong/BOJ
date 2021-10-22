#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include <regex>

using namespace std;

int main(void) {
	int N;
	string str;
	regex reg("^[A-F]?A+F+C+[A-F]?$");

	scanf("%d", &N);

	for (int i = 0; i < N; i++){
	cin >> str;
	if (regex_match(str, reg)) printf("Infected!\n");
	else printf("Good\n");
	}
	
	return 0;
}
