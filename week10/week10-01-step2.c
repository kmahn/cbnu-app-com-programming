#include <stdio.h>
typedef struct STUDENT_INFO SINFO;

void get_student_info();
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
		printf("\n");
	}
}

void print_list() {
	// 구현을 미룸
}

void delete_list() {
	// 구현을 미룸
}