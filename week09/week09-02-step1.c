#include <stdio.h>
#define MAXWORD 100 // 단어 최대 수

// 함수 원형 선언부
void get_words();
void sort_string();
void print_words();
void deallocate();

// 전역 변수 선언
char *pstrarray[MAXWORD]; // 단어를 저장할 문자 포인터 배열
int nword;

int main() {
	get_words();    // 사용자로부터 단어를 입력 받아 저장
	sort_string();  // 단어를 오름차순으로 정렬
	print_words();  // 정렬된 단어를 출력
	deallocate();   // 할당 받은 공간을 해제
}

void get_words() {
	// 구현을 미룸
}

void sort_string() {
	// 구현을 미룸
}

void print_words() {
	// 구현을 미룸
}

void deallocate() {
	// 구현을 미룸
}
