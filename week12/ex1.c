#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *f = fopen("/dev/random", "r");
    char *file = (char *) malloc(sizeof(char));
    fgets(file, 20, f);
    puts(file);
    return 0;
}
