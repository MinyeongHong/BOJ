#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int make_number(int num) {
	int a,ori_num;
	int result = 0;
	vector<int> each_number;
	if (num < 10) {
		return num + num;
	}
	else {
		ori_num = num;
		while (num) {
			a = num % 10;
			each_number.push_back(a);
			num /= 10;
		}
		for (auto itr = each_number.begin(); itr != each_number.end(); itr++) {
			result += *itr;
		}
		return result + ori_num;
	}

}
int main(void) {
	bool arr[10001] = { false };

	for (int i = 1; i < 10000; i++) {
		int value = make_number(i);
		if (value < 10000 && !arr[value]) arr[value] = true;
	}

	for (int j = 1; j < 10000; j++) {
		if(!arr[j]) printf("%d\n",j);
	}
	return 0;
}
