/**
4주차 예제 2번: 소수 판정 프로그램
- 반복문 개선 방법 2
*/
#include <stdio.h>
#include <math.h>

// 함수 원형 선언
int is_prime(int);

int main() {
	// 지역변수 선언
	int number;

	while (1) {
		printf("소수를 판정할 정수를 입력하세요(1 이하의 수이면 종료): ");
		scanf("%d", &number);
		if (number >= 2) {
			// 구현을 나중으로 미룸
			// printf("%d에 대한 소수를 판정합니다.\n", number);

			// 소수 판정하여 출력
			if (is_prime(number)) {
				printf("%d은(는) 소수입니다.\n\n", number);
			}
			else {
				printf("%d은(는) 소수가 아닙니다.\n\n", number);
			}
		}
		else {
			printf("%d에 대한 소수를 판정할 수 없습니다.\n", number);
			printf("프로그램을 종료합니다.\n");
			return 0;
		}
	}
}

int is_prime(int n) {
	// 지역변수 선언 및 초기화
	int divider = 2, to = (int)sqrt(n);
	int prime = 1;	// 소수라고 가정

	// 2 ~ n의 제곱근까지 반복을 하면서 나머지가 0인 것이 하나라도 있으면 소수가 아님
	while (divider < n) {
		if (n % divider == 0) {
			prime = 0; // 소수가 아님을 저장
			break;
		}
		divider++;
	}

	return prime; // 한번에 리턴
}