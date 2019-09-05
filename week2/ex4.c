#include "stdio.h"

#define STR_SIZE 300

void swap_numbers(int* a, int* b){
	int t = *a;
	*a = *b;
	*b = t;
}

int main(void){
	char s[STR_SIZE];
	int a, b;
	printf("Input 2 numbers to swap: ");
	fgets(s, STR_SIZE, stdin);
	sscanf(s, "%d%d", &a, &b);
	swap_numbers(&a, &b);
	printf("Swapped numbers: %d %d", a, b);
	return 0;
}