#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int getComputerChoice()
{
    return (rand() % 3) + 1;  // 1 = Rock, 2 = Paper, 3 = Scissors
}

int determineWinner(int player, int computer)
{
    if (player == computer) return 0;  // Draw
    else if ((player == 1 && computer == 3) ||
             (player == 2 && computer == 1) ||
             (player == 3 && computer == 2))
        return 1;  // Player wins
    else
        return -1; // Computer wins
}

int main()
{
    int playerChoice, computerChoice, result;
    char *choices[] = {"Invalid", "Rock", "Paper", "Scissors"};

    // initialize random number generator ONCE at the start
    srand(time(NULL)); // use current time as seed

    printf("=== Rock, Paper, Scissors Game ===\n");
    printf("1 = Rock\n2 = Paper\n3 = Scissors\n");

    while (1)
    {
        printf("\nEnter your choice (1/2/3), or 0 to quit: ");
        scanf("%d", &playerChoice);

        if (playerChoice == 0)
        {
            printf("Game ended. Thanks for playing!\n");
            break;
        }

        if (playerChoice < 1 || playerChoice > 3)
        {
            printf("Invalid input! Please enter 1, 2, or 3.\n");
            continue;
        }

        computerChoice = getComputerChoice();

        printf("You chose: %s\n", choices[playerChoice]);
        printf("Computer chose: %s\n", choices[computerChoice]);

        result = determineWinner(playerChoice, computerChoice);

        if (result == 0)
            printf("Result: It's a draw!\n");
        else if (result == 1)
            printf("Result: You win!\n");
        else
            printf("Result: Computer wins!\n");
    }

    return 0;
}
