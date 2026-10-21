#ifndef LEXER_H
#define LEXER_H
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

enum TokenType { //Wait, just put some of OUR code
    ANYTOK, /*any token, by default when any token is expected */
    LPARENTHESE,
    RPARENTHESE,
    NUMBER,
    STRING,
    IDENTIFIER,
    PRINT, /* requires a string*/
    SEMIC, /* semicolon*/
    EOF_TOKEN
};

typedef struct {
    char* string;
    int length;
} StringSlice;

struct Token {
    enum TokenType type;
    union {// Either a number or an identifier
        int number;
        StringSlice string;
        char identifier[64];
    };
};


typedef struct Token token_t;
typedef struct  {
token_t token_array[4096][240];
int line_nbr;
} Token_array_w_line_nbr;

typedef enum TokenType tokentype_t;



void lexer(const char* input_file_name);
#endif
