#include <stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    srand(time(0));

    int randomNumber = (rand()%100) + 1;
    int No_of_guesses = 0;
    int guessed_number;

    do {
        printf("Guess the number : ");
        scanf("%d",&guessed_number);
        if (guessed_number>randomNumber){
            printf("Lower number please!\n");
        }
        else if (randomNumber>guessed_number){
            printf("Higher Number please!\n");
        }
        else {
            printf("Congrats!!\n");
        }
         No_of_guesses++;
        }while (guessed_number != randomNumber);

        printf("You gussed the number in %d gusses",No_of_guesses);

    



    
    return 0;
}