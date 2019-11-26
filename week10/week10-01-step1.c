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
	// 구현을 미룸
}

void print_list() {
	// 구현을 미룸
}

void delete_list() {
	// 구현을 미룸
}