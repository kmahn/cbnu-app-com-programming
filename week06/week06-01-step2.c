/*
6주차 예제: 최대값 찾기
*/
#include <stdio.h>
#define SIZE 10

void print_array(int[]);
int find_max(int[]);

int main() {

	// 지역변수 선언 및 초기화
	int data[SIZE] = { 3, 2, 9, 7, 1, 4, 8, 0, 6, 5 };
	int maxindex;

	// 배열 출력
	print_array(data);

	// 배열 요소 중 최대값인 요소의 인덱스 구하기
	maxindex = find_max(data);

	// 출력
	printf("최대값: data[%d] = %d\n", maxindex, data[maxindex]);

	return 0;
}

void print_array(int array[]) {
	int n;
	printf("배열의 값\n");
	for (n = 0; n < SIZE; n++) {
		// 배열 원소출력
		printf("data[%d]=%d ", n, array[n]);

		// 5개마다 줄 바꿈
		if ((n + 1) % 5 == 0)
			printf("\n");
	}
}

int find_max(int array[]) {
	int n;
	int maxindex = 0; // 0번째 원소가 최대값이라 가정

	// 최대값이 있는 원소의 인덱스 구하기
	for (n = 1; n < SIZE; n++) {
		if (array[maxindex] < array[n])
			maxindex = n;
	}

	return maxindex;
}