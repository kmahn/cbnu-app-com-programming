/**
 1주차 실습 예제 5
 - N!을 구하는 프로그램
 - 프로그램을 실행하여 오류를 찾아 수정하시오.
*/
#include <stdio.h>
#define MAX 20

int fact(int);

int main() {
	for (int i = 0; i <= MAX; i++) {
		printf("%2d! = %d\n", i, fact(i));
	}
}

int fact(int n) {
	int result = 1;
	for (int i = 1; i <= n; i++) {
		result *= i;
	}
	return result;
}

