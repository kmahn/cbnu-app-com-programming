#include <stdio.h>

// ������ �Ǻ��Լ� ���� ����
int is_perfect_number(int);

int main() {
	// ���� ���� ����
	int number, n;

	printf("1000 ������ ������:\n");
	for (number = 1; number <= 1000; number++) {
		// ������ �ӽ� ���
		// printf("%d�� ���������� üũ�غ��ô�.\n", number);
		if (is_perfect_number(number)) {
			printf(" %d \n", number);
		}
	}

	return 0;
}


// ������ �Ǻ� �Լ� ����
int is_perfect_number(int number) {
	// �������� ���ϱ� ���� �ε��� i, ����� ���� ���ϱ� ���� sum ���� ����(�ʱ�ȭ�� 0)
	int i, sum = 0;

	for (i = 1; i < number; i++) {
		// i�� number�� ������ ���� ���� ����
		if (number % i == 0) sum += i;
	}

	// ���� ���� ������ ���� �ƴϸ� ������ ����
	if (sum == number) return 1;
	else return 0;

	// �� if-else ������ �Ʒ��� ���� �����ϰ� ǥ�� ����
	// return sum == number;
}