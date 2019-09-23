/**
4���� ���� 3��: �����佺�׳׽��� ü
- eratos() �Լ� �� print_primes ����
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// �Լ� ���� ����
void eratos(char[], int);
void print_primes(char*, int);

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
			// printf("%d ���� �迭�� �Ҵ��Ͽ����ϴ�.\n", number + 1);

			// �����佺�׳׽��� ü�� ���ϰ�
			eratos(arr, number);
			// �Ҽ��� ���
			print_primes(arr, number);

			// �޸𸮸� �� ��������� ������ ��
			free(arr);
		}
	}

	return 0;
}

void eratos(char arr[], int number) {
	// ���� ���� ����
	int n, m, to, last, index;

	to = (int)sqrt(number); // ������ ���� ��
	for (n = 2; n <= to; n++) {
		// �̹� �Ҽ��� �ƴ� ��� ������ �ʿ� ����
		if (arr[n] != 0) continue;

		last = number / n;
		for (m = 2; m <= last; m++) {
			index = n * m;
			arr[index] = 1; // �Ҽ��� �ƴ��� ǥ��
		}
	}
}

void print_primes(char *arr, int number) {
	// ���� ���� ����
	int n, count = 0;

	printf("%d�� �Ҽ�:\n", number);
	for (n = 2; n <= number; n++) {
		// �ش� �ε����� �Ҽ��̸� �Ҽ� ���
		if (arr[n] == 0) {
			printf("%9d", n); // ���ڸ� 9ĭ�� ���� ���
			count++;
			if (count % 8 == 0) printf("\n"); // �� �ٿ� 8���� ���
		}
	}
	printf("\n");
}