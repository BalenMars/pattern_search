#if 0
Author: Balen A.
Date: January 15th 2021
Comparing the style of two functions: strindex() and check_partten()
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check_partten(char source[], char pattern[]);
int strindex(char s[], char t[]);

int main(int argc, char **argv) {

	if (argc != 3) {
		fprintf(stderr, "This program requires a file and a pattern to search for.\n");
		fprintf(stderr, "Exiting ...\n");
		exit(EXIT_FAILURE);
	}
	else {
		printf("Pattern to search \"%s\" in file:\n", argv[2]);
		printf("File to search %s\n", argv[1]);
	}

	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	fp = fopen(argv[1], "r");
	if (fp == NULL)
		exit(EXIT_FAILURE);

	int number_of_pattern = 0;
	char *pattern = argv[2];
	int pattern_length = strlen(pattern);
	int check_partten_return;
	int number_of_lines = 0;

	while ((read = getline(&line, &len, fp)) != -1) {

		number_of_lines++;

		if (line[read-1] == '\n')
			line[read-1] = '\0';

		check_partten_return = 0;
		char *printf_format = "Found pattern \"%s\" at line %d with index %d\n";

		while (check_partten_return != -1) {
			check_partten_return = check_partten(line, pattern);
			if (check_partten_return != -1){
				number_of_pattern++;
				printf(printf_format, pattern, number_of_lines, check_partten_return);
			}
			line += (check_partten_return + pattern_length);
		}

		line = NULL;
	}

	printf("Number of pattern %s found: %d\n", pattern, number_of_pattern);

	fclose(fp);
	if (line)
		free(line);

	return EXIT_SUCCESS;
}

int check_partten(char source[], char pattern[]) {

	int first_pattern_char = pattern[0];
	int pattern_index = 0;
	int source_index = 0;

	for (source_index=0; source[source_index]!='\0'; ++source_index) {
		if (source[source_index] == first_pattern_char) {
			for (pattern_index=0;
				 pattern[pattern_index]!='\0'
			     && source[source_index + pattern_index] == pattern[pattern_index];
				 ++pattern_index);
		}
		if (pattern[pattern_index] == '\0')
			return source_index;
	}
	return -1;
}

/* Below function is directly copied from
 * The C Programming Language 2nd by Kernighan & Ritchie, which I think is bad programming style.
 * A better style is the function above it, which I wrote to demo my opinion.
*/

/* strindex: return index of t in s, -1 if none */
int strindex(char s[], char t[]) {
	int i, j, k;
	for (i = 0; s[i] != '\0'; i++) {
		for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++) ;
		if (k > 0 && t[k] == '\0') return i;
	}
	return -1;
}


