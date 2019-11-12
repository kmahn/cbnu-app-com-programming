#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ���Ͽ� ��� �ִ� �ܾ��� �ִ� ��
#define MAXWORD 1000
#define DELEMETERS " ,.!?\t\n"

// �Լ� ���� ����
void initialize();
void read_file();
void print_words();
void deallocate();

// �ܾ ������ ����ü ����
struct word_count {
	char *str; // �ܾ ������ ������ ������
	int count; // �ܾ ��Ÿ�� Ƚ��
};

// �ܾ ������ �迭(�����ͷ� ����)
struct word_count *words;

// �迭�� ����Ǿ� �ִ� �ܾ� ��
int nwords;

int main() {
	initialize();  // ����ü �迭�� �Ҵ��ϰ� �ʱ�ȭ
	read_file();   // ���Ͽ��� �ܾ �����Ͽ� words[]�� ����
	print_words(); // words[]�� ����Ǿ� �ִ� �ܾ�� Ƚ���� ���
	deallocate();  // �������� �Ҵ� ���� �����Ҹ� ����
	return 0;
}

void initialize() {
	// ����ü �迭�� �������� �Ҵ��ϰ� ���� ���� �ʱ�ȭ
	words = (struct word_count *) malloc(sizeof(struct word_count) * MAXWORD);
	memset(words, 0, sizeof(struct word_count) * MAXWORD);
	nwords = 0;
}

void read_file() {
	char buffer[256], *token;
	FILE *fp = fopen("programming.txt", "r");
	while (fgets(buffer, 255, fp)) {
		// printf("%s", buffer);
		token = strtok(buffer, DELEMETERS);
		while (token) {
			printf("%s\n", token);
			token = strtok(NULL, DELEMETERS);
		}
	}
	fclose(fp);
}

void print_words() {
	// ������ �̷�
}

void deallocate() {
	free(words);
}