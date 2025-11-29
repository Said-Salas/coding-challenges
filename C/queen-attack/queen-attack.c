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

void strToLower(char *s) { //'S' = 83' (ASCII value) => tolower(83) returns 115. 's' = '115'. char(115) returns 's'.
    for (; *s; ++s) *s = (char)tolower((unsigned char)*s); // we use 'unsigned char' to make positive the ASCII value because 'tolower()' expects positive values from 0 to 255(ASCII range) and our character could or could not be signed. If signed, char would be negative and would cause bugs.
}

void trimString(char *str) { 
    char *start = str; //Trim leading spaces. Var 'start' points to 'str[0]'. 
    while(*start && isspace((unsigned char)*start)) start++;
    if (start != str) {
        memmove(str, start, strlen(start) + 1);
    }
    
    size_t len = strlen(str); //Trim trailing spaces
    while (len > 0 && isspace((unsigned char)str[len - 1])) {
        str[--len] = '\0';
    } 
}  

void flushInputBuffer(const char *buffer) {
    if (strchr(buffer, '\n') == NULL) {
        int leftoverHolder; //Int type can hold all 257 values from ASCII, and the 257th value is -1, which means (EOF)--end of file. This occurs if input pipe is empty/closed/even broken. Char types can only hold 256 characters. Int holds 0-256. Char holds 0-255. We count the '0' as 1.
        while ((leftoverHolder = getchar()) != '\n' && leftoverHolder != EOF); //There is no loop body, since 'getchar()' grabs leftover characters in the input stream and passes them to variable 'leftoverHolder'. This process cleans up the input (stdin) already, which is great.
    }
}

bool parsePosition(const char *input, int *col, int *row) {
    if (!input) return false;
    size_t len = strlen(input);
    if (len != 2) return false;
    char rawColumn = (char)tolower((unsigned char)input[0]); //input[0] is implicit dereference, so we don't write '*(input + 0).
    if (!isalpha((unsigned char) rawColumn)) return false;
    int columnValue = getColumnValue(rawColumn);
    if (columnValue < 0) return false;
    if (!isdigit((unsigned char)input[1])) return false;
    int rowValue = input[1] - '1';
    if (rowValue < 0 || rowValue >= CHESSBOARD_SIZE) return false;
    *col = columnValue;
    *row = rowValue;
    return true;
}

bool queenCanAttack(int columnOne, int rowOne, int columnTwo, int rowTwo) {
    if (columnOne == columnTwo && rowOne == rowTwo) {
        fprintf(stderr, "Positions must be different\n");
        return false;
    }
    if (columnOne == columnTwo) return true;
    if (rowOne == rowTwo) return true;
    return abs(columnOne - columnTwo) == abs(rowOne - rowTwo); //This is the greatest enhancement. So elegant. If horizontal distance equals vertical distances, pieces are in diagonal. We use absolute value 'abs' so numbers are always positive.
}

int main(void) {
    char posOne[BUFFER_SIZE];
    char posTwo[BUFFER_SIZE];

    int colOne, rowOne, colTwo, rowTwo;

    printf("Type \"exit\" to end program\n");

    while (1) {
        printf("Enter position of white queen: ");
        if (!fgets(posOne, sizeof posOne, stdin)) break; // Receive input on posOne and give me it's size. If size of input overflows specified size of 'posOne' --defined by 'BUFFER_SIZE'-- trim it and keep what can be fitted. For instance, entering a 50 byte string will cause 'fgets' to only store up to 31 characters + null terminator. 1 character = 1 byte(8 bits).
        //However, 'fgets' returns 'False' when the input stream is closed/dead. Pressing Ctrl+D (Mac) or Ctrl+Z (Windows) closes the pipe feeding data to the program and would make the expression falsy, exiting loop and ending the program.
        
        flushInputBuffer(posOne);
        posOne[strcspn(posOne, "\r\n")] = '\0'; //replace any Enter (\n) with null terminator (\0) by looping through each character of the string array and checking. We use '\r\n' because Windows uses it to end a line and begin a new one, whereas MacOS\Linux only uses '\n' to do the same. The function says: 'Loop through each character of the input and if it matches anything inside '\r\n', replace it with the null terminator "\0"'. Note, it has to match either '\r' or '\n', and won't return a match for only the '\' or only the 'n'.
        trimString(posOne);
        
        char copyPosOne[BUFFER_SIZE]; //BUFFER_SIZE here => Reserve 32 bytes of memory for this array
        strncpy(copyPosOne, posOne, BUFFER_SIZE); //BUFFER_SIZE here => stop copying after 32 characters, even if the source is longer (should not happen).
        copyPosOne[BUFFER_SIZE - 1] = '\0';
        strToLower(copyPosOne);
        if (strcmp(copyPosOne, "exit") == 0) break;

        printf("Enter position of black queen: ");
        if (!fgets(posTwo, sizeof posTwo, stdin)) break;

        flushInputBuffer(posTwo);
        posTwo[strcspn(posTwo, "\r\n")] = '\0';
        trimString(posTwo);

        char copyPosTwo[BUFFER_SIZE];
        strncpy(copyPosTwo, posTwo, BUFFER_SIZE);
        copyPosTwo[BUFFER_SIZE - 1] = '\0';
        strToLower(copyPosTwo);
        if(strcmp(copyPosTwo, "exit") == 0) break;

        if (!parsePosition(copyPosOne, &colOne, &rowOne)) {
            fprintf(stderr, "Please enter a valid chess position for the white queen.\n");
            continue; //we don't exit loop or end program, rather we skip the current iteration and go back to the top of loop again. This will let user start 'fresh' and enter input again.
        }
        if (!parsePosition(copyPosTwo, &colTwo, &rowTwo)) {
            fprintf(stderr, "Please enter a valid chess position for the black queen.\n");
            continue;
        }

        if (queenCanAttack(colOne, rowOne, colTwo, rowTwo)) {
            printf("Queens can attack each other\n");
        } else {
            printf("Queens can't attack each other\n");
        }
    }

    return 0;
}

// Given the position of two queens on a chess board, indicate whether or not they are positioned so that they can attack each other.

// In the game of chess, a queen can attack pieces which are on the same row, column, or diagonal.

// A chessboard can be represented by an 8 by 8 array.

// So if you are told the white queen is at c5 (zero-indexed at column 2, row 3) and the black queen at f2 (zero-indexed at column 5, row 6), then you know that the set-up is like so:

// A chess board with two queens. Arrows emanating from the queen at c5 indicate possible directions of capture along file, rank and diagonal.

// You are also able to answer whether the queens can attack each other. In this case, that answer would be yes, they can, because both pieces share a diagonal.