#include <stdio.h>

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
			printf("%d�� ���� ����� ���մϴ�.\n", number);
		}
		else {
			printf("%d�� ���� ����� ���� �� �����ϴ�.\n", number);
			break;
		}
		printf("\n");
	}

	return 0;
}