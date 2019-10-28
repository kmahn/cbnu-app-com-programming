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
void print_array(const char *, int[]);

// ���� ������ ���� ���� �Լ�
int find_min(int[], int);
void swap(int *, int *);
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

void print_array(const char *str, int arr[]) {
	// �迭 arr ���
	int n;
	printf(str); // �迭�� ���� ���

				 // �迭�� ���� ���
	for (n = 0; n < SIZE; n++) printf("%5d", arr[n]);

	// ���� ��� ������ ���� �ٹٲ�
	printf("\n");
}

int find_min(int arr[], int start) {
	// �迭�� start �ε����������� �����Ͽ� ���� �ּҰ��� �ִ� ���� �ε����� ����
	int n, minindex = start;
	for (n = start + 1; n < SIZE; n++) {
		if (arr[minindex] > arr[n]) minindex = n;
	}
	return minindex;
}

void swap(int *px, int *py) {
	// px�� py�� ����Ű�� �޸��� ���� ��ȯ
	int temp = *px;
	*px = *py;
	*py = temp;
}

void selection_sort(int arr[]) {
	// �迭 arr�� ��������
	int n, minindex;
	for (n = 0; n < SIZE - 1; n++) {
		minindex = find_min(arr, n);
		swap(arr + minindex, arr + n);
	}
}
