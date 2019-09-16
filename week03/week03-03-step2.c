#include <stdio.h>

// 완전수 판별함수 원형 선언
int is_perfect_number(int);

int main() {
	// 지역 변수 선언
	int number, n;

	printf("1000 이하의 완전수:\n");
	for (number = 1; number <= 1000; number++) {
		// 구현전 임시 출력
		// printf("%d가 완전수인지 체크해봅시다.\n", number);
		if (is_perfect_number(number)) {
			printf(" %d \n", number);
		}
	}

	return 0;
}


// 완전수 판별 함수 정의
int is_perfect_number(int number) {
	// 완전수를 구하기 위한 인덱스 i, 약수의 합을 구하기 위한 sum 변수 선언(초기화는 0)
	int i, sum = 0;

	for (i = 1; i < number; i++) {
		// i가 number의 약수라면 누적 합을 구함
		if (number % i == 0) sum += i;
	}

	// 누적 합이 같으면 참을 아니면 거짓을 리턴
	if (sum == number) return 1;
	else return 0;

	// 위 if-else 구문은 아래와 같이 간단하게 표현 가능
	// return sum == number;
}