#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Print(vector<int> &arr) {
	for (int i = 0; i < 5; i++) printf("%d ", arr[i]);
	printf("\n");
}
int main(void) {
	bool flag = true;
	int a;
	vector <int> input_arr;
	for (int i = 0; i < 5; i++) {
		cin >> a;
		input_arr.push_back(a);
	}
	
	while (flag) {
		flag = false;
		for (int i = 0; i < 4; i++) {
			if (input_arr[i] > input_arr[i + 1]) {
				swap(input_arr[i], input_arr[i + 1]);
				Print(input_arr);
				flag = true;
			}
		}
	}
	return 0;
}
