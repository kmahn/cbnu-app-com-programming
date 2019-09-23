/**
4���� ���� 2��: �Ҽ� ���� ���α׷�
- �ݺ��� ���� ��� 1
*/
#include <stdio.h>
#include <math.h>

// �Լ� ���� ����
int is_prime(int);

int main() {
	// �������� ����
	int number;

	while (1) {
		printf("�Ҽ��� ������ ������ �Է��ϼ���(1 ������ ���̸� ����): ");
		scanf("%d", &number);
		if (number >= 2) {
			// ������ �������� �̷�
			// printf("%d�� ���� �Ҽ��� �����մϴ�.\n", number);

			// �Ҽ� �����Ͽ� ���
			if (is_prime(number)) {
				printf("%d��(��) �Ҽ��Դϴ�.\n\n", number);
			}
			else {
				printf("%d��(��) �Ҽ��� �ƴմϴ�.\n\n", number);
			}
		}
		else {
			printf("%d�� ���� �Ҽ��� ������ �� �����ϴ�.\n", number);
			printf("���α׷��� �����մϴ�.\n");
			return 0;
		}
	}
}

int is_prime(int n) {
	// �������� ���� �� �ʱ�ȭ
	int divider = 2, to = (int)sqrt(n);

	// 2 ~ n�� �����ٱ��� �ݺ��� �ϸ鼭 �������� 0�� ���� �ϳ��� ������ �Ҽ��� �ƴ�
	while (divider < n) {
		if (n % divider == 0) return 0;
		divider++;
	}

	return 1;
}