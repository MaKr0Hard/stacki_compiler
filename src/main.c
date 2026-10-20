#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include "lexer.h"

char program_name[2048];



int main(int argc, char** argv) { //TODO : Add multi-file support
    int opt;
    char* input = NULL;
    char* output = NULL;
    while ((opt = getopt(argc, argv, "s:o:")) != -1) { //-s : source
                                                     //-o : output
        switch (opt) {
            case 's':
                input = (char *)malloc(strlen(optarg));
                strcpy(input, optarg);
                puts(input);
                break;
            case 'o':
                output = (char*)malloc(strlen(optarg));
                strcpy(output, optarg);
                puts(output);
                break;
            default:
                putchar('\n');
                //printf("Unknown argmment : -%c", optarg);
                exit(EXIT_FAILURE);
                break;
        }
    }

    if ((input != NULL) && (output != NULL)) {
        lexer(input);
    }
    free(input);
    free(output);
}
