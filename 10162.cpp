#include <iostream>
using namespace std;

int main(void) {
	int N;
	cin >> N;
	int a = 0;
	int b = 0;
	int c = 0;
	while (N >= 300) {
			N -= 300;
			a++;
		}
	while (N >= 60) {
			N -= 60;
			b++;
		}
	while (N >= 10) {
			N -= 10;
			c++;
		}

	if (N != 0) printf("-1");
	else printf("%d %d %d",a,b,c);

	return 0;
}
