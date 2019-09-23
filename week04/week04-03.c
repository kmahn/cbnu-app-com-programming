/**
4주차 예제 3번: 에라토스테네스의 체
- eratos() 함수 및 print_primes 구현
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// 함수 원현 선언
void eratos(char[], int);
void print_primes(char*, int);

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
			// printf("%d 개의 배열을 할당하였습니다.\n", number + 1);

			// 에라토스테네스의 체를 구하고
			eratos(arr, number);
			// 소수를 출력
			print_primes(arr, number);

			// 메모리를 다 사용했으면 해제해 줌
			free(arr);
		}
	}

	return 0;
}

void eratos(char arr[], int number) {
	// 지역 변수 선언
	int n, m, to, last, index;

	to = (int)sqrt(number); // 마지막 나눌 값
	for (n = 2; n <= to; n++) {
		// 이미 소수가 아닌 경우 수행할 필요 없음
		if (arr[n] != 0) continue;

		last = number / n;
		for (m = 2; m <= last; m++) {
			index = n * m;
			arr[index] = 1; // 소수가 아님을 표시
		}
	}
}

void print_primes(char *arr, int number) {
	// 지역 변수 선언
	int n, count = 0;

	printf("%d의 소수:\n", number);
	for (n = 2; n <= number; n++) {
		// 해당 인덱스가 소수이면 소수 출력
		if (arr[n] == 0) {
			printf("%9d", n); // 숫자를 9칸에 맞춰 출력
			count++;
			if (count % 8 == 0) printf("\n"); // 한 줄에 8개씩 출력
		}
	}
	printf("\n");
}