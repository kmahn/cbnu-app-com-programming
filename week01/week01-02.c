/**
 1주차 실습 예제 2
 - 다음 코으듸 잘못된 부분을 찾아보자.
*/

#include <stdio.h>

int main() {
	int x, y;

	printf("Input a number >>> ");
	scanf("%d", &x);

	if (x > 0) {
		printf("%d\n", x);
	}
	else {
		printf("%d\n", y * y);
	}

	return 0;
}

