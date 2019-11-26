#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

#define ESC 0x1b // ESC Ű�� ASCII �ڵ�

// �Լ� ���� ����
void initialize();
void gotoxy(int, int);
void cursor_off();
char get_alphabet();
void display_screen();
void clear_screen();
void sleep(clock_t);

char screen[25][80];

int main() {
	char ch = 0;

	// ���� �ʱ�ȭ
	initialize();

	while (ch != ESC) {
		gotoxy(0, 24);
		printf("������ �����Ϸ��� ����, �����Ϸ��� ESC�� ��������.");
		get_alphabet();
		display_screen();
		ch = _getch();
		clear_screen();
		sleep(1000);
	}
}

void initialize() {
	srand((unsigned)time(NULL));
	cursor_off();
}

void gotoxy(int x, int y) {
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void cursor_off() {
	CONSOLE_CURSOR_INFO coff = { 100, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &coff);
}

char get_alphabet() {
	int y, x;
	char alpha;

	do {
		x = rand() % 80;
		y = rand() % 25;
	} while (screen[y][x]);

	alpha = rand() % 26 + 'A'; // �빮�� ������ ����
	screen[y][x] = alpha; // ���� ����
	return alpha;
}

void display_screen() {
	int y, x;
	for (y = 0; y < 24; y++) {
		for (x = 0; x < 80; x++) {
			if (screen[y][x]) {
				gotoxy(x, y);
				_putch(screen[y][x]);
			}
		}
	}
}

void clear_screen() {
	int y, x;
	for (y = 0; y < 24; y++) {
		for (x = 0; x < 80; x++) {
			if (screen[y][x]) {
				gotoxy(x, y);
				_putch(' ');
			}
		}
	}
}

void sleep(clock_t wait) {
	clock_t goal = clock() + wait;
	while (goal > clock());
}