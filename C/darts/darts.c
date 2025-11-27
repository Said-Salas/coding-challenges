#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 32


int parseChar(int *xI, int *yI, char *x, char *y) {
    xI = x - '0';
    yI = y - '0';
    if(!isdigit(xI) || !isdigit(yI)) return false;
    if(!)

}

int main(void) {
    printf("Press \"exit\" to end program");

    while (1) {
        char x, y;
        int xI, yI;
        printf("Enter 'x' coordinate of the dart: ");
        scanf("%c", &x);
        if(strcmp(x, "exit") == 0) break;
        printf("Enter 'y' coordinate of the dart: ")
        scanf("c", &y);

        int success = parseChar(&xI, &yI, &x, &y);
    }
    return 0;
}


//Instructions
// Calculate the points scored in a single toss of a Darts game.

// Darts is a game where players throw darts at a target.

// In our particular instance of the game, the target rewards 4 different amounts of points, depending on where the dart lands:

// If the dart lands outside the target, player earns no points (0 points).
// If the dart lands in the outer circle of the target, player earns 1 point.
// If the dart lands in the middle circle of the target, player earns 5 points.
// If the dart lands in the inner circle of the target, player earns 10 points.
// The outer circle has a radius of 10 units (this is equivalent to the total radius for the entire target), the middle circle a radius of 5 units, and the inner circle a radius of 1. Of course, they are all centered at the same point — that is, the circles are concentric defined by the coordinates (0, 0).

// Given a point in the target (defined by its Cartesian coordinates x and y, where x and y are real), calculate the correct score earned by a dart landing at that point.