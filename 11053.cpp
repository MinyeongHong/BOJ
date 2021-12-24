
#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>

using namespace std;

int main(void) {
    int arr[1001][2] = { 0 };
    int N, val;
    int answer = 1;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        arr[i][0] = a;
    }

    arr[0][1] = 1;

    for (int j = 1; j < N; j++) {
        for (int k = j - 1; k >= 0; k--) {
            if (arr[j][0] > arr[k][0]) {
                arr[j][1] = max(arr[j][1], arr[k][1] + 1);
            }
            else if (arr[j][1] == 0) {
                arr[j][1] = 1;
            }
            
        }
        if (answer < arr[j][1]) answer = arr[j][1];
    }

    cout << answer;

    return 0;
}