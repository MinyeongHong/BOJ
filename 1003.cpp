#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>
using namespace std;

int main(void) {
    vector<pair<int, int>> cnt;
    vector <int> arr;
    int T;
    int val;
    cin >> T;
    for (int i = 0; i <T; i++) {
        int a;
        cin >> a;
        arr.push_back(a);
    }

    for (int i = 0; i < T; i++) {
        val = arr[i];
        cnt.clear();
        cnt.push_back(make_pair(1, 0));
        cnt.push_back(make_pair(0,1));
        for (int k = 2; k <= val; k++) {
            cnt.push_back(make_pair(cnt[k-1].first+cnt[k-2].first,cnt[k-1].second+cnt[k-2].second));
        }
        cout << cnt[val].first << ' ' << cnt[val].second<<endl;
    }

    
    return 0;
}