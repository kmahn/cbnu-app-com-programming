/*
6���� ����: ���� ���� - ���� ����
*/
#include <stdio.h>

void initialize();
void erase_bingo(int[][5], int);
void print_bingo(int[][5]);
void print_winner(int winner);
int get_number(int);
int check_bingo(int [][5]);

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

		// ����ڰ� ������ �ϼ��ߴ��� üũ
		uwin = check_bingo(ubingo);

		// ��ǻ�Ͱ� ������ �ϼ��ߴ��� üũ
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
}

void erase_bingo(int bingo[][5], int number) {
}

void print_bingo(int bingo[][5]) {
}

void print_winner(int winner) {
}

int get_number(int from) {
	return 1;
}

int check_bingo(int bingo[][5]) {
	return 1;
}