#include <stdio.h>
#include <math.h>

void main() {
	// 지역 변수 선언
	int n;
	double nexp, newexp, oldexp, fact;

	// 라이브러리 함수를 이용해서 자연대수 값 구하기
	nexp = exp(1.0);

	printf(" n 자연대수             계산                 오차\n");
	printf("=================================================================\n");
	
	// 변수 초기화
	n = 1;
	newexp = 0.0;
	oldexp = -1.0;
	fact = 1.0;

	// 자연대수를 구하여 출력
	while (oldexp != newexp) {
		oldexp = newexp;
		newexp = newexp + 1.0 / fact;
		printf("%2d %20.18lf %20.18lf %20.18lf\n", n, nexp, newexp, fabs(nexp - newexp));
		fact = fact * n;
		n++;
	}

	return 0;
}