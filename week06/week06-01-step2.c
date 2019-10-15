/*
6���� ����: �ִ밪 ã��
*/
#include <stdio.h>
#define SIZE 10

void print_array(int[]);
int find_max(int[]);

int main() {

	// �������� ���� �� �ʱ�ȭ
	int data[SIZE] = { 3, 2, 9, 7, 1, 4, 8, 0, 6, 5 };
	int maxindex;

	// �迭 ���
	print_array(data);

	// �迭 ��� �� �ִ밪�� ����� �ε��� ���ϱ�
	maxindex = find_max(data);

	// ���
	printf("�ִ밪: data[%d] = %d\n", maxindex, data[maxindex]);

	return 0;
}

void print_array(int array[]) {
	int n;
	printf("�迭�� ��\n");
	for (n = 0; n < SIZE; n++) {
		// �迭 �������
		printf("data[%d]=%d ", n, array[n]);

		// 5������ �� �ٲ�
		if ((n + 1) % 5 == 0)
			printf("\n");
	}
}

int find_max(int array[]) {
	int n;
	int maxindex = 0; // 0��° ���Ұ� �ִ밪�̶� ����

	// �ִ밪�� �ִ� ������ �ε��� ���ϱ�
	for (n = 1; n < SIZE; n++) {
		if (array[maxindex] < array[n])
			maxindex = n;
	}

	return maxindex;
}