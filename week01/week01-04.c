/**
 1���� �ǽ� ���� 4
 - 1 ~ n������ ���� ���ϴ� ���α׷�
 - ������ �ִ� �κ��� ã�� ����
*/
#include <stdio.h>

int main() {
	int n, result = 0;

	printf("Input a number >>> ");
	scanf("%d", &n);

	for (int i = 0; i <= n; i++) {
		result *= i;
	}

	printf("%d\n", result);

	return 0;
}

