#include <stdio.h>

int main(void){
    int numberLimit;
    printf("Up to what natural number shall I calculate?: ");
    fflush(stdout);
    scanf("%d", &numberLimit);

    int sumOne = 0;
    for (int i = 1; i <= numberLimit; i++){
        sumOne += i;
    }
   int squareOfSum = sumOne * sumOne;

   int sumTwo = 0;
   for (int i = 1; i <= numberLimit; i++){
        sumTwo += i * i;
   }
   
   int differenceOfSums = squareOfSum - sumTwo;
   printf("The difference of the sums is: %d", differenceOfSums);

   return 0;
}