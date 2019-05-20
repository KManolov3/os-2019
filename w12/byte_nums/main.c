#include <fcntl.h>
#include <sys/types.h>
#include <err.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
    /* TODO: Check whether program was called correctly */  

    char* mode = argv[1];
    int fd;

    /* TODO: Open file and add error handling */

    u_int16_t number;
    int min=65000, max=0;
    while(read(fd, &number, sizeof(u_int16_t)) > 0){
	/* TODO: Handle the 3 possible cases: whether the first argument of the program is --print, --min or --max */
    }

    /* TODO: Handle the 3 possible cases: whether the first argument of the program is --print, --min or --max */

// How will the individual bytes look as chars?
    
    lseek(fd, 0, SEEK_SET);
    char c;
    while(read(fd, &c, sizeof(char) ) > 0) //sizeof(char) == 1
        printf("%d\n", c);

// How will those 16bit numbers look as ints?

    lseek(fd, 0, SEEK_SET);
    int i;
    while(read(fd, &i, sizeof(int) ) > 0) //sizeof(int) == 4
        printf("%d\n", i);

// Unset the residue bit
     
    i = i & ~(1 << 18);
    printf("%d\n", i);

    close(fd);
    exit(0);
}
