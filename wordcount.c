/*
this program replicates the funcionality of the wc command
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int wcount = 0;
size_t ret;
char buffer[1024];
int flag = 0;

int main(int argc, char **argv) {

    FILE *fptr = fopen(argv[1], "r");
    if (!fptr) {
        perror("Could not open file");
        return 1;
    }

    while (ret = fread(&buffer, sizeof(char), 1024, fptr)) {
        for (int i = 0; i < ret; i++) {
            if (isspace(buffer[i])) {
                if (flag == 1) {
                    wcount++;
                    flag = 0;
                }
            } else {
                flag = 1;
            }
        }
    }

    if (flag == 1){ 
        wcount++;
    }
    // for (char c = getc(fptr); c != EOF; c = getc(fptr)) {
    //     if (c == ' ' || c == '\n') {
    //         wcount++;
    //     }
    // }

    fclose(fptr);
    printf("word count for this file: %d\n", wcount);

    return 0;
}