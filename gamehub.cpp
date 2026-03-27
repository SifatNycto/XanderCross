#include <iostream>
#include <cstdlib>
#include <ctime>


class NumberGuessGame {
    private:
        int secretNumber;
        int guess = 0;
        int attempts = 0;
        int minRange = 1;
        int maxRange = 100;

    public:
       NumberGuessGame() {
        srand(time(NULL));
       }
        
        void header_ngg() {
            std::cout << "\n+--------------------------------------+";
            std::cout << "\n|>>>      NUMBER GUESSING GAME      <<<|";
            std::cout << "\n+--------------------------------------+";
            std::cout << std::endl;
        }

        void play() {
            char play_again;
            do
            {
                // NGG Game Header
                header_ngg();

                int choice;
                std::cout << "Choose Difficulty: ";
                std::cout << std::endl << "1. Easy\n2. Medium\n3. Hard" << std::endl;
                std::cout << "Choice here: ";
                std::cin >> choice;

                if (choice == 1) minRange = 1, maxRange = 10;
                else if (choice == 2) minRange = 1, maxRange = 100;
                else if (choice == 3) minRange = 1, maxRange = 1000;
                else
                {
                    std::cout << "Choice set to default" << std::endl;
                    minRange = 1, maxRange = 100;
                }

                secretNumber = rand() % (maxRange - minRange + 1) + minRange;

                std::cout << "Guess Between " << minRange << " to " << maxRange << std::endl;

                guess = 0;
                attempts = 0;
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
                        std::cout << "Attempts: " << attempts << std::endl;
                    }
                }
                std::cout << std::endl << "Play Again? (y/n): ";
                std::cin >> play_again;

                std::cout << std::endl;

            } while (play_again == 'y' || play_again == 'Y');
        }
};

int main()
{
   NumberGuessGame ngg;
   ngg.play();
    
   return 0;
}