#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;
//N±Ø 0 S±Ø1 ¹Ý½Ã°è0 ½Ã°è1
deque <bool> wheel[5];

void rotate_wheel(int n,bool d) {
	if (d) {
		wheel[n].push_front(wheel[n][7]);
		wheel[n].pop_back();
	}
	else {
		wheel[n].push_back(wheel[n][0]);
		wheel[n].pop_front();

	}
}

int main(void) {
	int answer = 0;
	string str;
	int n,number,direction;
	bool value;
	for (int i = 1; i < 5; i++) {
		cin >> str;
		for(char k:str) wheel[i].push_back(k-'0');
	}
	cin >> n;
	while (n--) {
		bool affected[5] = { false };
		bool clockwise[5] = { false };

		cin >> number >> direction;
		affected[number] = true;
		int idx = number;
		bool flag;
		if (direction==1) flag = true;
		else flag = false;
		clockwise[number] = flag;
		if (number == 4) {
			while (idx > 1 && wheel[idx][6] != wheel[idx - 1][2]) {
				if (idx == 0) break;
				flag = !flag;
				affected[idx - 1] = true;
				clockwise[idx - 1] = flag;
				idx--;
			}
		}

		else if (number == 1) {
			while (idx < 4 && wheel[idx][2] != wheel[idx + 1][6]) {
				if (idx == 4) break;
				flag = !flag;
				affected[idx + 1] = true;
				clockwise[idx + 1] = flag;
				idx++;
			}
		}

		else {
			while (idx<4 && wheel[idx][2] != wheel[idx + 1][6]) {
				if (idx == 4) break;
				flag = !flag;
				affected[idx + 1] = true;
				clockwise[idx + 1] = flag;
				idx++;
			}
			idx = number;
			flag = clockwise[number];

			while (idx>1 && wheel[idx][6] != wheel[idx - 1][2]) {
				if (idx == 0) break;
				flag = !flag;
				affected[idx - 1] = true;
				clockwise[idx - 1] = flag;
				idx--;
			}
		}
		
		for (int j = 1; j < 5; j++) {
			if (affected[j]) {
				rotate_wheel(j, clockwise[j]);
			}
		}


	}



	for (int j = 1; j < 5; j++) {
		if (wheel[j][0]) answer += pow(2, j - 1);
	}

	cout << answer;
	
	return 0;
}
