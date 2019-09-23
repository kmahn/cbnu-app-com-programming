#include <stdio.h>

int main() {
	// 지역변수 선언
	int number;

	while (1) {
		printf("소수를 판정할 정수를 입력하세요(1 이하의 수이면 종료): ");
		scanf("%d", &number);
		if (number >= 2) {
			// 구현을 나중으로 미룸
			printf("%d에 대한 소수를 판정합니다.\n", number);
		}
		else {
			printf("%d에 대한 소수를 판정할 수 없습니다.\n", number);
			printf("프로그램을 종료합니다.\n");
			return 0;
		}
	}
}
