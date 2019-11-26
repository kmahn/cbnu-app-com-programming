#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct STUDENT_INFO SINFO;

void get_student_info();
void insert_node(const SINFO*);
void print_list();
void delete_list();

struct STUDENT_INFO {
	char id[16];
	char name[16];
	int score;
	SINFO *next;
};

SINFO *listhead = NULL;

int main() {
	get_student_info();
	print_list();
	return 0;
}

void get_student_info() {
	SINFO student;
	printf("학생 정보를 입력하세요.\n");
	printf("입력을 마치려면 학번에 -1을 넣으세요.\n\n");

	while (1) {
		printf("학번: ");
		scanf("%s", student.id);

		// 학번에 -1이 입력되면 입력 종료
		if (strcmp(student.id, "-1") == 0) break;

		printf("이름: ");
		scanf("%s", student.name);
		printf("성적: ");
		scanf("%d", &student.score);

		// 학생 정보를 정렬하여 저장
		insert_node(&student);

		printf("\n");
	}
}

void insert_node(const SINFO *student) {
	SINFO *temp = (SINFO *)malloc(sizeof(SINFO));
	strcpy(temp->id, student->id);
	strcpy(temp->name, student->name);
	temp->score = student->score;
	temp->next = listhead;
	listhead = temp;
}

void print_list() {
	SINFO *search;
	search = listhead; // 연결리스트의 처음부터 탐색 시작

	// 헤더 출력
	printf("\n%16s%16s%6s\n", "학번", "이름", "성적");
	printf("======================================\n");

	while (search) {
		printf("%16s", search->id);
		printf("%16s", search->name);
		printf("%6d\n", search->score);
		search = search->next; // 다음 노드로 이동
	}
}

void delete_list() {
	// 구현을 미룸
}