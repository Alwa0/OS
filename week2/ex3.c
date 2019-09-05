#include "stdio.h"

#define STR_SIZE 300

void triangle(int n){
	int i, j;
	for(i = 1; i <= n; i++){
		for(j = 0; j < (2*n-2*i+1)/2; j++){
			printf(" ");
		}
		for(j = 0; j < 2*i-1; j++){
			printf("*");
		}
		printf("\n");
	}
}

int main(void){
	char s[STR_SIZE];
	int n;
	printf("Input a number: ");
	fgets(s, STR_SIZE, stdin);
	sscanf(s, "%d", &n);
	triangle(n);
	return 0;
}