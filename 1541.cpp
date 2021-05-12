#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main(void) {
    string numbers;
    int tmp = 0;
    int a = 0;
    int answer = 0;
    getline(cin,numbers);
    int len = numbers.length();
    int i = len - 1;

    while(i >= 0) {
        if (numbers[i] >= '0' && numbers[i] <= '9') {
            tmp += pow(10, a) * (numbers[i] - 48);
            a++;
        }
        else if (numbers[i] == '-') {
            if (answer > 0) {
                answer += tmp;
                answer *= -1;
            }
            else answer -= tmp;

            tmp = 0;
            a = 0;

        }
        else {
            a = 0;
        }

        i--;
    }

    answer += tmp;

    printf("%d", answer);

    return 0;
}

