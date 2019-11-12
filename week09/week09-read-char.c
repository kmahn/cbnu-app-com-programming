#include <stdio.h>

int main() {
	char ch;
	FILE *fp = fopen("malloc.txt", "r");
	while (!feof(fp)) {
		ch = fgetc(fp);
		putchar(ch);
	}
	fclose(ch);
	return 0;
}