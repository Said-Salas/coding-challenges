#include <stdio.h>
#include <ctype.h>
#include <string.h>

void toLowerCase (char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

const char *colors[] = {
    "black", "brown", "red", "orange", "yellow", 
    "green", "blue", "violet", "grey", "white"
};

int colorCode(char *color) {
    for (int i = 0; i < 10; i++) {
        if (strcmp(color, colors[i]) == 0) {
            return i;
        }
    }
    return -1; //Not found in the colors array
}

int main(void) {
    char input[100];

    printf("(Type \"exit\" to end program)\n");

    do {
        printf("What color do you see? \n");
        scanf("%s", input);
        toLowerCase(input);

        if (strcmp(input, "exit") == 0) break; 
        
        int resistanceValue = colorCode(input);

        if (resistanceValue != -1) {
            printf("Color %s has a resistance value of %d.\n", input, resistanceValue);
        }
        else {
            printf("Entered color doesn't have an assigned resistance value yet.\n");
        }

    } while (1 > 0);

    return 0;
}

