/*
  5주차 예제: 원주율 구현
*/
#include <stdio.h>
#include <math.h>

void main() {
	// 지역 변수 선언
	int n, sign;
	double PI, pi1, pi2, pi2sqr;

	// 원주율 계산
	PI = 4.0 * atan(1.0);

	// 헤더 출력
	printf("원주율 = %10.8lf\n", PI);
	printf("==================================================================\n");
	printf("항의 수\t공식1\t        오차\t        공식2\t        오차\n");
	printf("==================================================================\n");

	// 변수 초기화
	pi1 = 0.0;
	pi2sqr = 0.0;
	sign = -1;

	// 원주율 계산 및 1000항 마다 원주율 출력
	for (n = 1; n <= 10000; n++) {
		sign *= -1;
		pi1 += sign * 4.0 / (2.0 * n - 1.0);
		pi2sqr += 6.0 / ((double)n * (double)n);
		pi2 = sqrt(pi2sqr);
		if (n % 1000 == 0)
			printf("%6d\t%10.8lf\t%10.8lf\t%10.8lf\t%10.8lf\n", n, pi1, fabs(PI - pi1), pi2, fabs(PI - pi2));
	}
}