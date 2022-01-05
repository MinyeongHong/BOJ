#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    int A,B;
    int answer = 0;
    cin >> A >> B;
    while (B > A) {
        if (B % 10 == 1) {
            B = B / 10;
            answer++;
        }
        else if (B % 2 == 0) {
            B = B / 2;
            answer++;
        }
        else {
            break;
        }
    }

    if (B == A) answer++;
    else answer = -1;
    printf("%d",answer);

    return 0;
}
