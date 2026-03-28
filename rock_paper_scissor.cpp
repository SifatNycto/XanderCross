#include <iostream>
#include <cstdlib>
#include <cctype>
#include <ctime>

class RockPaperScissor {
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
    RockPaperScissor rps;
    
    rps.play();
    
    return 0;
}