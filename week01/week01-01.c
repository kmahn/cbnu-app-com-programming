/**
 1주차 실습 예제 1
 - 절대값을 출력하는 프로그램을 디버깅 모드로
 - 실행하여 한 줄 한줄 차례로 실행해 보자.
*/
#include <stdio.h>

int main() {
	int n, a;

	printf("Input a number >>> ");
	scanf("%d", &n);

	if (n > 0) {
		a = -n;
	}
	else {
		a = n;
	}

	printf("|%d| = %d\n", a, n);

	return 0;
}

