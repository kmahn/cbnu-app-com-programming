/*
  7���� ����: �������� - ���α׷� ����
*/
#include <stdio.h>
#define SIZE 10	// �迭 ũ��

// ������ �����Ͽ� �迭 �ʱ�ȭ
void generate_random(int[]);

// �迭 ���
void print_array(const char *, const int[]);

// ���� ����
void selection_sort(int[]);


int main() {
	// ���� ���� ����
	int data[SIZE], n;

	// �� 3ȸ ����
	for (n = 0; n < 3; n++) {
		// ������ �迭 �ʱ�ȭ �� �迭 ���
		generate_random(data);
		print_array("����: ", data);

		// ���� ���� �� �迭 ���
		selection_sort(data);
		print_array("����: ", data);

		printf("\n");
	}

	return 0;
}

void generate_random(int arr[]) {
	// ������ �����Ͽ� �迭 arr�� �� �Ҵ�
}

void print_array(const char *str, const int arr[]) {
	// �迭 arr ���
}

void selection_sort(int arr[]) {
	// �迭 arr�� ��������
}