#include <stdio.h>

int main() {
	// 지역 변수 초기화
	int score;
	char grade;

	printf("\n점수를 입력하세요 : ");
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
		printf("학접은 %c입니다.\n", grade);
	}
	else {
		printf("입력을 잘못하셨습니다.\n");
	}
}