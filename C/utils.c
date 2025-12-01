#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "utils.h"

void strToLower(char *s) {
    for (; *s; ++s) *s = (char)tolower((unsigned char)*s);
}

void trimString(char *str) {
    char *start = str;
    while (*start && isspace((unsigned char)*start));
    if (start != str) {
        memmove(str, start, strlen(start) + 1);
    }

    size_t len = strlen(str);
    while (len > 0 && isspace((unsigned char)str[len - 1])) {
        str[--len] = '\0';
    }
}

void flushInputBuffer(const char *buffer) {
    if (strchr(buffer, '\n') == NULL) {
        int leftoverC;
        while ((leftoverC = getchar()) != '\n' && leftoverC != EOF);
    }
}