#include <stdio.h>

int main() {
	// ���� ���� �ʱ�ȭ
	int score;
	char grade;

	printf("\n������ �Է��ϼ��� : ");
	scanf("%d", &score);

	if (score >=0 && score <= 100) {
		switch (score / 10) {
		case 10: case 9:
			grade = 'A';
			break;
		case 8:
			grade = 'B';
			break;
		case 7:
			grade = 'C';
			break;
		case 6:
			grade = 'D';
			break;
		default:
			grade = 'F';
		}
		printf("������ %c�Դϴ�.\n", grade);
	}
	else {
		printf("�Է��� �߸��ϼ̽��ϴ�.\n");
	}
}