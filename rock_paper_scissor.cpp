#include <iostream>
#include <cstdlib>
#include <cctype>
#include <ctime>

const std::string BRIGHT_RED     = "\033[91m";
const std::string BRIGHT_GREEN   = "\033[92m";
const std::string BRIGHT_YELLOW  = "\033[93m";
const std::string BRIGHT_BLUE    = "\033[94m";
const std::string BRIGHT_MAGENTA = "\033[95m";
const std::string BRIGHT_CYAN    = "\033[96m";
const std::string RESET = "\033[0m";
const std::string BOLD = "\033[1m";


class RockPaperScissor {
    private:
        char user_choice;
        std::string computer = "";
        int totalMatches = 0;
        int wins = 0;
        int losses = 0;
        int ties = 0;

    public:
        RockPaperScissor() {
            srand(time(NULL));
        }

        void play() {
            
            std::cout << BOLD << BRIGHT_BLUE    << "\n========================================" << RESET;
            std::cout << BOLD << BRIGHT_YELLOW  << "\n         ROCK PAPER SCISSOR" << RESET;
            std::cout << BOLD << BRIGHT_BLUE    << "\n========================================" << RESET << std::endl;
            
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
                
                totalMatches++;

                std::cout << std::endl;
                std::cout << "Play Again? (y/n): ";
                std::cin >> play_again;
                std::cout << std::endl;

            } while (play_again == 'y' || play_again == 'Y');

            scoreBoard();
        }

        // ............
        void decide_winner() {
            switch(user_choice)
            {
                case 'r':
                            if (computer == "rock")
                            {
                                std::cout << "Oops... It's a tie!";
                                ties++;
                            }
                            else if (computer == "paper")
                            {
                                std::cout << "Ha Ha Ha, Shame on you\nYou lose!";
                                losses++;
                            }
                            else
                            {
                                std::cout << "Congratulations.... You win!";
                                wins++;
                            }
                            break;
                case 'p':
                            if (computer == "rock")
                            {
                                std::cout << "Congratulations.... You win!";
                                wins++;
                            }
                            else if (computer == "paper")
                            {
                                std::cout << "Oops... It's a tie!";
                                ties++;
                            }
                            else
                            {
                                std::cout << "Ha Ha Ha, Shame on you\nYou lose!";
                                losses++;
                            }
                            break;
                case 's':
                            if (computer == "rock")
                            {
                                std::cout << "Ha Ha Ha, Shame on you\nYou lose!";
                                losses++;
                            }
                            else if (computer == "paper")
                            {
                                std::cout << "Congratulations.... You win!";
                                wins++;
                            }
                            else
                            {
                                std::cout << "Oops... It's a tie!";
                                ties++;
                            }
                            break;

            }
        }

        void scoreBoard()
        {
            std::cout << BOLD << BRIGHT_MAGENTA << "\n<<< SCOREBOARD >>>" << RESET;
            std::cout << BOLD << BRIGHT_CYAN    << "\n+----------------+" << RESET;
            std::cout                   << "\n| Matches   : " << totalMatches;
            std::cout << BOLD << BRIGHT_GREEN   << "\n| Wins      : " << wins << RESET;
            std::cout << BOLD << BRIGHT_RED     << "\n| Losses    : " << losses << RESET;
            std::cout << BOLD << BRIGHT_YELLOW  << "\n| Ties      : " << ties << RESET;
            std::cout << BOLD << BRIGHT_CYAN    << "\n+----------------+" << RESET;
        }
};

int main()
{
    RockPaperScissor rps;
    
    rps.play();
    
    return 0;
}



