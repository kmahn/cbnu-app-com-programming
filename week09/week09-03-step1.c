#include <stdio.h>

// ���Ͽ� ��� �ִ� �ܾ��� �ִ� ��
#define MAXWORD 1000

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
	// ������ �̷�
}

void read_file() {
	// ������ �̷�
}

void print_words() {
	// ������ �̷�
}

void deallocate() {
	// ������ �̷�
}