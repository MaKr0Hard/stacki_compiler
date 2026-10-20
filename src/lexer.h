#ifndef LEXER_H
#define LEXER_H
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

enum TokenType { //Wait, just put some of OUR code
    LPARENTHESE,
    RPARENTHESE,
    NUMBER,
    //STRING,
    IDENTIFIER,

    EOF_TOKEN
};

struct Token {
    enum TokenType type;
    union {
        int number;
        //struct StringSlice string;
        char identifier[64];
    };
};


typedef struct Token token_t;

void lexer(const char* input_file_name);
#endif
