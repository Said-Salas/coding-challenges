#include <stdio.h>

int main(void) {
    unsigned long long grainOnSquare = 1;
    unsigned long long arrayOfGrains[64];
    unsigned long long totalGrains = 1;

    for (int i = 0; i < 64; i++) {
         if (i == 0) {
            arrayOfGrains[i] = grainOnSquare;
            // printf("%llu\n", arrayOfGrains[i]);
         }
         else {
            grainOnSquare *= 2;
            arrayOfGrains[i] = grainOnSquare;
            totalGrains += grainOnSquare;
            // printf("%llu\n", arrayOfGrains[i]);
         }
    }

    printf("What square do you wish to know it\'s number of grains? ");
    int wishedSquare = 0;
    fflush(stdout);
    int result = scanf("%d", &wishedSquare);

    if (result == 1) {
        printf("The number of grains at square %d is: %llu\n", wishedSquare, arrayOfGrains[wishedSquare - 1]);
        printf("The total number of grains on the chessboard is: %llu\n", totalGrains);
    }
    else {
        printf("An invalid value was entered. Try again.");
    }

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
