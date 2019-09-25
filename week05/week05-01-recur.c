/*
5 주차 예제: 팩토리얼 - 순환
*/
#include <stdio.h>

long long factorial(int n);

int main() {
	int n;
	long long ifact = 1LL;

	printf("n    정수 팩토리얼\n");
	printf("========================\n");

	for (n = 1; n <= 20; n++) {
		ifact = factorial(n);
		printf("%2d: %20lld\n", n, ifact);
	}

	return 0;
}

long long factorial(int n) {
	if (n <= 1) return 1;
	else return n * factorial(n - 1);
}