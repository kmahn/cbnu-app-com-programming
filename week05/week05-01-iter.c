/*
 5 주차 예제: 팩토리얼 - 반복
*/
#include <stdio.h>

int main() {
	// 지역 변수 선언
	int n;
	int ifact = 1;
	double dfact = 1.0;

	// 팩토리얼 계산
	printf("n      정수 팩토리얼        실수 팩토리얼\n");
	printf("===========================================\n");
	for (n = 1; n <= 20; n++) {
		ifact = ifact * n;
		dfact = dfact * n;
		printf("%2d: %20d %20.0lf\n", n, ifact, dfact);
	}

	return 0;
}