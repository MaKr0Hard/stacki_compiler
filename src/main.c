#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

char program_name[2048];

// For lexer
typedef enum {
    not_an_identifier, //We don't have cpp here, so he have to do with this, this could be done in something like inheritence
    LET,
    ARRAY,
    FN, //Just put this into prectice
    IF,


}identifier;

typedef struct {
    char* name;
    int type;
} Var;
Var* vars;

typedef enum {
    not_a_value_not_a_variable,

} values_variables;

typedef enum {
    not_an_operator,

} operators;

typedef enum {
    not_a_delimiter,

} delimiters;



char* convert_string_to_lower(char* string) {
    for (int i = 0; i < strlen(string); i++) {
        string[i] = tolower(string[i]);
    }
    return string;
}

//Useless now

void lexer(const char* input_file_name) {
    FILE *input_file = fopen(input_file_name, "r"); //TODO: check if file exists
    char line[4096];

    while (fgets(line, sizeof(line), input_file)) {
        char* token_1 = strtok(line, " ");
        if (token_1 == NULL) {
            break;
        } else { convert_string_to_lower(token_1); //Remove this if you want case sensitivity
            if (strcmp(token_1, "if") == 0) {

            } else if (strcmp(token_1, "print") == 0) {

            } else if (strcmp(token_1, "let") == 0) {
                //TODO: use variables array
            } else if (strcmp(token_1, "array") == 0) { //TODO: Make rules for that (identifier, keyword, etc.), basically lexer

            } else if (strcmp(token_1, "fn") == 0) {// Just for this time btw, id do not believe in postfix types

            } //TODO: When doing the lexer, every condition should be an identifier and if there is another condition inside, send the condtion as an array of tokens and do the same thing inside a function.

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
