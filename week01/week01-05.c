/**
 1���� �ǽ� ���� 5
 - N!�� ���ϴ� ���α׷�
 - ���α׷��� �����Ͽ� ������ ã�� �����Ͻÿ�.
*/
#include <stdio.h>
#define MAX 20

int fact(int);

int main() {
	for (int i = 0; i <= MAX; i++) {
		printf("%2d! = %d\n", i, fact(i));
	}
}

int fact(int n) {
	int result = 1;
	for (int i = 1; i <= n; i++) {
		result *= i;
	}
	return result;
}

