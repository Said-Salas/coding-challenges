#include <stdio.h> //standard input/output functions
#include <stdlib.h> //memory allocation and conversion of types functions
#include <string.h> //string manipulation functions
#include <ctype.h> //character functions like seeing if a char is a digit, a number or converting it to upper/lower case
#include <stdbool.h> //we can use boolean values in our code (true/false)

#define CHESSBOARD_SIZE 8 //Text substitution, the preprocessor reads it before compile time. Less error prone, easier to maintain.
#define BUFFER_SIZE 32 

int getColumnValue(char column) { //this switch statement is way cleaner
    switch (column) {
        case 'a': return 0;
        case 'b': return 1;
        case 'c': return 2;
        case 'd': return 3;
        case 'e': return 4;
        case 'f': return 5;
        case 'g': return 6;
        case 'h': return 7;
        default: return -1;
    }
}

static void strToLower(char *s) {
    for (; *s; ++s)
}

