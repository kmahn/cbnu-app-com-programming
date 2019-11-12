#include <stdio.h>
#include <ctype.h>

// 영문자는 26자로 구성, 각 알파벳이 나온 횟수를 카운팅하기 위한 변수
int alphabet[26] = {0};

int main() {
	char ch;
	int n;
	FILE *fp = fopen("malloc.txt", "r");
	while (!feof(fp)) {
		ch = fgetc(fp);
		if (isupper(ch)) alphabet[ch - 'A']++;
		else if (islower(ch)) alphabet[ch - 'a']++;
	}
	fclose(fp);

	printf("파일의 영문자 수\n\n");

	for (n = 0; n < 26; n++) {
		printf("%c: %2d", n + 'A', alphabet[n]);
		if ((n + 1) % 5 == 0) printf("\n");
		else printf(", ");
	}

	return 0;
}

