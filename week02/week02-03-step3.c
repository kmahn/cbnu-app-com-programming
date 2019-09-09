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
void get_data() {
	// 안내문 출력
	printf("최대 10개의 실수를 입력하세요\n");
	printf("입력을 종료하려면, 0 이하의 수를 입력하세요.\n\n");

	// 지금까지 입력된 데이터의 수를 0으로 초기화
	n = 0;

	// 음수가 입력되지 않거나 데이터가 10개 이하가 입력된 동안
	// 사용자로부터 데이터를 입력받음
	while (n < 10) {
		printf("숫자 %d: ", n + 1);
		scanf("%f", &num[n]);
		if (num[n] > 0.0) n += 1;
		else break;
	}
}

// 리턴값이 있는 함수는 임시값 리턴
float calc_average() {
	// 필요한 지역 변수 선언
	float sum, avg;
	int k;

	// sum을 덧셈의 항등원으로 초기화
	sum = 0.0;

	// k = 0 ~ n 까지 num[k]까지의 합 구하기
	for (k = 0; k < n; k++)
		sum += num[k];

	// 평균 구하기
	avg = sum / n;

	return avg;
}

float calc_stdev(float mean)
{
	return 1.0;
}