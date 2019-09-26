#include <stdio.h>
#include <math.h>

void main() {
	// ���� ���� ����
	int n;
	double nexp, newexp, oldexp, fact;

	// ���̺귯�� �Լ��� �̿��ؼ� �ڿ���� �� ���ϱ�
	nexp = exp(1.0);

	printf(" n �ڿ����             ���                 ����\n");
	printf("=================================================================\n");
	
	// ���� �ʱ�ȭ
	n = 1;
	newexp = 0.0;
	oldexp = -1.0;
	fact = 1.0;

	// �ڿ������ ���Ͽ� ���
	while (oldexp != newexp) {
		oldexp = newexp;
		newexp = newexp + 1.0 / fact;
		printf("%2d %20.18lf %20.18lf %20.18lf\n", n, nexp, newexp, fabs(nexp - newexp));
		fact = fact * n;
		n++;
	}

	return 0;
}