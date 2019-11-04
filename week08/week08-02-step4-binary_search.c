#include <stdio.h>
#include <stdlib.h>

void print_array(const char *, const int[], int);
int *read_data(int *);
int binary_search(const int[], int, int);

int main() {
	// ���� ���� �� �ʱ�ȭ
	int *data = NULL;
	int size = 0;
	int index, key = 1, i;

	// ���Ͽ��� ������ �б�
	data = read_data(&size);
	print_array("����: ", data, size);

	while (1) {
		printf("�˻��� ���� �Է��Ͻÿ�: "); // ������� �Է��� �޴´�.
		scanf("%d", &key);

		// �Է°��� 1���� ������ ���α׷� ����
		if (key < 1) break;

		// key�� Ž���ϰ� ����� ����Ѵ�. ������ �̷�
		index = binary_search(data, size, key);
		if (index != -1) {
			printf("�����Ͱ� %d��°�� �ֽ��ϴ�.\n", index + 1);
		}
		else {
			printf("�����Ͱ� ���Ͽ� �����ϴ�.\n");
		}
	}

	printf("���α׷��� �����մϴ�.\n\n");

	if (data) {
		// ���� �Ҵ��� �� data�� ����Ű�� �޸� ����
		free(data);
	}

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

int *read_data(int *psize) {
	int *arr = NULL, size = 0, i;
	char temp[20];	// �ӽ� ����
	const char *FILE_PATH = "sorted.txt";	// �Է� ���� ���
	FILE *fp = fopen(FILE_PATH, "r");		// �б� ���� ���� ����

	if (fp) {
		fscanf(fp, "%s %d", temp, &size); // "����: �����ͼ�" �Է� - temp�� ������ �о���̰� ����(���α׷����� ���ʿ��� ��)
		if (size > 0) {
			// ���� �����Ͱ� �ִٸ�, �迭�� ���� �����͸�ŭ ���� �Ҵ�
			arr = (int *)malloc(sizeof(int) * size);
			for (i = 0; i < size; i++) {
				fscanf(fp, "%d", arr + i);
			}
		}
		fclose(fp);
	}
	else {
		printf("������ �������� �ʽ��ϴ�.\n");
	}
	*psize = size;
	return arr;
}

int binary_search(const int arr[], int size, int key) {
	int low = 0, high =  size - 1, center;

	while (low <= high) {
		center = (low + high) / 2;

		if (key == arr[center]) return center;
		else if (key > arr[center]) low = center + 1;
		else high = center - 1;
	}

	return -1;
}
