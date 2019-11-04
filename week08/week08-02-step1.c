#include <stdio.h>

void print_array(const char *, const int[], int);

int main() {
	// ���� ���� �� �ʱ�ȭ
	int data[] = { 1, 2, 3, 4, 5, 6, 7 }; // �ӽ÷� �迭 ���� -> ���� �����迭�� ����
	int size = 7; // �ӽ÷� �迭�� ũ�⸦ 7�� ���Ѵ�.
	int index, key = 1;

	// ���Ͽ��� ������ �б�
	print_array("����: ", data, size);

	while (1) {
		printf("�˻��� ���� �Է��Ͻÿ�: "); // ������� �Է��� �޴´�.
		scanf("%d", &key);

		// �Է°��� 1���� ������ ���α׷� ����
		if (key < 1) break;

		// key�� Ž���ϰ� ����� ����Ѵ�. ������ �̷�
		printf("%d�� Ž���մϴ�.\n", key);
	}

	printf("���α׷��� �����մϴ�.\n\n");

	return 0;
}

void print_array(const char *str, const int arr[], int size) {
	int i;
	printf("%s %d\n", str, size);
	for (i = 0; i < size; i++) {
		printf("%5d", arr[i]);
		if ((i + 1) % 10 == 0) printf("\n");
	}
	printf("\n");
}
