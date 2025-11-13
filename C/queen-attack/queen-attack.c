#include <stdio.h>
#include <string.h> 
#include <ctype.h>

int chessPosition (int *column, int *row) {
    if (row > 8) {
        printf("Please enter a valid row value\n");
        return 1;
    }

    if (row == 1) {
        int tilePosition = 0;
    }
    else {
        tilePosition = 8;
        tilePosition *= row - 1;
    }
    
    int columnValue = 0;

    switch(column) {
        case 'a':
            columnValue = 1;
            break;
        case 'b':
            columnValue = 2;
            break;
        case 'c':
            columnValue = 3;
            break;
        case 'd':
            columnValue = 4;
            break;
        case 'e':
            columnValue = 5;
            break;
        case 'f':
            columnValue = 6;
            break;
        case 'g':
            columnValue = 7;
            break;
        case 'h':
            columnValue = 8;
            break;
        default:
            printf("That column does not exist on the chessboard\n");
            return 1;
    }

    tilePosition += columnValue;
    return tilePosition;
}

int main(void) {

    char positionOne[] = "";
    char positionTwo[] = "";

    printf("Enter position of white queen: ");
    scanf("%s", &positionOne);
    printf("Enter position og black queen: ");
    scanf("%s", &positionTwo);
   
    if ((strlen(positionOne) > 2 || strlen(positionOne) < 2) || (strlen(positionTwo) > 2 || strlen(positionTwo) < 2)) {
        printf("Please enter a valid chess position\n");
        return 1;
    }

    if (!isalpha(tolower(positionOne[0])) || !isalpha(tolower(positionTwo[0]))) {
        printf("Please enter a valid column letter\n");
        return 1;
    }

    if (!isdigit(positionOne[1]) || !isdigit(positionTwo[1])) {
        printf("Please enter a valid row number\n");
        return 1;
    }

    char columnOne = tolower(positionOne[0]);
    char columnTwo = tolower(positionTwo[0]);

    int rowOne = atoi(positionOne[1]);
    int rowTwo = atoi(positionTwo[1]);

    if ((strcmp(columnOne, columnTwo) == 0) && (rowOne == rowTwo)) {
        printf("Positions must be different\n");
        return 1;
    }
    
    if ((strcmp(columnOne, columnTwo) == 0) || (rowOne == rowTwo)) {
        printf("Queens can attack themselves\n");
        return 0;
    }

    int higherPosition = (chessPosition(columnOne, rowOne) > chessPosition(columnTwo, rowTwo)) ? chessPosition(columnOne, rowOne) : chessPosition(columnTwo, rowTwo);
    int lowerPosition = (chessPosition(columnOne, rowOne) < chessPosition(columnTwo, rowTwo)) ? chessPosition(columnOne, rowOne) : chessPosition(columnTwo, rowTwo);

    if (((higherPosition - lowerPosition) % 7 == 0) || ((higherPosition - lowerPosition) % 9 == 0)) {
        printf("Queens are in a diagonal, therefore can attack themselves\n");
    }
    else {
        printf("Your queens can't attack each other currently");
    }

    return 0;
}

// Instructions
// Given the position of two queens on a chess board, indicate whether or not they are positioned so that they can attack each other.

// In the game of chess, a queen can attack pieces which are on the same row, column, or diagonal.

// A chessboard can be represented by an 8 by 8 array.

// So if you are told the white queen is at c5 (zero-indexed at column 2, row 3) and the black queen at f2 (zero-indexed at column 5, row 6), then you know that the set-up is like so
// You are also able to answer whether the queens can attack each other. In this case, that answer would be yes, they can, because both pieces share a diagonal