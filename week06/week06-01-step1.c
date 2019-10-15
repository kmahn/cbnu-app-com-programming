/*
6주차 예제: 최대값 찾기 - 프로그램 구조
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
	// 배열 출력
}

int find_max(int array[]) {
	// 배열(array)에서 최대값이 있는 곳의 인덱스를 찾아 리턴
	return 1;
}