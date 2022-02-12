#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int main(void) {
	int T, a, b,num;
	vector <int> answer;
	cin >> T;
	while (T--) {
		cin >> a >> b;
		num = a;
		if(b==1) num = a%10;
		while (--b) {
			num *=a;
			if (num > 10) {
				num %= 10;
			}

		}
		
		if (num == 0) num = 10;
		answer.push_back(num);
	}

	for(auto itr=answer.begin(); itr<answer.end(); itr++)printf("%d\n",*itr);
	return 0;
}
