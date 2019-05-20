#include <fcntl.h>
#include <sys/types.h>
#include <err.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    printf("Value of the given parameter is: %d\n", atoi(argv[1]));
    printf("The size of int is: %d bytes\n", sizeof(int));
    printf("The size of uint16_t is %d bytes\n", sizeof(u_int16_t));

    int fd16, fd32;
    if( (fd16 = open("16bits.bin", O_WRONLY | O_CREAT | O_TRUNC, 755)) == -1)
        errx(1, "Couldn't open file");
    if( (fd32 = open("32bits.bin", O_WRONLY | O_CREAT | O_TRUNC, 755)) == -1){
        close(fd16);
        errx(1, "Couldn't open file");
    }

    for(int i=1; i<=atoi(argv[1]); i++){
        u_int16_t number = (u_int16_t)i;
        
        if(sizeof(u_int16_t) != write(fd16, &number, sizeof(u_int16_t))
            || sizeof(int) != write(fd32, &i, sizeof(int)) ){
            close(fd16);
            close(fd32);
            errx(2, "Error while writing");
        }
    }

    close(fd16);
    close(fd32);

    exit(0);
}
