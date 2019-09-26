/*
5���� ����: ��ٸ��� ���� ����
*/
#include <stdio.h>
#include <math.h>

#define YN(x) (1.0/(1.0 + (x)))

// �Լ� ���� ����
double trapez(int);

int main() {

	// ���� ���� ����
	double log2, integ;
	int steps;

	// log_e 2 ���ϱ�
	log2 = log(2.0);
	printf(" ����    log2                 ��ٸ��� ����        ����\n");
	printf("=======================================================================\n");

	// ��ٸ��� ���� ��� �� ��º�
	for (steps = 10; steps <= 10000000; steps *= 10) {
		// �ӽ�, �Լ� ȣ��� ��ġ�� �κ�
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