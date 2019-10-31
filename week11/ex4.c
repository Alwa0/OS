
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(){
	int fd1 = open("ex1.txt", O_RDWR);
	int fd2 = open("ex1.memcpy.txt", O_RDWR);
	
	struct stat stat1;
	struct stat stat2;

	stat("ex1.txt", &stat1);
	stat("ex1.memcpy.txt", &stat2);

	int size = stat1.st_size;
	ftruncate(fd2, size);
	char *map1 = mmap(NULL, size, PROT_READ, MAP_SHARED, fd1, 0);
	char *map2 = mmap(NULL, size, PROT_WRITE, MAP_SHARED, fd2, 0);

	memcpy(map2, map1, size);

	close(fd1);
	close(fd2);
	
	return 0;
}