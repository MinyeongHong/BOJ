
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    int n,a;
    int answer=0;
    int idx =0;
    cin >> n;
    vector<int> store;
    vector<int> drink;
    
    for (int i = 0; i < n; i++) {
        cin >> a;
        store.push_back(a);
    }

    while (store[idx] != 0) {
        if(idx < n-1) idx++;
        else {
            idx = -1;
            break;
        }
    }

    if (idx == -1) {
        answer = 0;
        cout << answer;
        return 0;
    }
    else drink.push_back(store[idx]);

    for (int j = idx+1; j < n; j++) {
        if (drink.back() == 2) {
            if(store[j]==0) drink.push_back(store[j]);
        }
        else if(drink.back() == 1){
            if (store[j]==2) drink.push_back(store[j]);
        }
        else {
            if (store[j] == 1) drink.push_back(store[j]);
        }

    }
    answer = drink.size();
    cout << answer;
    return 0;
}