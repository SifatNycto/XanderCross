#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    int num, guess, tries = 0;
    srand(time(NULL));
    num = (rand() % 100) + 1;
    std::cout << "\n+--------------------------------------+";
    std::cout << "\n|>>>      NUMBER GUESSING GAME      <<<|";
    std::cout << "\n+--------------------------------------+";
    
    std::cout << std::endl;
    
    do
    {
        std::cout << "\nEnter number guess between (1-100): ";
        std::cin >> guess;
        tries++;

        if (guess > num) std::cout << '\n' << "Guess is too high.";
        else if (guess < num) std::cout << '\n' << "Guess is too low..";
        else
        {
            std::cout << "\n\n" << "CORRECT GUESS!!!";
            std::cout << '\n' << "You tried " << tries << " times.";
        }
        
    } while (guess != num);
    
    return 0;
}