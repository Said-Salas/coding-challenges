#include <stdio.h>
#include <string.h> 
#include <ctype.h>

int chessPosition (int *column, int *row) {
    int tilePosition = 1;
    tilePosition *= row;

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
            printf("That column does not exist on the chessboard");
            return 1;
    }

    tilePosition += columnValue;
    return tilePosition;
}

void toLowerCase(char *column) {
    column = tolower(column);
}

int main(void) {
    char positionOne[] = "";
    char positionTwo[] = "";

    printf("Enter position of white queen: ");
    scanf("%s", &positionOne);
    printf("Enter position og black queen: ");
    scanf("%s", &positionTwo);

    int lenghtOne = strlen(positionOne);
    int lengthTwo = strlen(positionTwo);
   
    if (lengthOne > 2 || lengthTwo > 2) {
        printf("Please enter a valid chess position");
        return 1;
    }

    char columnOne = toLowerCase(positionOne[0]);
    char rowOne = toLowerCase(positionOne[1]);

    char columnTwo = positionTwo[0];
    char rowTwo = positionTwo[1];

    if ((strcmp(columnOne, columnTwo) == 0) || (strcmp(rowOne, rowTwo)) == 0) {
        printf("Queens can attack themselves");
        return 0;
    }

    const positionOne = chessPosition(columnOne, rowOne);
    const positionTwo = chessPosition(columnTwo, rowTwo);

    if ((positionOne % 2 != 0 && positionTwo % 2 != 0) || (positionOne % 2 == 0 && positionTwo % 2 == 0)) {
        printf("Queens are in a diagonal, therefore can attack themselves");
    }

    return 0;
}

// Instructions
// Given the position of two queens on a chess board, indicate whether or not they are positioned so that they can attack each other.

// In the game of chess, a queen can attack pieces which are on the same row, column, or diagonal.

// A chessboard can be represented by an 8 by 8 array.

// So if you are told the white queen is at c5 (zero-indexed at column 2, row 3) and the black queen at f2 (zero-indexed at column 5, row 6), then you know that the set-up is like so
// You are also able to answer whether the queens can attack each other. In this case, that answer would be yes, they can, because both pieces share a diagonal