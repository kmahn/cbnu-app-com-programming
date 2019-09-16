#include <stdio.h>

int main() {
	// 지역 변수 선언
	int number, n;

	printf("1000 이하의 완전수:\n");
	for (number = 1; number <= 1000; number++) {
		// 구현전 임시 출력
		printf("%d가 완전수인지 체크해봅시다.\n", number);
	}

	return 0;
}
