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
	return 0;
}

void get_student_info() {
	SINFO student;
	printf("�л� ������ �Է��ϼ���.\n");
	printf("�Է��� ��ġ���� �й��� -1�� ��������.\n\n");

	while (1) {
		printf("�й�: ");
		scanf("%s", student.id);

		// �й��� -1�� �ԷµǸ� �Է� ����
		if (strcmp(student.id, "-1") == 0) break;

		printf("�̸�: ");
		scanf("%s", student.name);
		printf("����: ");
		scanf("%d", &student.score);
		
		// �л� ������ �����Ͽ� ����
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
	// ������ �̷�
}

void delete_list() {
	// ������ �̷�
}