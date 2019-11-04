/*
7���� ����: �������� - ���� ���� �� ��� ����
*/
#include <stdio.h>
#include <stdlib.h> // srand(), rand() �Լ�
#include <time.h>	// time() �Լ�
#define SIZE 10		// �迭 ũ��
#define MAX 1000	// ���� ���� ����

// ������ �����Ͽ� �迭 �ʱ�ȭ
void generate_random(int[]);

// �迭 ���
void print_array(const char *, const int[]);

// ���� ����
void selection_sort(int[]);


int main() {
	// ���� ���� ����
	int data[SIZE], n;

	// ���� ���� �õ尪 �ʱ�ȭ�� �� ����
	srand((unsigned)time(NULL));

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
	int n;

	// �迭�� ũ�⸸ŭ ������ �����Ͽ� �迭�� �Ҵ�
	for (n = 0; n < SIZE; n++) {
		arr[n] = rand() % MAX + 1;
	}
}

void print_array(const char *str, const int arr[]) {
	// �迭 arr ���
	int n;
	printf(str); // �迭�� ���� ���

	// �迭�� ���� ���
	for (n = 0; n < SIZE; n++) printf("%5d", arr[n]);

	// ���� ��� ������ ���� �ٹٲ�
	printf("\n");
}

void selection_sort(int arr[]) {
	// �迭 arr�� ��������
}