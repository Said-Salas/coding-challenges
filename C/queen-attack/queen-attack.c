#include <stdio.h>
#include <string.h> 

int chessPosition (int *row, int *column) {
    int tilePosition = 1;
    tilePosition *= row;
}

int main(void) {
    char positionOne[] = "";
    printf("Enter position of white queen: ");
    scanf("%s", &positionOne);
    char columnOne = positionOne[0];
    char rowOne = positionOne[1];

    char positionTwo[] = "";
    printf("Enter position og black queen: ");
    scanf("%s", &positionTwo);
    char columnTwo = positionTwo[0];
    char rowTwo = positionTwo[1];

    if ((strcmp(columnOne, columnTwo) == 0) || (strcmp(rowOne, rowTwo)) == 0) {
        printf("Queens can attack themselves");
        return 0;
    }

    return 0;
}

// Instructions
// Given the position of two queens on a chess board, indicate whether or not they are positioned so that they can attack each other.

// In the game of chess, a queen can attack pieces which are on the same row, column, or diagonal.

// A chessboard can be represented by an 8 by 8 array.

// So if you are told the white queen is at c5 (zero-indexed at column 2, row 3) and the black queen at f2 (zero-indexed at column 5, row 6), then you know that the set-up is like so
// You are also able to answer whether the queens can attack each other. In this case, that answer would be yes, they can, because both pieces share a diagonal