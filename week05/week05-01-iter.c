/*
 5 ���� ����: ���丮�� - �ݺ�
*/
#include <stdio.h>

int main() {
	// ���� ���� ����
	int n;
	int ifact = 1;
	double dfact = 1.0;

	// ���丮�� ���
	printf("n      ���� ���丮��        �Ǽ� ���丮��\n");
	printf("===========================================\n");
	for (n = 1; n <= 20; n++) {
		ifact = ifact * n;
		dfact = dfact * n;
		printf("%2d: %20d %20.0lf\n", n, ifact, dfact);
	}

	return 0;
}