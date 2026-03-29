#ifndef CFLOW_LEXER_H
#define CFLOW_LEXER_H

#include <ctype.h>

void generate_function_signature(FILE *file, char *buffer, int current) {
    int index = 0;
    while (current != EOF && isalnum(current)) {
        buffer[index] = (char)current;
        current = fgetc(file);
        index++;
    }
    buffer[index] = "\0";
}

void lexer(FILE *file) {
    int current = getc(file);
    while (current != EOF) {
        if (isspace(current)) {
            continue;
        } else if (isalpha(current)) {
            char buffer[84];
            generate_function_signature(file, buffer, current);
            printf("%s\n", buffer);
        }

        current = getc(file);
    }
}


#endif //CFLOW_LEXER_H
