#include <stdio.h>

int main(void) {
    int year;
    printf("Enter year: ");
    fflush(stdout);
    scanf("%d", &year);

    if (year % 100 == 0 && year % 400 == 0) {
        printf("The year is leap\n");
    }
    else if (year % 4 == 0 && year % 100 != 0){
        printf("The year is leap\n");
    }
    else {
        printf("Year ain't leap\n");
    }
    return 0;
}