#include <iostream>
#include <vector>

using namespace std;

int solution(int n) {
    if (n == 1) return 1;
    if (n == 2) return 2;
    if (n == 3) return 4;
    if (n > 3) {
        return solution(n - 1) + solution(n - 2) + solution(n - 3);
    }
}


int main(void) {
    int T,n;
    vector<int> answer;
    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> n;
        answer.push_back(solution(n));
    }
    for (auto itr = answer.begin(); itr < answer.end(); itr++) printf("%d\n", *itr);
    
    return 0;
}
