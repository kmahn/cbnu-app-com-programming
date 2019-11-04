#include <stdio.h>

int main() {
	// 파일 포인터 선언
	FILE *fp;
	
	// 파일 열기
	fp = fopen("myfile.txt", "w");

	if (fp) {
		// 파일쓰고 닫기
		fprintf(fp, "My first file\n");
		fclose(fp);
	}

	return 0;
}