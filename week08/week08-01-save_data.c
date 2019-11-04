/*
8���� ����: �������� - print_array() �Լ� ����
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 1000
#define OUTPUT_FILE "sorted.txt"

void generate_random(int[], int);
void print_array(FILE * const, const char *, const int[], int);
void save_data(const int[], int);

// �������� ���� �Լ�
void bubble_sort(int[], int);
void bubble(int[], int);
void swap(int*, int*);

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
	print_array(stdout, "����: ", data, size);

	// ���� ���� ����
	bubble_sort(data, size);
	print_array(stdout, "����: ", data, size);

	// ���Ͽ� ����: ������ �̷�
	save_data(data, size);

	// ���� �޸� ����
	free(data);

	return 0;
}


void generate_random(int arr[], int size) {
	int n;

	// size��ŭ�� ������ �����Ͽ� �迭 arr�� ����
	for (n = 0; n < size; n++) arr[n] = rand() % MAX + 1;
}

void print_array(FILE * const fp, const char *str, const int arr[], int size) {
	int n;

	// printf("%s %d\n", str, size);
	fprintf(fp, "%s %d\n", str, size);


	for (n = 0; n < size; n++) {
		// printf("%5d", arr[n]);
		fprintf(fp, "%5d", arr[n]);

		// ���ٿ� 10 ���� ���
		//if ((n + 1) % 10 == 0) printf("\n");
		if ((n + 1) % 10 == 0) fprintf(fp, "\n");

	}
	// printf("\n");
	fprintf(fp, "\n");
}

void save_data(const int arr[], int size) {
	FILE *fp;

	fp = fopen(OUTPUT_FILE, "w");
	if (fp) {
		print_array(fp, "����: ", arr, size);
		fclose(fp);
	}
}

void bubble_sort(int arr[], int size) {
	int n;

	// arr[0] ~ arr[size - n - 1] �߿���
	for (n = 0; n < size - 1; n++) {
		bubble(arr, size - n - 1); // ���� ū ���� size - n - 1�� ����
	}
}

void bubble(int arr[], int last) {
	int m;
	for (m = 0; m < last; m++) {
		// ���� ���Ұ� ���� ���Һ��� ũ�� ��ȯ
		if (arr[m] > arr[m + 1]) swap(arr + m, arr + m + 1);
	}
}

void swap(int *px, int *py) {
	// �� �� ��ȯ
	int tmp = *px;
	*px = *py;
	*py = tmp;
}