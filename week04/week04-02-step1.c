#include <stdio.h>

int main() {
	// �������� ����
	int number;

	while (1) {
		printf("�Ҽ��� ������ ������ �Է��ϼ���(1 ������ ���̸� ����): ");
		scanf("%d", &number);
		if (number >= 2) {
			// ������ �������� �̷�
			printf("%d�� ���� �Ҽ��� �����մϴ�.\n", number);
		}
		else {
			printf("%d�� ���� �Ҽ��� ������ �� �����ϴ�.\n", number);
			printf("���α׷��� �����մϴ�.\n");
			return 0;
		}
	}
}
