/*
6���� ����: ���� ���� - print_winner() ����
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initialize();
// �Լ� ���� �߰�
void set_rand(int *);
void swap(int *, int *);

void erase_bingo(int[][5], int);
void print_bingo(int[][5]);
void print_winner(int winner);

// get_number() �Լ��� ���� �������� �߰�
int checked[25];
int count = 0;
int get_number(int);

int check_bingo(int[][5]);

// ������
int ubingo[5][5];
int cbingo[5][5];


void main() {
	// �������� ����
	int number, uwin, cwin;

	// ������ �ʱ�ȭ
	initialize();

	do {
		// ������� ������ ���
		printf("�����\n");
		print_bingo(ubingo);

		// ����ڰ� ��ȣ�� ����
		number = get_number(0);
		// ����ڰ� ������ ��ȣ�� ������ �����ǿ��� ����
		erase_bingo(ubingo, number);
		erase_bingo(cbingo, number);

		// ��ǻ�Ͱ� ��ȣ�� ����
		number = get_number(1);
		// ��ǻ�Ͱ� ������ ��ȣ�� ������ �����ǿ��� ����
		erase_bingo(ubingo, number);
		erase_bingo(cbingo, number);

		// ����ڰ� ���� �ϼ��ߴ��� üũ
		uwin = check_bingo(ubingo);

		// ��ǻ�Ͱ� ���� �ϼ��ߴ��� üũ
		cwin = check_bingo(cbingo);
	} while (uwin + cwin == 0); // �Ѵ� �ϼ����� ���� ���� �ݺ�

								// ����ڿ� ��ǻ���� �������� ���
	printf("�����\n");
	print_bingo(ubingo);
	printf("��ǻ��\n");
	print_bingo(cbingo);

	print_winner(cwin * 2 + uwin); // ���ڸ� ǥ��: 1�̸� ����ڰ� �¸�, 2�̸� ��ǻ�Ͱ� �¸�, 3�̸� ���º�

	return 0;
}

void initialize() {
	// ���� ������ ���� �õ尪 ����
	srand((unsigned)time(NULL));

	// ���� �� ����
	set_rand((int *)ubingo);
	set_rand((int *)cbingo);
}

void set_rand(int *arr) {
	int i;

	// �������� 1 ~ 25���� ������� ä�� ��
	for (i = 0; i < 25; i++) arr[i] = i + 1;
	// ���� ���ڵ��� ����
	for (i = 0; i < 25; i++) swap(arr + i, arr + rand() % 25);
}

void swap(int *x, int *y) {
	int t = *x;
	*x = *y;
	*y = t;
}

void erase_bingo(int bingo[][5], int number) {
	int x, y;
	for (y = 0; y < 5; y++) {
		for (x = 0; x < 5; x++) {
			// ��ȣ�� ��ġ�ϴ� ���� ã�� �����.
			if (bingo[y][x] == number) bingo[y][x] = 0;
		}
	}
}

void print_bingo(int bingo[][5]) {
	int x, y;
	for (y = 0; y < 5; y++) {
		for (x = 0; x < 5; x++) {
			if (bingo[y][x] != 0) {
				printf("%5d", bingo[y][x]);
			}
			else {
				printf("   XX");
			}
		}
		printf("\n");
	}
}

void print_winner(int winner) {
	switch (winner) {
		case 1: printf("����ڰ� �̰���ϴ�.\n"); break;
		case 2: printf("��ǻ�Ͱ� �̰���ϴ�.\n"); break;
		case 3: printf("�����ϴ�.\n"); break;
		default: printf("���� �̻��մϴ�.\n");
	}
}

int get_number(int from) {
	int number;
	int x, retry;

	do {
		retry = 0;
		if (from == 0) {
			printf("1 ~ 25 ������ ���ڸ� �Է��ϼ���: ");
			scanf("%d", &number);
			if (number < 1 || number > 25) retry = 1;
		}
		else {
			number = rand() % 25 + 1;
		}

		if (retry == 0) {
			for (x = 0; x < count; x++) {
				if (checked[x] == number) {
					retry = 1;
					break;
				}
			}
		}
	} while (retry == 1);

	checked[count++] = number;

	if (from == 0) printf("����ڰ� %d�� �����߽��ϴ�.\n", number);
	else printf("��ǻ�Ͱ� %d�� �����߽��ϴ�.\n", number);

	return number;
}

int check_bingo(int bingo[][5]) {
	int x, y, sum;

	// �����ٷ� ������ ���� ã��
	for (y = 0; y < 5; y++) {
		sum = 0;
		for (x = 0; x < 5; x++) sum += bingo[y][x];
		if (sum == 0) return 1;
	}

	// �����ٷ� ������ ���� ã��
	for (x = 0; x < 5; x++) {
		sum = 0;
		for (y = 0; y < 5; y++) sum += bingo[y][x];
		if (sum == 0) return 1;
	}

	// �»� -> ���� �밢�� ���� Ȯ��
	sum = 0;
	for (x = 0; x < 5; x++) sum += bingo[x][x];
	if (sum == 0) return 1;

	// ���� -> ��� �밢�� ���� Ȯ��
	sum = 0;
	for (x = 0; x < 5; x++) sum += bingo[x][5 - x - 1];
	if (sum == 0) return 1;

	return 0;

}
