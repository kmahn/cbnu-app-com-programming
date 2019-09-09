#include <stdio.h>

void main()
{
	// 1. 지역 변수 선언
	float num1, num2, num3;
	float max, min;
	float difference;

	// 2. 안내문 출력 및 데이터 입력
	printf("세 개의 수를 입력하세요.\n\n");
	printf("첫 번째 수: ");
	scanf("%f", &num1);
	printf("두 번째 수: ");
	scanf("%f", &num2);
	printf("세 번째 수: ");
	scanf("%f", &num3);

	// 3. 임시 데이터로 처리
	max = 100.1;
	min = -20.4;

	difference = max - min;
	printf("\n가장 큰 수와 작은 수의 차이 = %f\n\n", difference);

	return 0;
}
