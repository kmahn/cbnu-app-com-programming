#include <stdio.h>
#include <stdlib.h>
#include "studentmgnt.h"

SINFO *listhead = NULL;

static void flush();
static void insert_node(SINFO *new_node, SINFO *prev_node, SINFO *pos);

char print_menu() {
	char menu;
	printf(
		"ó���� ����� ��ȣ�� �����ϼ���.\n\n"

		"1. �ڷ��߰�\n"
		"2. ��ϰ˻�\n"
		"3. ��ϻ���\n"
		"4. �������\n"
		"5. ��Ϻ���\n"
		"6. �޴�����\n"
		"7. ����\n\n"

		"���� > "
	);

	menu = getchar();
	flush();
	return menu;
}


void add_student() {
	SINFO *new_node = (SINFO *)malloc(sizeof(SINFO));
	printf("�����͸� �Է��ϼ���.\n");
	printf("�а�: "); scanf("%s", new_node->major);
	printf("�й�: "); scanf("%s", new_node->id);
	printf("�̸�: "); scanf("%s", new_node->name);
	printf("����: "); scanf("%d", &new_node->score);

	insert_node(new_node, NULL, listhead);
	printf("%s�� �����͸� �����Ͽ����ϴ�.\n\n", new_node->name);
	flush();
}

void print_list() {
	SINFO *search = listhead;

	printf("\n%-16s%-16s%-16s%-6s\n", "�а�", "�й�", "�̸�", "����");
	printf("======================================================\n");
	while (search) {
		printf("%-16s", search->major);
		printf("%-16s", search->id);
		printf("%-16s", search->name);
		printf("%6d\n", search->score);
		search = search->next;
	}
	printf("\n");
}

void delete_list() {
	SINFO *temp = listhead;
	while (listhead) {
		listhead = listhead->next;
		free(temp);
		temp = listhead;
	}
}

void write_list() {
	SINFO *temp;
	FILE *fp;

	if (fp = fopen("student.dat", "wb")) {
		temp = listhead;
		while (temp) {
			fwrite(temp, sizeof(SINFO), 1, fp);
			temp = temp->next;
		}
		fclose(fp);
	}
}


void read_list() {
	SINFO *temp;
	FILE *fp;
	int count;
	if (fp = fopen("student.dat", "rb")) {
		do {
			temp = (SINFO *)malloc(sizeof(SINFO));
			count = fread(temp, sizeof(SINFO), 1, fp);
			if (count) {
				insert_node(temp, NULL, listhead);
			}
		} while (count);
		fclose(fp);
	}
}

void search_menu() {
	char key[32], cond;
	printf(
		"\n�������� �˻��Ͻðڽ��ϱ�?\n"
		"1. �й�\n"
		"2. �̸�\n\n"
		"�˻����� > "
	);
	cond = getchar();
	if (cond != '1' && cond != '2') {
		printf("\n�˻� ������ Ʋ���ϴ�.\n\n");
	}
	else {
		printf("\n%s��? ", cond == '1' ? "�й�" : "�̸�");
		scanf("%s", key);
		print_node(key, cond);
	}
	flush();
}

void print_node(const char *key, char cond) {
	SINFO *search = listhead;
	int result;

	while (search) {
		result = cond == '1' ? strcmp(search->id, key) : strcmp(search->name, key);

		if (result == 0) break;
		search = search->next;
	}

	if (search) {
		printf("\n�˻� ���: ");
		printf("%s ", search->major);
		printf("%s ", search->id);
		printf("%s ", search->name);
		printf("%3d\n\n", search->score);
	}
	else
		printf("\n\n�˻� ���ǿ� �ش��ϴ� �л��� �����ϴ�.\n\n");
}

void sort_menu() {
	char cond;
	printf(
		"\n�������� �����Ͻðڽ��ϱ�?\n"
		"1. �а�\n"
		"2. �й�\n\n"
		"���� ���� > "
	);
	cond = getchar();
	if (cond == '1' || cond == '2')
		sort_list(cond);
	else
		printf("\n�˻� ������ Ʋ���ϴ�.\n\n");
	flush();
}

void sort_list(char cond) {
	SINFO *oldlist, *temp;
	oldlist = listhead;
	listhead = NULL;

	while (oldlist != NULL) {
		temp = oldlist;
		oldlist = oldlist->next;
		sort_add(temp, cond);
	}
	if (cond == '1')
		printf("\n�а������� �����Ͽ����ϴ�.\n\n");
	else
		printf("\n�й������� �����Ͽ����ϴ�.\n\n");
}

void sort_add(SINFO *node, char cond) {
	int result;
	SINFO *search, *prev;
	search = listhead;
	prev = NULL;

	while (search) {
		result = cond == '1' ? strcmp(node->major, search->major) : strcmp(node->id, search->id);

		if (result > 0) {
			prev = search;
			search = search->next;
		}
		else
			break;
	}
	insert_node(node, prev, search);
}

void delete_node() {
	char name[16];
	SINFO *search, *prev;

	printf(
		"\n������ �л��� �̸��� �Է��ϼ���: \n"
		"�̸�: "
	);
	scanf("%s", name);
	flush();

	search = listhead;
	prev = NULL;
	while (search) {
		if (strcmp(name, search->name) == 0)
			break;
		prev = search;
		search = search->next;
	}

	if (search) {
		if (prev) {
			prev->next = search->next;
		}
		else {
			listhead = search->next;
		}
		free(search);
		printf("%s �л��� �����͸� �����Ͽ����ϴ�.\n\n", name);
	}
	else {
		printf("�л� �����Ͱ� �������� �ʽ��ϴ�.\n");
	}
}

// ���� �Լ�
void flush() {
	while (getchar() != '\n');
}

void insert_node(SINFO *new_node, SINFO *prev_node, SINFO *pos) {
	if (prev_node) {
		new_node->next = pos;
		prev_node->next = new_node;
	}
	else {
		new_node->next = pos;
		listhead = new_node;
	}
}

