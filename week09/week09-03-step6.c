#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 파일에 들어 있는 단어의 최대 수
#define MAXWORD 1000
#define DELEMETERS " ,.!?\t\n"

// 함수 원형 선언
void initialize();
void read_file();
void move_downward(int);
void insert_data(int, const char *);
void print_words();
void deallocate();
void convert_lower(char *);
int linear_search(const char *, int *);

// 단어를 저장할 구조체 선언
struct word_count {
	char *str; // 단어를 저장할 문자형 포인터
	int count; // 단어가 나타난 횟수
};

// 단어를 저장할 배열(포인터로 선언)
struct word_count *words;

// 배열에 저장되어 있는 단어 수
int nwords;

int main() {
	initialize();  // 구조체 배열을 할당하고 초기화
	read_file();   // 파일에서 단어를 추출하여 words[]에 저장
	print_words(); // words[]에 저장되어 있는 단어와 횟수를 출력
	deallocate();  // 동적으로 할당 받은 기억장소를 해제
	return 0;
}

void initialize() {
	// 구조체 배열을 동적으로 할당하고 관련 변수 초기화
	words = (struct word_count *) malloc(sizeof(struct word_count) * MAXWORD);
	memset(words, 0, sizeof(struct word_count) * MAXWORD);
	nwords = 0;
}

void read_file() {
	char buffer[256], *token;
	int found, index;
	FILE *fp = fopen("programming.txt", "r");
	while (fgets(buffer, 255, fp)) {
		token = strtok(buffer, DELEMETERS);
		while (token) {
			convert_lower(token);
			index = linear_search(token, &found);

			if (found) {
				// 단어가 이미 있다면 해당 단어의 카운트를 증가
				words[index].count++;
			}
			else {
				move_downward(index); // 단어를 한칸씩 뒤로 옮기고
				insert_data(index, token); // 단어를 해당 위치에 추가.
			}
			token = strtok(NULL, DELEMETERS);
		}
	}
	fclose(fp);
}

void move_downward(int index) {
	// 구현 미루기: index부터 그 이후의 단어들을 뒤로 한 칸씩 옮김
}

void insert_data(int index, const char *word) {
	// 구현 미루기: index에 해당하는 위치에 word 추가
}

void convert_lower(char *str) {
	while (*str) {
		*str = tolower(*str);
		str++;
	}
}

int linear_search(const char *key, int *found) {
	int n, compare;

	*found = 0; // 찾지 못했음으로 가정

	for (n = 0; n < nwords; n++) {
		compare = strcmp(key, words[n].str);
		if (compare <= 0) {
			*found = compare == 0; // compare가 0이면 찾음
			break;
		}
	}

	// 배열의 인덱스를 리턴
	return n;
}

void print_words() {
	// 구현을 미룸
}

void deallocate() {
	free(words);
}
