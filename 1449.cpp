#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    int N, L, a;
    int answer = 0;
    int idx = 1;
    vector <int> leak_point;
    cin >> N >> L;
    for (int i = 0; i < N; i++) {
        cin >> a;
        leak_point.push_back(a);
    }
    if (N == 1) answer++;
    else {
        sort(leak_point.begin(), leak_point.end());
        answer = N;
        for (int k = 0; k < N - 1; k++) {
            double pivot = leak_point[k] - 0.5 + L;
            for (int j = k + 1; j < N; j++) {
                if (pivot >= leak_point[j] + 0.5) { answer--; k++; }
                else {
                    break;
                }
            }
        }
       
    }

    cout << answer;
    return 0;
}
