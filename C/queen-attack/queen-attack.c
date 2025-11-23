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

static void strToLower(char *s) { //'S' = 83' (ASCII value) => tolower(83) returns 115. 's' = '115'. char(115) returns 's'.
    for (; *s; ++s) *s = (char)tolower((unsigned char)*s); // we use 'unsigned char' to make positive the ASCII value because 'tolower()' expects positive values from 0 to 255(ASCII range) and our character could or could not be signed. If signed, char would be negative and would cause bugs.
}

bool parsePosition(const char *input, int *col, int *row) {
    if (!input) return false;
    size_t len = strlen(input);
    if (len != 2) return false;
    char rawColumn = (char)tolower((unsigned char)input[0]);
    if (!isalpha((unsigned char) rawColumn)) return false;
    int columnValue = getColumnValue(rawColumn);
    if (columnValue < 0) return false;
    if (!isdigit((unsigned char)s[1])) return false;
    int rowValue = s[1] - '1';
    if (rowValue < 0 || rowValue >= CHESSBOARD_SIZE) return false;
    *col = columnValue;
    *row = rowValue;
    return true;
}

