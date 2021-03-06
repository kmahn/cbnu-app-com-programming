#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
	// 지역 변수 선언
	char buffer[100], *tmp; // 사용자가 입력한 문자열 저장, 기억 공간 할당용(동적 할당)
	int size; // 받은 문자열의 길이

	nword = 0;
	printf("단어를 입력하세요. 최대 단어수는 100개입니다.\n");
	printf("입력을 중지하려면 엔터를 입력하세요\n\n");

	while (nword < MAXWORD) {
		printf("%d. 단어 입력: ", nword + 1);
		gets(buffer);

		// 입력된 단어가 빈문자열이면 입력을 마침
		if (strcmp(buffer, "") == 0) break;

		size = strlen(buffer) + 1; // 단어의 크기를 구하고
		pstrarray[nword] = (char *)malloc(sizeof(char) * size); // 단어를 저장할 기억공간을 할당
		strcpy(pstrarray[nword++], buffer); // 단어를 복사
	}
}

void sort_string() {
	int n, m, minindex;
	char *tmp;

	for (n = 0; n < nword - 1; n++) {
		minindex = n;
		for (m = n; m < nword; m++) {
			if (strcmp(pstrarray[minindex], pstrarray[m]) > 0) minindex = m;
		}
		// 아래의 내용을 swap 함수로 분리해도 됨
		tmp = pstrarray[minindex];
		pstrarray[minindex] = pstrarray[n];
		pstrarray[n] = tmp;
	}
}

void print_words() {
	int n;
	printf("\n정렬 후 출력: 단어 수 = %d\n", nword);
	for (n = 0; n < nword; n++) {
		puts(pstrarray[n]);
	}
}

void deallocate() {
	int n;

	// 입력된 모든 단어에 대해서 반복하면서
	for (n = 0; n < nword; n++) {
		if (pstrarray[n] != NULL) {
			// 기억 공간 해제
			free(pstrarray[n]);
			pstrarray[n] = NULL;
		}
	}
}
