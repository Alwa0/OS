#include "stdio.h"
#include "string.h"

#define STR_SIZE 300

int main(void){
	char s[STR_SIZE];
	int i;
	printf("Input a string: ");
	fgets(s, STR_SIZE, stdin);
	for(i = 0; i < strlen(s)/2; i++){
		char t = s[i];
		s[i] = s[strlen(s)-i-1];
		s[strlen(s)-i-1] = t;
	}
	printf("\n");
	printf("Reversed string: %s", s);
	return 0;
}