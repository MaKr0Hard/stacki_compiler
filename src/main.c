#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void open_input(char* input_file_name) {
    FILE *input_file = fopen(input_file_name, "r");
    char[4096] line;

    while (fgets(line, sizeof(line), input_file)) {

    }
}

int main(int argc, char** argv) { //TODO : Add multi-file support
    int opt;
    char* input = NULL;
    char* output = NULL;
    while ((opt = getopt(argc, argv, "s:o:")) != -1) { //-s : source
                                                     //-o : output
        switch (opt) {
            case 's':
                input = (char *)malloc(strlen(optarg)); //TODO: free me
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
        open_input(input);
    }
    free(input);
    free(output);
}
