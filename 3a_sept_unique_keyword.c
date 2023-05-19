#include<stdio.h>
#include<string.h>
#include<stdlib.h>

const char keywords[][10] = {"int", "float", "double", "char", "for", "while", "if", "else", "return", "include"};
const char operators[] = {'+', '-', '*', '/', '=', '<', '>', '!', '&', '|', '^', '~', '%', ':', '"' , '#'};
const char delimiters[] = {';', ',', '(', ')', '{', '}'};

int is_keyword(char *str) {
    int i;
    for (i = 0; i < sizeof(keywords) / sizeof(keywords[0]); i++) {
        if (strcmp(keywords[i], str) == 0) {
            return 1;
        }
    }
    return 0;
}

int is_operator(char ch) {
    int i;
    for (i = 0; i < sizeof(operators) / sizeof(operators[0]); i++) {
        if (operators[i] == ch) {
            return 1;
        }
    }
    return 0;
}

int is_delimiter(char ch) {
    int i;
    for (i = 0; i < sizeof(delimiters) / sizeof(delimiters[0]); i++) {
        if (delimiters[i] == ch) {
            return 1;
        }
    }
    return 0;
}

int is_identifier(char *str) {
    if (is_keyword(str)) {
        return 0;
    }
    if (!isalpha(str[0]) && str[0] != '_') {
        return 0;
    }
    int i;
    for (i = 1; i < strlen(str); i++) {
        if (!isalnum(str[i]) && (str[i]) != '_'&& str[i]!='.') {
            return 0;
        }
    }
    return 1;
}

int main() {
    char str[100];
    int i, j = 0, k;

        FILE *f;
        f=fopen("identify.c", "r");

    while (fscanf(f,"%s", str) != EOF)
     {
        if (is_keyword(str)) {
            printf("\n keyword :- %s", str);
        } else if (is_identifier(str)) {
            printf("\n identifier :- %s", str);
        } else if (is_operator(str[0])) {
            printf("\n operator :- %c", str[0]);
        } else if (is_delimiter(str[0])) {
            printf("\n delimiter :- %c", str[0]);
        } else {
            printf("\n number :- %s ", str);
        }
    }
    return 0;
}
