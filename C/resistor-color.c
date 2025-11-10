#include <stdio.h>
#include <ctype.h>
#include <string.h>

const char *colors[] = {
    "black", "brown", "red", "orange", "yellow", 
    "green", "blue", "violet", "grey", "white"
};

int colorCode(const char *color) {
    for (int i = 0; i < 10; i++) {
        if (strcmp(color, colors[i]) == 0) {
            return i;
        }
    }
    return -1;  //Means => 'Not found'
}

void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int main(void) {
    char input[100];
    printf("(type \"exit\" to end program)\n");

    do {
        printf("What color do you see? Color: e");
        scanf("%99s", input);
       
        toLowerCase(input);
        
        if (strcmp(input, "exit") == 0) {
            break;
        }

        int resValue = colorCode(input);
        if (resValue == -1) {
            printf("The color you entered does not have an assigned resistance value yet\n");
        }
        else {
            printf("%s has a resistance value of: %d\n", input, resValue);
        }

    } while (1); //infinite loop
    
   
    return 0;
}


// Instructions
// If you want to build something using a Raspberry Pi, you'll probably use resistors. For this exercise, you need to know two things about them:

// Each resistor has a resistance value.
// Resistors are small - so small in fact that if you printed the resistance value on them, it would be hard to read.
// To get around this problem, manufacturers print color-coded bands onto the resistors to denote their resistance values. Each band has a position and a numeric value.

// The first 2 bands of a resistor have a simple encoding scheme: each color maps to a single number.

// In this exercise you are going to create a helpful program so that you don't have to remember the values of the bands.

// These colors are encoded as follows:

// black: 0
// brown: 1
// red: 2
// orange: 3
// yellow: 4
// green: 5
// blue: 6
// violet: 7
// grey: 8
// white: 9
// The goal of this exercise is to create a way:

// to look up the numerical value associated with a particular color band
// to list the different band colors
// Mnemonics map the colors to the numbers, that, when stored as an array, happen to map to their index in the array: Better Be Right Or Your Great Big Values Go Wrong.