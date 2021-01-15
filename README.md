# pattern_search
Comparing two styles of programming 

[![Build Status](https://travis-ci.com/BalenMars/pattern_search.svg?branch=main)](https://travis-ci.com/BalenMars/pattern_search)

In this C programme example, I try to show the difference between two programming style through two functions:
###### check_partten(), which I wrote:
```
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
```
&nbsp;

###### strindex(), which is copied from the The C Programming Language 2nd by Kernighan & Ritchie:
```
int strindex(char s[], char t[]) {
	int i, j, k;
	for (i = 0; s[i] != '\0'; i++) {
		for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++) ;
		if (k > 0 && t[k] == '\0') return i;
	}
	return -1;
}
```
&nbsp;

I argue that the former is much cleaner and more readable than the later, which I think is a bad style and should be avoided.

&nbsp;
