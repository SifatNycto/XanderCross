#include <iostream>
#include <cstdlib>
#include <ctime>


class NumberGuessGame {
    private:
        int secretNumber;
        int guess = 0;
        int attempts = 0;

    public:
       NumberGuessGame() {
        srand(time(NULL));
        secretNumber = (rand() % 100) + 1;
       }
        
        void header_ngg() {
            std::cout << "\n+--------------------------------------+";
            std::cout << "\n|>>>      NUMBER GUESSING GAME      <<<|";
            std::cout << "\n+--------------------------------------+";
            std::cout << std::endl;
        }
        void play() {
            
            // NGG Game Header
            header_ngg();
            std::cout << "Guess a number between 1 to 100" << std::endl;

            // Game Loop
            while(guess != secretNumber)
            {
                std::cout << "Enter your guess: ";
                std::cin >> guess;
                attempts++;

                if (guess > secretNumber)
                    std::cout << "Too High" << std::endl;

                else if (guess < secretNumber)
                    std::cout << "Too Low" << std::endl;

                else
                {
                    std::cout << "Correct! You guessed correct" << std::endl;
                    std::cout << "Attempts: " << attempts;
                }
            }
        }
};

int main()
{
   NumberGuessGame ngg;
   ngg.play();
    
   return 0;
}