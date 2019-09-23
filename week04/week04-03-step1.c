/**
4주차 예제 3번: 에라토스테네스의 체
- main 함수 구현
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
	// 지역 변수 선언
	int number;
	char *arr;

	// 입력
	printf("정수를 입력하시오: ");
	scanf("%d", &number);

	if (number > 2) {
		arr = (char *)calloc(number + 1, sizeof(char));
		if (arr) {
			// 에라토스테네스의 체에 대한 구현을 미룸
			printf("%d 개의 배열을 할당하였습니다.\n", number + 1);

			// 메모리를 다 사용했으면 해제해 줌
			free(arr);
		}
	}

	return 0;
}