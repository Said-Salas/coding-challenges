#include <stdio.h>
#include <string.h> 
#include <ctype.h>

int getColumnValue (char column) {
    int columnValue = 0;

    switch(column) {
        case 'a':
            columnValue = 0;
            break;
        case 'b':
            columnValue = 1;
            break;
        case 'c':
            columnValue = 2;
            break;
        case 'd':
            columnValue = 3;
            break;
        case 'e':
            columnValue = 4;
            break;
        case 'f':
            columnValue = 5;
            break;
        case 'g':
            columnValue = 6;
            break;
        case 'h':
            columnValue = 7;
            break;
        default:
            printf("That column does not exist on the chessboard\n");
            return 1;
    }

    return columnValue;
}



int main(void) {
    printf("Type \"exit\" to end program\n");

    do {
        char positionOne[3] = "";
        char positionTwo[3] = "";

        printf("Enter position of white queen: ");
        scanf("%s", positionOne);
        if (strcmp(positionOne, "exit") == 0) break;
        printf("Enter position of black queen: ");
        scanf("%s", positionTwo);
    
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

        int columnOne = getColumnValue(tolower(positionOne[0]));
        int columnTwo = getColumnValue(tolower(positionTwo[0]));

        int rowOne = positionOne[1] - '1';
        int rowTwo = positionTwo[1] - '1';

        if ((columnOne == columnTwo) && (rowOne == rowTwo)) {
            printf("Positions must be different\n");
            return 1;
        }
        
        if ((columnOne == columnTwo) || (rowOne == rowTwo)) {
            printf("Queens can attack themselves\n");
        }
        else {
            if () {
                printf("Queens are in a diagonal, therefore can attack themselves\n");
            }
            else {
                printf("Your queens can't attack each other currently\n");
            }
        }
    } while (1 > 0);

    return 0;
}

// Instructions
// Given the position of two queens on a chess board, indicate whether or not they are positioned so that they can attack each other.

// In the game of chess, a queen can attack pieces which are on the same row, column, or diagonal.

// A chessboard can be represented by an 8 by 8 array.

// So if you are told the white queen is at c5 (zero-indexed at column 2, row 3) and the black queen at f2 (zero-indexed at column 5, row 6), then you know that the set-up is like so
// You are also able to answer whether the queens can attack each other. In this case, that answer would be yes, they can, because both pieces share a diagonal