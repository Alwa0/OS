#include "stdio.h"
#include "limits.h"
#include "float.h"

int main(void){
	int a = INT_MAX;
	float b = FLT_MAX;
	double c = DBL_MAX;
	printf("Integer size = %lu bytes\n", sizeof(a));
	printf("Maximum value for integer = %d \n", a);    
    printf("Float size = %lu bytes\n", sizeof(b));
    printf("Maximum value for float = %f \n", b);
    printf("Double size = %lu bytes\n", sizeof(c));	
	printf("Maximum value for double = %f ", c);
	return 0;
}