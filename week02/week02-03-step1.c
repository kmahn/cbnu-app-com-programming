#include <stdio.h>
#define NUMMAX 10	// 데이터의 최대 수를 정의

// 함수 선언부
void get_data();
float calc_average();
float calc_stdev(float mean);

// 전역 변수 선언
float num[NUMMAX];
int n;

int main()
{
	// 지역 변수 선언
	float avg, stdev;
	
	// 데이터 입력
	get_data();

	// 평균 구하기
	avg = calc_average();

	// 표준편차 구하기
	stdev = calc_stdev(avg);

	printf("\n평균 = %6.2f\n", avg);
	printf("표준편차 = %6.2f\n\n", stdev);

	return 0;
}

// 비어 있는 함수 구현
void get_data() {}

// 리턴값이 있는 함수는 임시값 리턴
float calc_average() {
	return 1.0;
}

float calc_stdev(float mean)
{
	return 1.0;
}