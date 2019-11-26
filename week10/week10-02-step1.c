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

int main() {
	char ch = 0;

	// ���� �ʱ�ȭ
	initialize();

	while (ch != ESC) {
		gotoxy(0, 24);
		printf("������ �����Ϸ��� ����, �����Ϸ��� ESC�� ��������.");
		ch = _getch();
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