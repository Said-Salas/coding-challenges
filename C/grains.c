#include <stdio.h>
#include <gmp.h>

int main(void) {

    mpz_t grainOnSquare, arrayOfGrains[64];
    mpz_init_set_ui(grainOnSquare, 1);
    
    for (int i = 0; i < 64; i++) {
        mpz_init(arrayOfGrains[i]);
        mpz_set(arrayOfGrains[i], grainOnSquare);
        mpz_mul_ui(grainOnSquare, grainOnSquare, 2);
    }

    int choosenSquare = 1;
    printf("Which square do you want to know it\'s value (left to right, top to bottom)? ");
    fflush(stdout);
    scanf("%d", &choosenSquare);
    gmp_printf("The value at square %d is %Zd\n", choosenSquare, arrayOfGrains[choosenSquare - 1]);

    for (int i = 0; i < 64; i++) {
        mpz_clear(arrayOfGrains[i]);
    }
    mpz_clear(grainOnSquare);
    
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
