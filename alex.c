#include <stdio.h>
#include <string.h>

#define MAX_LINE_LENGTH 1023

int isWhitespace(char c) {
    return c == ' ' || c == '\t' || c == '\v' || c == '\n' || c == '\r';
}

int isAlpha(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

int isNumber(char c) {
    return c >= '0' && c <= '9';
}

int main(int argc, char** argv) {
    char line[MAX_LINE_LENGTH + 1];
    int position;

    for (;;) {
        printf(">>> ");

        // Read line and exit on EOF or 'exit'
        if (fgets(line, MAX_LINE_LENGTH, stdin) == NULL) break;
        line[strcspn(line, "\n\r")] = '\0'; // Removes '\n' from string by finding the '\n' index and swaping for '\0'
        if(strcmp(line, "exit") == 0) break;

        position = 0;

        while(line[position] != '\0') {
            // Ignore whitespace
            while(isWhitespace(line[position])) position++;

            // Numbers
            if (isNumber(line[position])) {
                while(isNumber(line[position])) {
                    printf("%c", line[position]);
                    position++;
                }

            // Indentifiers
            } else if (isAlpha(line[position]) || line[position] == '_') {
                while(isAlpha(line[position]) || line[position] == '_' || isNumber(line[position])) {
                    printf("%c", line[position]);
                    position++;
                }

            // Default
            } else {
                printf("%c", line[position]);
                position++;
            }

            printf("\n");
        }
    }

    return 0;
}
