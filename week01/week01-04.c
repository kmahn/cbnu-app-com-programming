/**
 1주차 실습 예제 4
 - 1 ~ n까지의 곱을 구하는 프로그램
 - 오류가 있는 부분을 찾아 수정
*/
#include <stdio.h>

int main() {
	int n, result = 0;

	printf("Input a number >>> ");
	scanf("%d", &n);

	for (int i = 0; i <= n; i++) {
		result *= i;
	}

	printf("%d\n", result);

	return 0;
}

