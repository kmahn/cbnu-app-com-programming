/*
6���� ����: �ִ밪 ã�� - ���α׷� ����
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
	// �迭 ���
}

int find_max(int array[]) {
	// �迭(array)���� �ִ밪�� �ִ� ���� �ε����� ã�� ����
	return 1;
}