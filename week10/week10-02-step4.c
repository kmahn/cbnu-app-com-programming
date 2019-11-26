#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

#define ENTER 0x0d // Enter 키의 ASCII 코드
#define ESC 0x1b   // ESC 키의 ASCII 코드

// 함수 원형 선언
void initialize();
void gotoxy(int, int);
void cursor_off();
char get_alphabet();
void display_screen();
void clear_screen();
void sleep(clock_t);
void clear_array();
void play_game();

char screen[25][80];

int main() {
	char ch = 0;

	// 게임 초기화
	initialize();

	while (ch != ESC) {
		gotoxy(0, 24);
		printf("게임을 시작하려면 엔터, 종료하려면 ESC를 누르세요.");
		ch = _getch();
		if (ch == ENTER) {
			system("cls");
			gotoxy(0, 24);
			printf("점수: %4d", 0);
			play_game(); // 게임 시작
		}
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

	alpha = rand() % 26 + 'A'; // 대문자 무작위 생성
	screen[y][x] = alpha; // 문자 저장
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

void clear_array() {
	memset(screen, 0, 25 * 80);
}

void play_game() {
	int score;
	char keyin, alphabet;

	score = 0;
	clear_array(); // screen[][] 배열 초기화
	do {
		clear_screen();
		sleep(1000);
		alphabet = get_alphabet();
		display_screen();
		keyin = _getch();
		keyin = toupper(keyin);
		if (keyin == alphabet) {
			score++;
			gotoxy(0, 24);
			printf("점수: %4d", score);
		}
	} while (keyin == alphabet);
}