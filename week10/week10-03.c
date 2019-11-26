#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

#define ENTER 0x0d // Enter 키의 ASCII 코드
#define ESC 0x1b   // ESC 키의 ASCII 코드

typedef struct _ALPHA_NODE ALPHA_NODE;

// 함수 원형 선언
void initialize();
void gotoxy(int, int);
void cursor_off();
char get_alphabet();
int check_node(int, int);
void display_screen();
void clear_screen();
void sleep(clock_t);
void clear_list();
void play_game();

struct _ALPHA_NODE {
	int x;
	int y;
	char alpha;
	ALPHA_NODE *next;
};

ALPHA_NODE *alphalist = NULL;

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
	clear_list();
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
	ALPHA_NODE *temp;

	do {
		x = rand() % 80;
		y = rand() % 25;
	} while (check_node(x, y));

	alpha = rand() % 26 + 'A'; // 대문자 무작위 생성
	temp = (ALPHA_NODE*)malloc(sizeof(ALPHA_NODE));
	temp->x = x;
	temp->y = y;
	temp->alpha = alpha;

	temp->next = alphalist;
	alphalist = temp;
	
	return alpha;
}

int check_node(int x, int y) {
	ALPHA_NODE *search = alphalist;
	while (search) {
		if ((search->x == x) && (search->y == y)) break;
		else search = search->next;
	}
	return search ? 1 : 0;
}

void display_screen() {
	ALPHA_NODE *search = alphalist;
	while (search) {
		gotoxy(search->x, search->y);
		_putch(search->alpha);
		search = search->next;
	}
}

void clear_screen() {
	ALPHA_NODE *search = alphalist;
	while (search) {
		gotoxy(search->x, search->y);
		_putch(' ');
		search = search->next;
	}
}

void sleep(clock_t wait) {
	clock_t goal = clock() + wait;
	while (goal > clock());
}

void clear_list() {
	ALPHA_NODE *temp = alphalist;
	while (alphalist) {
		alphalist = alphalist->next;
		free(temp);
		temp = alphalist;
	}
}

void play_game() {
	int score;
	char keyin, alphabet;
	score = 0;
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

	clear_screen();
}