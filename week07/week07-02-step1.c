/*
7���� ����: �������� - ���α׷� ����
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 1000

void generate_random(int[], int);
void print_array(const char *, int[], int);

int main() {
	// ���� ���� ����
	int *data, size;

	// ���� ���� �õ尪 �ʱ�ȭ(�ѹ��� ȣ��)
	srand((unsigned)time(NULL));

	// �迭�� ũ�� �Է�
	printf("�迭�� ũ�⸦ �Է��ϼ���: ");
	scanf("%d", &size);

	// ���� �迭
	data = (int *)malloc(sizeof(int) * size);

	generate_random(data, size);
	print_array("����: ", data, size);

	// ���� ����: ������ �̷�
	print_array("����: ", data, size);

	// ���Ͽ� ����: ������ �̷�(8�忡�� ����)

	// ���� �޸� ����
	free(data);

	return 0;
}


void generate_random(int arr[], int size) {
	int n;

	// size��ŭ�� ������ �����Ͽ� �迭 arr�� ����
	for (n = 0; n < size; n++) arr[n] = rand() % MAX + 1;
}

void print_array(const char *str, int arr[], int size) {
	int n;

	printf("%s %d\n", str, size);

	for (n = 0; n < size; n++) {
		printf("%5d", arr[n]);

		// ���ٿ� 10 ���� ���
		if ((n + 1) % 10 == 0) printf("\n");
	}
	printf("\n");
}
