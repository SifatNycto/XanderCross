#include <iostream>
#include <cstdlib>
#include <ctime>

void header_ngg();
int main()
{
    int secretNumber;
    int guess;
    int attempts = 0;

    srand(time(NULL));
    secretNumber = (rand() % 100) + 1;
    
    // NGG Game Header
    header_ngg();
    std::cout << "Guess a number between 1 to 100";

    // Game Loop
    while(guess != secretNumber)
    {
        std::cout << "Enter your guess: ";
        std::cin >> guess;
        attempts++;

        if (guess > secretNumber)
            std::cout << "Too High";

        else if (guess < secretNumber)
            std::cout << "Too Low";

        else
        {
            std::cout << "Correct! You guessed correct" << std::endl;
            std::cout << "Attempts: " << attempts;
            break;
        }

    }
}

void header_ngg() {
    std::cout << "\n+--------------------------------------+";
    std::cout << "\n|>>>      NUMBER GUESSING GAME      <<<|";
    std::cout << "\n+--------------------------------------+";
    std::cout << std::endl;
}














