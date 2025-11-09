#include <stdio.h>

int main(void) {
    int grainOnSquare = 1;
    int arrayOfGrains[64];

    for (int i = 0; i < 64; i++) {
         if (i == 0) {
            arrayOfGrains[i] = grainOnSquare;
         }
         grainOnSquare *= 2;
         arrayOfGrains[i] = grainOnSquare;
         printf("%d\n", arrayOfGrains[i]);
    }

    printf("What square do you wish to know it\'s number of grains? ");
    int wishedSquare = 0;
    fflush(stdout);
    scanf("%d", &wishedSquare);
    printf("The number of")

    return 0;
}

// Introduction
// There once was a wise servant who saved the life of a prince. The king promised to pay whatever the servant could dream up. Knowing that the king loved chess, the servant told the king he would like to have grains of wheat. One grain on the first square of a chessboard, with the number of grains doubling on each successive square.

// Instructions
// Calculate the number of grains of wheat on a chessboard.

// A chessboard has 64 squares. Square 1 has one grain, square 2 has two grains, square 3 has four grains, and so on, doubling each time.

// Write code that calculates:

// the number of grains on a given square
// the total number of grains on the chessboard
