#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

#define ESC 0x1b // ESC 키의 ASCII 코드

// 함수 원형 선언
void initialize();
void gotoxy(int, int);
void cursor_off();

int main() {
	char ch = 0;

	// 게임 초기화
	initialize();

	while (ch != ESC) {
		gotoxy(0, 24);
		printf("게임을 시작하려면 엔터, 종료하려면 ESC를 누르세요.");
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