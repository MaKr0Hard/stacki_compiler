#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

char program_name[2048];

char** vars = NULL;

char* convert_string_to_lower(char* string) {
    for (int i = 0; i < strlen(string); i++) {
        string[i] = tolower(string[i]);
    }
    return string;
}

void open_input(const char* input_file_name) {
    FILE *input_file = fopen(input_file_name, "r");
    char line[4096];

    while (fgets(line, sizeof(line), input_file)) {
        //TODO: use strtok() to parse the code and stop at semicolons
        char* token_1 = strtok(line, " ");
        if (token_1 == NULL) {
            break;
        } else { convert_string_to_lower(token_1); //Remove this if you want case sensitivity
            if (strcmp(token_1, "if") == 0) {

            } else if (strcmp(token_1, "print") == 0) {

            } else if (strcmp(token_1, "var") == 0) {
                //TODO: use variables array
            }

        }

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
