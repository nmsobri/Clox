#include <stdio.h>

#include "common.h"
#include "compiler.h"
#include "scanner.h"

void compile(const char* source) {
    initScanner(source);
    int line = -1;

    for (;;) {
        Token token = scanToken();

        if (token.line != line) {
            printf("Line: %-4d", token.line);
            printf("Token type: %d (%s)  Lexeme: '%.*s'\n", token.type, tokenTypeToString(token.type), token.length, token.start);
            line = token.line;
        } else {
            printf("%*.*c", 5, 1, '|');
            printf("%4c Token type: %d (%s)  Lexeme: '%.*s'\n", ' ', token.type, tokenTypeToString(token.type), token.length, token.start);
        }

        if (token.type == TOKEN_EOF) break;
    }
}