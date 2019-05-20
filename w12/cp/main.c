#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <err.h>
#include <stdbool.h>
#include <string.h>

bool checkIsDir(const char* filePath){
    struct stat fileStat;
    stat(filePath, &fileStat);
    return S_ISDIR(fileStat.st_mode);
}

int findNamePosition(const char* filePath){
    int lastSlashPos = 0;
    for(int i=0; i<strlen(filePath); i++){
        if(filePath[i] == '/')
            lastSlashPos = i;
    }

    return lastSlashPos;
}

char* concat(const char* str1, const char* str2){
    char* concatenated = malloc(strlen(str1) + strlen(str2) + 1);
    strcpy(concatenated, str1);
    strcat(concatenated, str2);

    return concatenated;
}

int main(int argc, char* argv[])
{
    /* TODO: Add error handling for correct usage */
    int fdFrom, fdTo;

    /* TODO: Open file to be copied and add error handling */

    bool isDir = checkIsDir(argv[2]); // Check if the destination parameter is a directory or a file path
    
    char* destinationPath;
    if(!isDir){
        /* TODO: Open destination file path */
    } else {
        /* TODO: Find where the file name starts */
        /* TODO: Construct name of destination file */
	/* TODO: Open destination file path */
    }
    if(fdTo == -1){
        /* TODO: Free used up resources */
	/* TODO: Add error handling */
    }
    free(destinationPath); //Free the allocated memory in the pointer returned from concat

    char buffer[4096];
    int readSize;
  
    /* TODO: Copy contents of source file in destination file */

    close(fdFrom);
    close(fdTo);
    exit(0);
}
