/*
5주차 예제: 사다리꼴 적분 구현
*/
#include <stdio.h>
#include <math.h>

#define YN(x) (1.0/(1.0 + (x)))

// 함수 원형 선언
double trapez(int);

int main() {

	// 지역 변수 선언
	double log2, integ;
	int steps;

	// log_e 2 구하기
	log2 = log(2.0);
	printf(" 구간    log2                 사다리꼴 적분        오차\n");
	printf("=======================================================================\n");

	// 사다리꼴 적분 계산 및 출력부
	for (steps = 10; steps <= 10000000; steps *= 10) {
		// 임시, 함수 호출로 대치할 부분
		// integ = log2;

		integ = trapez(steps);
		printf("%8d %20.18lf %20.18lf %20.18lf\n", steps, log2, integ, fabs(log2 - integ));
	}

	return 0;
}

double trapez(int steps) {
	double integral, h, x;
	int k;

	integral = 0.0;
	h = 1.0 / steps;

	for (k = 0; k <= steps; k++) {
		x = h * k;
		if ((k == 0) || (k == steps))
			integral += YN(x);
		else
			integral += 2.0 * YN(x);

	}
	integral = h * integral / 2.0;
	return integral;
}