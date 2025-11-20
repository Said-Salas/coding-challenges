#include <stdio.h>
#include <string.h> 
#include <ctype.h>
#include <stdlib.h>

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

//A diagonal consists of an array of length 2 [x, y], where x = column and y = row.
int** getDiagonals(const int startingArray[2], int* arraySize) {
    int capacity = 8; //Initial capacity of totalDiagonals (number of pairs it can hold before resizing)
    int storedDiagonals = 0; //Stored diagonals so far
    int** pointerArray = malloc(capacity * sizeof(int*)); //Here we start with an arbitrary memory capacity, we say 'in the case of 8 diagonals found, we allocate this much memory => each diagonal found is an array of 2 integers, each integer is 4 bytes worth of memory. Therefore, per diagonal we have 8 bytes worth of memory occupied. 8 bytes used per diagonal per 8 diagonals found = 64 bytes of memory capacity we are allocating here, as an inital guess. The memory capacity will --of course-- grow as needed.
    if (!totalDiagonals) {
        fprintf(stderr, "Memory allocation failed, try again\n"); //we use 'fprintf to indicate that we want to stream the message to the standard error (stderr) stream. 'printf' is used to ouput something in the terminal (standard output => stdout)
        *arraySize = 0;
        return NULL;  //If memory allocation fails, we return NULL (standard way to indicate failure in C)
    }

    int currentColumn, currentRow, potentialColumn, potentialRow; //we modify current column and row, and becomesare our potential column and row, and is 'potential' because we validate it. If truthy, currentColumn, currentRow = potentialColumn, potentialRow. If falsy, we break/stop the loop.
    currentColumn = startingArray[0];
    currentRow = startingArray[1];

    while(1) {
        if (currentColumn == 0 || currentRow == 0) break;
        potentialColumn = currentColumn - 1; // We go to the left over x axis, then downwards (y axis)
        potentialRow = currentRow - 1;
        int* diagonal = malloc(2 * sizeof(int));
        if (!diagonal) {
            fprintf(stderr, "Memory allocation failed, try again\n");
            return NULL;
        } //If memory allocation failed here, it is better to rerun the program in this case, since totalDiagonals might not have all positions/coordinates that correspond to a diagonal. Hence our algorithm could say our pieces aren't in a diagonal but because there wasn't enough memory to save all pairs of found coordinates/positions that correspond to diagonals.
        diagonal[0] = potentialColumn;
        diagonal[1] = potentialRow;
        if (storedDiagonals == capacity) {
            capacity *= 2; //If our capacity is full, we resize our allocated memory for more bytes. We multiply by 2 because it is a good number to multiply by--meaning it gives us enough memory for our task without allocating too much unnecessary memory in the RAM (that would be poor efficiency).
            int** newCapacity = realloc(pointerArray, capacity * sizeof(int*));
            if (!newCapacity) { 
                free(diagonal, pointerArray);
                fprintf(stderr, "Memory reallocation failed, try again\n");
                return NULL;
            }
            pointerArray = newCapacity;
        } 
        pointerArray[storedDiagonals++] = diagonal;
        currentColumn = potentialColumn;
        currentRow = potentialRow;
    }

    currentColumn = startingArray[0];
    currentRow = startingArray[1];

    while (1) {
        if (currentColumn == 0 || currentRow ==7 ) break;
        potentialColumn = currentColumn - 1;
        potentialRow = currentColumn + 1; //We now go to the left over x axis, then upwards (y axis)
        int* diagonal = malloc(2 * sizeof(int));
        if (!diagonal) {
            fprintf(stderr, "Memory allocation failed, try again\n");
            return NULL;
        }
        diagonal[0] = potentialColumn;
        diagonal[1] = potentialRow;
        if (storedDiagonals == capacity) {
            capacity *= 2;
            int** newCapacity =  realloc(pointerArray, capacity *sizeof(int*));
            if(!newCapacity) {
                free(diagonal, pointerArray);
                fprintf(stderr, "Memory reallocation failed, try again\n");
                return NULL;
            }
            pointerArray = newCapacity;
        }
        pointerArray[storedDiagonals++] = diagonal;
        currentColumn = potentialColumn;
        currentRow = potentialRow;
    } 

    currentColumn = startingArray[0];
    currentRow =  startingArray[1];
    
    while (1) {
        if (currentColumn == 7 || currentRow == 0) break;
        potentialColumn = currentColumn + 1;
        potentialRow = currentRow - 1;
        int* diagonal = malloc(2 * sizeof(int));
        if (!diagonal) {
            fprintf(stderr, "Memory allocation failed, try again\n");
            return NULL;
        }
        diagonal[0] = potentialColumn;
        diagonal[1] = potentialRow;
        if (storedDiagonals == capacity) {
            capacity *= 2;
            int** newCapacity = realloc(pointerArray, capacity *sizeof(int*));
            if (!newCapacity) {
                free(diagonal, pointerArray);
                fprintf(stderr, "Memory reallocation failed, try again\n");
                return NULL;
            }
            pointerArray = newCapacity;
        }
        pointerArray[storedDiagonals++] = diagonal;
        currentColumn = potentialColumn;
        currentRow = potentialRow;
    }

    currentColumn = startingArray[0];
    currentRow = startingArray[1];

    while (1) {
        if (currentColumn == 7 || currentRow == 7) break;
        potentialColumn = currentColumn + 1;
        potentialRow = currentRow + 1;
        int* diagonal = malloc(2 * sizeof(int));
        if (!diagonal) {
            fprintf(stderr, "Memory allocation failed, try again\n");
            return NULL;
        }
        diagonal[0] = potentialColumn;
        diagonal[1] = potentialRow;
        if (storedDiagonals == capacity) {
            capacity *= 2;
            int** newCapacity = realloc(pointerArray, capacity *sizeof(int*));
            if (!newCapacity) {
                free(diagonal, pointerArray);
                fprintf(stderr, "Memory reallocation failed, try again\n");
                return NULL;
            }
            pointerArray = newCapacity;
        }
        pointerArray[storedDiagonals++] = diagonal;
        currentColumn = potentialColumn;
        currentRow = potentialRow;
    }

    if (storedArrays == 0) {
        free(pointerArray);
        arraySize = 0;
        
    }
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