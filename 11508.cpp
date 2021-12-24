
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    int n,a;
    int answer=0;
    int idx =0;
    cin >> n;
    vector<int> price;
    
    for (int i = 0; i < n; i++) {
        cin >> a;
        price.push_back(a);
        answer += a;
    }

    sort(price.begin(), price.end());

    if (n % 3 == 0) {
        for (int i = 0; i < n; i+=3) {
            answer -= price[i];
        }
    }
    else {

        for (int i = n % 3; i < n; i += 3) {
            answer -= price[i];
        }
    }

    cout << answer;
    return 0;
}
//123 456 789 33
//455 556