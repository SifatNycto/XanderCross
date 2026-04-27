#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>
#include <ctime>

class GameSys {
    protected:

        virtual void play() = 0;

};

class NumberGuessGame : public GameSys {
    public:

        void play() override {

        }
};

class RockPaperScissor : public GameSys {
    public:

        void play() override {

        }
};

int main()
{
    NumberGuessGame ngg;

    RockPaperScissor rps;


    return 0;
}