#include <stdio.h>

// �Լ� ���� ����
void print_divisor(int);

int main() {
	// ���� ���� ����
	int number;

	while (1) {

		// ������ �Էº�
		printf("����� ���� ������ �Է��ϼ���(1 ������ ���� ����): ");
		scanf("%d", &number);

		// ����� ���� �� �ִ� ���� �Է�
		if (number >= 2) {
			// �ӽ÷� �޽��� ���
			// printf("%d�� ���� ����� ���մϴ�.\n", number);
			// number�� ���� ����� ����Ѵ�.
			print_divisor(number);
		}
		else {
			printf("%d�� ���� ����� ���� �� �����ϴ�.\n", number);
			break;
		}
		printf("\n");
	}

	return 0;
}

void print_divisor(int value) {
	// ���� ���� ����
	int n, remains;

	printf("%d�� ���: ", value);
	for (n = 1; n <= value; n++) {
		// value�� n���� ���� ������
		remains = value % n;

		// remains == 0, �������� 0�̸� n�� value�� ���
		if (!remains) {
			printf("%d ", n);
		}
	}
	printf("\n");
}