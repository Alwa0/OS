#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <memory.h>
#include <zconf.h>

int main(){
    int myFile = open("ex1.txt", O_RDWR);
    if(myFile < 0){
        printf("open error\n");
    }
    struct stat myStat = {};
    if (fstat(myFile, &myStat)){
        printf("fstat error\n");
    }

    off_t size = myStat.st_size;
    char *map = mmap(NULL, size, PROT_READ|PROT_WRITE, MAP_SHARED, myFile, 0);
    if (map == MAP_FAILED){
        printf("mmap error\n");
    }
    char* text = "This is a nice day";
    ftruncate(myFile, strlen(text));
    memcpy(map, text, strlen(text));
    msync(map, strlen(text)+1, MS_SYNC);
    munmap(map, strlen(text)+1);
    close(myFile);
    return 0;
}
