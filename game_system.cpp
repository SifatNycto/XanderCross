#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>
#include <ctime>

// For Colors >>>
// Normal Colors...
const std::string RED     = "\033[31m";
const std::string GREEN   = "\033[32m";
const std::string YELLOW  = "\033[33m";
const std::string BLUE    = "\033[34m";
const std::string MAGENTA = "\033[35m";
const std::string CYAN    = "\033[36m";

// Bright Colors...
const std::string BRIGHT_RED     = "\033[91m";
const std::string BRIGHT_GREEN   = "\033[92m";
const std::string BRIGHT_YELLOW  = "\033[93m";
const std::string BRIGHT_BLUE    = "\033[94m";
const std::string BRIGHT_MAGENTA = "\033[95m";
const std::string BRIGHT_CYAN    = "\033[96m";
const std::string BRIGHT_WHITE    = "\033[97m";

// For Reset >>>
const std::string RESET = "\033[0m";

// For Styles >>>
const std::string BOLD = "\033[1m";

// Class starts.......................
class GameSys {
    public:

        virtual void play() = 0;

};

class NumberGuessGame : public GameSys {
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
        void play() override {
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
                std::cout << "\n\n<<< Scoreboard >>>";
                std::cout << "\n+----------------+";
                std::cout << "\n| >> Games: " << totalGames;
                std::cout << "\n| >> Wins: " << wins;
                std::cout << "\n| >> Losses: " << losses;
                std::cout << "\n+----------------+";
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


class RockPaperScissor : public GameSys {
    private:
        char user_choice;
        std::string computer = "";
    public:
        RockPaperScissor() {
            srand(time(NULL));
        }

        void play() {
            char play_again;
            do 
            {
                // generating 
                int rand_num = (rand() % 3) + 1;

                if (rand_num == 1) computer = "rock";
                else if (rand_num == 2) computer = "paper";
                else computer = "scissor";

                std::string user;
                std::cout << std::endl << "Choose among them -> Rock || Paper || Scissor";
                std::cout << std::endl << "    'r' is for Rock";
                std::cout << std::endl << "    'p' is for Paper";
                std::cout << std::endl << "    's' is for Scissor";
                std::cout << std::endl << "    Enter your choice: ";
                std::cin >> user_choice;

                user_choice = tolower(user_choice);
                if (user_choice == 'r') user = "rock";
                else if (user_choice == 'p') user = "paper";
                else if (user_choice == 's') user = "scissor";
                else {
                    std::cout << "Invalid Input!" << std::endl;
                    std::cout << "Please enter 'r' or 'p' or 's' " << std::endl;
                    continue;
                }

                std::cout << std::endl;
                std::cout << "Your choice: " << user << std::endl;
                std::cout << "Computer choice: " << computer << std::endl;
                std::cout << std::endl;

                decide_winner();

                std::cout << std::endl;
                std::cout << "Play Again? (y/n): ";
                std::cin >> play_again;
                std::cout << std::endl;

            } while (play_again == 'y' || play_again == 'Y');
        }

        // ............
        void decide_winner() {
            switch(user_choice)
            {
                case 'r':
                            if (computer == "rock")
                            {
                                std::cout << "Oops... It's a tie!";
                            }
                            else if (computer == "paper")
                            {
                                std::cout << "Ha Ha Ha, Shame on you\nYou lose!";
                            }
                            else
                            {
                                std::cout << "Congratulations.... You win!";
                            }
                            break;
                case 'p':
                            if (computer == "rock")
                            {
                                std::cout << "Congratulations.... You win!";
                            }
                            else if (computer == "paper")
                            {
                                std::cout << "Oops... It's a tie!";
                            }
                            else
                            {
                                std::cout << "Ha Ha Ha, Shame on you\nYou lose!";
                            }
                            break;
                case 's':
                            if (computer == "rock")
                            {
                                std::cout << "Ha Ha Ha, Shame on you\nYou lose!";
                            }
                            else if (computer == "paper")
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
};


int main()
{
    
std::cout << BOLD << BRIGHT_MAGENTA
          << "\n                       >>> WELCOME TO <<<" << RESET;

std::cout << BOLD << BRIGHT_CYAN;

    std::cout << R"(

      ____    _    __  __  _____    _   _   _   _   ____   
     / ___|  / \  |  \/  || ____|  | | | | | | | | | __ )  
    | |  _  / _ \ | |\/| ||  _|    | |_| | | | | | |  _ \
    | |_| |/ ___ \| |  | || |___   |  _  | | |_| | | |_) | 
     \____/_/   \_\_|  |_||_____|  |_| |_|  \___/  |____/  

    )";

std::cout << RESET;

std::cout << BOLD << BRIGHT_CYAN
          << "\n================================================"
          << RESET;

std::cout << BOLD << BRIGHT_YELLOW
          << "\n [1] Number Guess Game"
          << RESET;

std::cout << BOLD << BRIGHT_BLUE
          << "\n [2] Rock Paper Scissor"
          << RESET;

std::cout << BOLD << BRIGHT_RED
          << "\n [3] Exit"
          << RESET;

std::cout << BOLD << BRIGHT_CYAN
          << "\n================================================"
          << RESET;

std::cout << BOLD << BRIGHT_WHITE
          << "\nEnter your choice here (1/2/3): "
          << RESET;



    std::cout << std::endl;

    int choice;
    std::cout << "\nEnter your choice here (1/2/3): ";
    std::cin >> choice;

    NumberGuessGame ngg;
    RockPaperScissor rps;

    if(choice == 1) ngg.play();
    else if(choice == 2) rps.play();
    else if(choice == 3) exit(0);
    else
    {
        std::cout << "\nInvalid choice!";
        exit(0);
    }

    return 0;
}