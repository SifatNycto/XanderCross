#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>


class NumberGuessGame {
    private:
        int secretNumber;
        int guess = 0;
        int attempts = 0;
        int minRange = 1;
        int maxRange = 100;

        int totalGames = 0;
        int wins = 0;
        int losses = 0;

        int playerTurn;
        std::string player1Name;
        std::string player2Name;
        std::string randPlayer;
        std::string guessPlayer;

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

       
        int modeSelection() {
            int Mode;
            std::cout << "Modes: " << std::endl;
            std::cout << "1. Play with computer" << std::endl;
            std::cout << "2. Play with friend" << std::endl;
            std::cout << "Choose Mode (1/2): ";
            std::cin >> Mode;

            return Mode;
        }
        void play() {
            char play_again;
            do
            {
                // NGG Game Header
                header_ngg();

                

                int choice;
                int Max_attempts;
                int mode;

                // Mode Selection...............
                mode = modeSelection();
                
                if (mode == 1)
                {
                    std::cout << std::endl << "Enter player name: ";
                    std::cin >> player1Name;
                    randPlayer = player1Name;

                    difficulty(&choice, &minRange, &maxRange, &Max_attempts);
                    secretNumber = rand() % (maxRange - minRange + 1) + minRange;
                }
                else if (mode == 2)
                {
                    difficulty(&choice, &minRange, &maxRange, &Max_attempts);
                    std::cout << std::endl << "Enter player 1 name: ";
                    std::cin >> player1Name;
                    std::cout << std::endl << "Enter player 2 name: ";
                    std::cin >> player2Name;

                    playerTurn = (rand() % 2) + 1;
                    // std::string randPlayer;

                    if (playerTurn == 1)
                        std::cout << "\nNow " << player1Name << " will set the Secret Number.", randPlayer = player1Name;
                    else 
                        std::cout << "\nNow " << player2Name << " will set the Secret Number.", randPlayer = player2Name;

                    while (true)
                    {
                        std::cout << std::endl << randPlayer << ", Enter secret number between " << minRange << " and " << maxRange << ": ";
                        std::cin >> secretNumber;

                        if (secretNumber >= minRange && secretNumber <= maxRange) break;
                        else std::cout << std::endl << "Invalid Secret Number Setting !";
                    }
                    // calling clear screen..............
                    clear_screen();
                }
                else {
                    std::cout << "Invalid mode choice!\nMode set to default" << std::endl;
                    difficulty(&choice, &minRange, &maxRange, &Max_attempts);
                    secretNumber = rand() % (maxRange - minRange + 1) + minRange;
                    
                    std::cout << std::endl << "Enter your name: ";
                    std::cin >> player1Name;
                    randPlayer = player1Name;
                }

                //..................
                if (mode == 2) {
                    if (randPlayer == player1Name) guessPlayer = player2Name;
                    else guessPlayer = player1Name;
                }
                else {
                    guessPlayer = player1Name;
                }


                std::cout << "\n" << guessPlayer << ", Guess Between " << minRange << " to " << maxRange << std::endl;

                guess = 0;
                attempts = 0;
                std::string input;
                // Game Loop
                while(guess != secretNumber && attempts < Max_attempts)
                {   
                    std::cout << "\nRemaining attempts: " << (Max_attempts - attempts) << std::endl;
                    std::cout << "Enter your guess: ";
                    std::cin >> input;
                    if (input == "q") exit(0);
                    else if (input == "h") break;
                    else {
                        try {
                            guess = stoi(input);
                        }
                        catch (...) {
                            std::cout << "Invalid input! Please enter a number" << std::endl;
                            continue;
                        }
                    }

                    // ................
                    attempts++;

                    if (guess > secretNumber)
                        std::cout << "Too High " << guessPlayer << std::endl;

                    else if (guess < secretNumber)
                        std::cout << "Too Low " << guessPlayer << std::endl;

                    else
                    {
                        std::cout << "Correct! " << guessPlayer << " You guessed correct number" << std::endl;
                        wins++;
                        std::cout << "Attempts: " << attempts << std::endl;
                        std::cout << "Remaining attempts: " << (Max_attempts - attempts) << std::endl;

                        if (playerTurn == 1)
                            std::cout << std::endl << "What s shame " << player1Name << ". \nYou failed to hide the number.";
                        else
                            std::cout << std::endl << "What s shame " << player2Name << ". \nYou failed to hide the number.";
                    }
                }
                
                //...
                if (attempts == Max_attempts && guess != secretNumber)
                {
                    std::cout << "\nYou Lost " << randPlayer << " !" << std::endl;
                    std::cout << "Correct Number: " << secretNumber << std::endl;
                    losses++;

                    if (playerTurn == 1)
                            std::cout << std::endl << "Ha Ha 😂 " << player1Name << ". Wins.";
                    else
                        std::cout << std::endl << "Ha Ha 😂 " << player2Name << ". Wins.";
                }

                std::cout << std::endl << randPlayer << ", Do You Wanna Play Again? (y/n): ";
                std::cin >> play_again;

                std::cout << std::endl;

                totalGames++;
            } while (play_again == 'y' || play_again == 'Y');
        }

        // difficulty setting method.........
        void difficulty(int *choice, int *minRange, int *maxRange, int *Max_attempts)
        {
            std::cout << std::endl << "Choose Difficulty: ";
            std::cout << std::endl << "1. Easy\n2. Medium\n3. Hard" << std::endl;
            std::cout << "Choice here: ";
            std::cin >> *choice;

            if (*choice == 1) *minRange = 1, *maxRange = 10, *Max_attempts = 5;
            else if (*choice == 2) *minRange = 1, *maxRange = 100, *Max_attempts = 7;
            else if (*choice == 3) *minRange = 1, *maxRange = 1000, *Max_attempts = 10;
            else
            {
                std::cout << "Invalid choice input!\nChoice set to default" << std::endl;
                *minRange = 1, *maxRange = 100, *Max_attempts = 7;
            }
        }

        // for system clear
        void clear_screen() {
            #if defined(_WIN32) || defined(_WIN64)
                system("cls");
            #else
                system("clear");
            
            #endif
        }
};

int main()
{
   NumberGuessGame ngg;
   ngg.play();
    
   return 0;
}


