#include <stdio.h>

int main() {
	// 지역 변수 선언
	int number;

	while (1) {

		// 데이터 입력부
		printf("약수를 구할 정수를 입력하세요(1 이하의 수면 종료): ");
		scanf("%d", &number);

		// 약수를 구할 수 있는 숫자 입력
		if (number >= 2) {
			// 임시로 메시지 출력
			printf("%d에 대한 약수를 구합니다.\n", number);
		}
		else {
			printf("%d에 대한 약수를 구할 수 없습니다.\n", number);
			break;
		}
		printf("\n");
	}

	return 0;
}