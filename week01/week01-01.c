/**
 1���� �ǽ� ���� 1
 - ���밪�� ����ϴ� ���α׷��� ����� ����
 - �����Ͽ� �� �� ���� ���ʷ� ������ ����.
*/
#include <stdio.h>

int main() {
	int n, a;

	printf("Input a number >>> ");
	scanf("%d", &n);

	if (n > 0) {
		a = -n;
	}
	else {
		a = n;
	}

	printf("|%d| = %d\n", a, n);

	return 0;
}

