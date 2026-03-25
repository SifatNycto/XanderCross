#include <iostream>
#include <cstdlib>
#include <ctime>

char user_choice();
char computer_choice();
void show_choice(char choice);
void choose_Winner(char player, char computer);

int main()
{
    srand(time(NULL));
    char player, computer;

    std::cout << "+-------------------------+" << std::endl;
    std::cout << "| ROCK-PAPER-SCISSOR GAME |" << std::endl;
    std::cout << "+-------------------------+" << std::endl;
    std::cout << std::endl;

    player = user_choice();
    std::cout << std::endl << "You choose: ";
    show_choice(player);

    computer = computer_choice();
    std::cout << std::endl << "Computers choice: ";
    show_choice(computer);

    std::cout << std::endl << std::endl;

    choose_Winner(player, computer);

    std::cout << std::endl;

    return 0;
}

char user_choice()
{
    char player;
    do
    {
        std::cout << std::endl << "Choose among them -> Rock || Paper || Scissor";
        std::cout << std::endl << "    'r' is for Rock";
        std::cout << std::endl << "    'p' is for Paper";
        std::cout << std::endl << "    's' is for Scissor";
        std::cout << std::endl << "    Enter here: ";
        std::cin >> player;

    } while (player != 'r' && player != 'p' && player != 's');
    
    return player;
}

char computer_choice()
{
    int computer_choice = (rand() % 3) + 1;

    switch (computer_choice)
    {
        case 1: return 'r';
        case 2: return 'p';
        case 3: return 's';
        default: return 'r';
    }
}

void show_choice(char choice)
{
    switch (choice)
    {
        case 'r': std::cout << "Rock";
                    break;
        case 'p': std::cout << "Paper";
                    break;
        case 's': std::cout << "Scissor";
                    break;
    }
}

void choose_Winner(char player, char computer)
{
    switch (player)
    {
        case 'r':
                    if (computer == 'r')
                    {
                        std::cout << "Oops... It's a tie!";
                    }
                    else if (computer == 'p')
                    {
                        std::cout << "Ha Ha Ha, Shame on you\nYou lose!";
                    }
                    else
                    {
                        std::cout << "Congratulations.... You win!";
                    }
                    break;
        case 'p':
                    if (computer == 'r')
                    {
                        std::cout << "Congratulations.... You win!";
                    }
                    else if (computer == 'p')
                    {
                        std::cout << "Oops... It's a tie!";
                    }
                    else
                    {
                        std::cout << "Ha Ha Ha, Shame on you\nYou lose!";
                    }
                    break;
        case 's':
                    if (computer == 'r')
                    {
                        std::cout << "Ha Ha Ha, Shame on you\nYou lose!";
                    }
                    else if (computer == 'p')
                    {
                        std::cout << "Congratulations.... You win!";
                    }
                    else
                    {
                        std::cout << "Oops... It's a tie!";
                    }
                    break;
    }
            
}