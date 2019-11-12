#include <stdio.h>
#include <string.h>

int main() {
	char str[] = "- This, a sample string.";
	char *token;

	token = strtok(str, " ,.-");
	while (token) {
		printf("%s\n", token);
		token = strtok(NULL, " ,.-");
	}
	return 0;
}