#include <stdio.h>

int main() {
	char x[] = "Hello world! I am learning C programming language.";
	
	int i, j;

	for (j = 0; x[j]; j++);

	printf("%s\t", x);
	for (i = j-1; x[i]; i--) {
		printf("%c", x[i]);
	}
	printf("\n");
	
	return 0;

}
