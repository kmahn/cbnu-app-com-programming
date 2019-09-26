/*
  5���� ����: ��ٸ��� ���� - ���α׷� ����
*/
#include <stdio.h>
#include <math.h>

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
		integ = log2;
		printf("%8d %20.18lf %20.18lf %20.18lf\n", steps, log2, integ, fabs(log2 - integ));
	}

	return 0;
}