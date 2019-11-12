#include <stdio.h>
#include <ctype.h>

// �����ڴ� 26�ڷ� ����, �� ���ĺ��� ���� Ƚ���� ī�����ϱ� ���� ����
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

	printf("������ ������ ��\n\n");

	for (n = 0; n < 26; n++) {
		printf("%c: %2d", n + 'A', alphabet[n]);
		if ((n + 1) % 5 == 0) printf("\n");
		else printf(", ");
	}

	return 0;
}

