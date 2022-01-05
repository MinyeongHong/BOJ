#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    long long a, N;
    vector <long long> num;
    cin >> N;

    a = 0;
    while (N > 0) {
        a++;
        N -= a;
        if (N < 0) {
            break;
        }
        else if (a != N) num.push_back(a);
        else {
            num.push_back(a + N);
            break;
        }
    }

    printf("%zd", num.size());

    return 0;
}
