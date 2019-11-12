#include <stdio.h>

int main() {
	char buffer[256];
	FILE *fp = fopen("malloc.txt", "r");
	
	while (fgets(buffer, 255, fp) != NULL) 
		puts(buffer);

	fclose(fp);
	return 0;
}