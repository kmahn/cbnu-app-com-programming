/**
4���� ���� 3��: �����佺�׳׽��� ü
- main �Լ� ����
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
	// ���� ���� ����
	int number;
	char *arr;

	// �Է�
	printf("������ �Է��Ͻÿ�: ");
	scanf("%d", &number);

	if (number > 2) {
		arr = (char *)calloc(number + 1, sizeof(char));
		if (arr) {
			// �����佺�׳׽��� ü�� ���� ������ �̷�
			printf("%d ���� �迭�� �Ҵ��Ͽ����ϴ�.\n", number + 1);

			// �޸𸮸� �� ��������� ������ ��
			free(arr);
		}
	}

	return 0;
}