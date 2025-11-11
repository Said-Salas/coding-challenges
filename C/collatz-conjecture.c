#include <stdio.h>

int main(void) {
    int startingNumber = 0;
    int numberSteps = 0;
    printf("Select starting positive number: ");
    scanf("%d", &startingNumber);
    int endNumber = startingNumber;

    do {
        if (endNumber % 2 == 0) {
            endNumber /= 2;
            numberSteps += 1;
        }
        else {
            endNumber *= 3;
            endNumber += 1;
            numberSteps += 1;
        }

    } while (endNumber != 1);

    printf("The number of steps that took number %d to reach 1 are: %d", startingNumber, numberSteps);

    return 0;
}



// One evening, you stumbled upon an old notebook filled with cryptic scribbles, as though someone had been obsessively chasing an idea. On one page, a single question stood out: Can every number find its way to 1? It was tied to something called the Collatz Conjecture, a puzzle that has baffled thinkers for decades.

// The rules were deceptively simple. Pick any positive integer.

// If it's even, divide it by 2.
// If it's odd, multiply it by 3 and add 1.
// Then, repeat these steps with the result, continuing indefinitely.

// Curious, you picked number 12 to test and began the journey:

// 12 ➜ 6 ➜ 3 ➜ 10 ➜ 5 ➜ 16 ➜ 8 ➜ 4 ➜ 2 ➜ 1

// Counting from the second number (6), it took 9 steps to reach 1, and each time the rules repeated, the number kept changing. At first, the sequence seemed unpredictable — jumping up, down, and all over. Yet, the conjecture claims that no matter the starting number, we'll always end at 1.

// It was fascinating, but also puzzling. Why does this always seem to work? Could there be a number where the process breaks down, looping forever or escaping into infinity? The notebook suggested solving this could reveal something profound — and with it, fame, fortune, and a place in history awaits whoever could unlock its secrets.

// Instructions
// Given a positive integer, return the number of steps it takes to reach 1 according to the rules of the Collatz Conjecture.

