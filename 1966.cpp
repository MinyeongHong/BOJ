#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include<string>
#include <algorithm>
using namespace std;

int main(void) {
	int T, target_idx,num,a;
	vector<int> answer;
	cin >> T;
	while (T--) {
		queue <pair<int,int>> list;
		vector<int> maxtomin;

		cin >> num >> target_idx;

		for (int i = 0; i < num; i++) {
			cin >> a;
			maxtomin.push_back(a);
			list.push({ a,i });
		}

		sort(maxtomin.rbegin(), maxtomin.rend());
		int index = 0;
		int ans= 0;
		while(!list.empty()){
			if (maxtomin[index] == list.front().first) {
				index++;
				ans++;
				if (target_idx == list.front().second) {
					answer.push_back(ans);
					break;
				}
				list.pop();
			}
			else {
				list.push(list.front());
				list.pop();
			}

		}

		

	}

	for (auto itr = answer.begin(); itr != answer.end(); itr++) printf("%d\n", *itr);
	return 0;
}
