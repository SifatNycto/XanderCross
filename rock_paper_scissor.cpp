#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    char play_again;

    srand(time(NULL));
    do 
    {
        int rand_num = (rand() % 3) + 1;
        std::string computer;
        if (rand_num == 1) computer = "rock";
        else if (rand_num == 2) computer = "paper";
        else computer = "scissor";

        char user_choice;
        std::string user;
        std::cout << "Enter your choice: " << std::endl;
        std::cout << "1. Rock\n2. Paper\n3. Scissor" << std::endl;
        std::cout << "Enter (r/p/s): ";
        std::cin >> user_choice;

        if (user_choice == 'r') user = "rock";
        else if (user_choice == 'p') user = "paper";
        else if (user_choice == 's') user = "scissor";
        else {
            std::cout << "Invalid Input!" << std::endl;
            std::cout << "Please enter 'r' or 'p' or 's' here: " << std::endl;
        }

        std::cout << std::endl;
        std::cout << "Your choice: " << user << std::endl;
        std::cout << "Computer choice: " << computer << std::endl;
        std::cout << std::endl;

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

        std::cout << std::endl;
        std::cout << "Play Again? (y/n): ";
        std::cin >> play_again;
        std::cout << std::endl;

    } while (play_again == 'y' || play_again == 'Y');
    

    return 0;
}