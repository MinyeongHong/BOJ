#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;

int main(void) {
	int N,K;
	int p = 2;
	cin >> N >> K;
	vector <bool> v(N+1, true );
	while (K > 0) {
		for (int i = 2; i <= N; i++) {
			if (v[i] && i% p == 0) {
				v[i] = false;
				K--;
				if (K == 0) {
					printf("%d", i);
					return 0;
				}
			}
		}
		p++;
	}

	return 0;
}
