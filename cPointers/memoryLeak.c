#include <stdio.h>
#include <stdlib.h>

int cash = 100;

int main(){
    printf("\n");
    
    int bet;
    int location = 0;

    while((cash > 0) && (bet != -1)){
        printf("Enter Bet: (-1 to quit)\n");
        scanf("%d", &bet);
        if(bet<=cash){
            cash -= bet;
            printf("Enter Guess\n");
            int guess = -1;
            scanf("%d", &guess);
            if (location == guess){
                printf("Correct Guess!!\n");
                cash += 3*bet;
            }
            else{
                printf("Wrong Guess\n");
            }
        }
        else{
            printf("Invalid Bet\n");
        }
        printf("Availiable Cash = %d\n", cash);
    }
    

    printf("\n");
    return 0;
}