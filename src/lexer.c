#include "lexer.h"



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
