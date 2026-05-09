#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>

const std::string BRIGHT_RED     = "\033[91m";
const std::string BRIGHT_GREEN   = "\033[92m";
const std::string BRIGHT_YELLOW  = "\033[93m";
const std::string BRIGHT_MAGENTA = "\033[95m";
const std::string BRIGHT_CYAN    = "\033[96m";
const std::string RESET = "\033[0m";
const std::string BOLD = "\033[1m";


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

        std::string setterName;
        std::string guesserName;

    public:
        NumberGuessGame() {
            srand(time(NULL));
        }
        
        void header_ngg() {
            std::cout << BOLD << BRIGHT_CYAN    << "\n+--------------------------------------+" << RESET;
            std::cout << BOLD << BRIGHT_GREEN   << "\n| >>>     NUMBER GUESSING GAME     <<< |" << RESET;
            std::cout << BOLD << BRIGHT_CYAN    << "\n+--------------------------------------+" << RESET;
            std::cout << std::endl;
        }

       
        int modeSelection() {
            int Mode;
            std::cout << "Modes: " << std::endl;
            std::cout << "1. Play with computer" << std::endl;
            std::cout << "2. Play with friend" << std::endl;
            std::cout << "3. Exit" << std::endl;
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
                    setterName = "Computer";

                    std::cout << std::endl << "Enter player name: ";
                    std::cin >> player1Name;
                    guesserName = player1Name;

                    //randPlayer = player1Name;

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

                    if (playerTurn == 1) {
                        setterName = player1Name;
                        guesserName = player2Name;
                        std::cout << "\nNow " << setterName << " will set the Secret Number.";   
                    }
                        
                    else {
                        setterName = player2Name;
                        guesserName = player1Name;
                        std::cout << "\nNow " << setterName << " will set the Secret Number.";
                    } 
                        

                    while (true)
                    {
                        std::cout << std::endl << setterName << ", Enter secret number between " << minRange << " and " << maxRange << ": ";
                        std::cin >> secretNumber;

                        if (secretNumber >= minRange && secretNumber <= maxRange) break;
                        else std::cout << std::endl << "Invalid Secret Number Setting !";
                    }

                    // calling clear screen..............
                    clear_screen();
                }
                
                else if (mode == 3) exit(0);

                else {
                    std::cout << "Invalid mode choice!\nMode set to default" << std::endl;
                    difficulty(&choice, &minRange, &maxRange, &Max_attempts);
                    secretNumber = rand() % (maxRange - minRange + 1) + minRange;
                    
                    std::cout << std::endl << "Enter your name: ";
                    std::cin >> player1Name;
                    guesserName = player1Name;
                    setterName = "Computer";
                }

              

                std::cout << "\n" << guesserName << ", Guess Between " << minRange << " to " << maxRange << std::endl;

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
                            if (!(guess >= minRange && guess <= maxRange)) {
                                std::cout << "\nPlease enter a number between " << minRange << " and " << maxRange << std::endl;
                                continue;
                            }
                                
                        }
                        catch (...) {
                            std::cout << "Invalid input! Please enter a number" << std::endl;
                            continue;
                        }
                    }

                    // ................
                    attempts++;

                    if (guess > secretNumber)
                        std::cout << guesserName << ", Too High" << std::endl;

                    else if (guess < secretNumber)
                        std::cout << guesserName << ", Too Low" << std::endl;

                    else
                    {
                        std::cout << "Correct! " << guesserName << ", You guessed correctly." << std::endl;
                        wins++;
                        std::cout << "Attempts: " << attempts << std::endl;
                        std::cout << "Remaining attempts: " << (Max_attempts - attempts) << std::endl;

                        if (mode == 1)
                            std::cout << "\nYou beat the computer!";
                        else 
                            std::cout << "\nWhat a shame, " << setterName << ". You failed to hide the number";
                    }
                }
                
                //...
                if (attempts == Max_attempts && guess != secretNumber)
                {
                    std::cout << "\n" << guesserName << ", You lost!" << std::endl;
                    std::cout << "Correct number was: " << secretNumber << std::endl;
                    losses++;

                    if (mode == 1)
                        std::cout << "\nComputer Wins!";
                    else
                        std::cout << "\n" << setterName << " Wins!";
                }

                std::cout << std::endl << guesserName << ", Do You Wanna Play Again? (y/n): ";
                std::cin >> play_again;

                std::cout << std::endl;

                totalGames++;

                // Scoreboard >>>
                std::cout << BOLD << BRIGHT_MAGENTA << "\n<<< SCOREBOARD >>>" << RESET;
                std::cout << BOLD << BRIGHT_CYAN    << "\n+------------------+" << RESET;
                std::cout << BOLD << BRIGHT_YELLOW  << "\n| Total Games : " << totalGames << RESET;
                std::cout << BOLD << BRIGHT_GREEN   << "\n| Wins        : " << wins << RESET;
                std::cout << BOLD << BRIGHT_RED     << "\n| Losses      : " << losses << RESET;
                std::cout << BOLD << BRIGHT_CYAN    << "\n+------------------+" << RESET;

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


