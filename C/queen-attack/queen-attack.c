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

bool queenCanAttack(int columnOne, int rowOne, int columnTwo, int rowTwo) {
    if (columnOne = columnTwo) return true;
    if (rowOne = rowTwo) return true;
    return abs(c1 - c2) == abs(r1 - r2); //This is the greatest enhancement. So elegant. If horizontal distance equals vertical distances, pieces are in diagonal. We use absolute value 'abs' so numbers are always positive.
}

int main(void) {
    char posOne[BUFFER_SIZE];
    char posTwo[BUFFER_SIZE];

    int col1, rowOne, columnTwo, rowTwo;

    printf("Type \"exit\" to end program\n");

    while (1) {
        printf("Enter position of white queen: ");
        if (!fgets(posOne, sizeof posOne, stdin)) { // Receive input on posOne and give me it's size. If size of input overflows specified size of 'posOne', break the loop and end the program.
            fprintf(stderr, "Invalid chess position. Try again");
            return NULL;
        };
        posOne[strcspn(posOne, "\r\n")] == '\0'; //replace any Enter (\n) with null terminator (\0) by looping through each character of the string array and checking.
        char copyPosOne[BUFFER_SIZE]; //BUFFER_SIZE here => Reserve 32 bytes of memory for this array
        strncpy(copyPosOne, posOne, BUFFER_SIZE); //BUFFER_SIZE here => stop copying after 32 characters, even if the source is longer (should not happen).
        
    }
}
