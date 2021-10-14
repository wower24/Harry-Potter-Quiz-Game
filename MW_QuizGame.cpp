
#include "MW_QuizGame.h"

int main()
{
    int vID = 0;
    int mode;
    int level;
    std::string pName;

    std::cout << "Hello World!\n" << "Welcome to my Quiz Game!\n";
    //choosing a game mode
    std::cout << "At first, choose a game mode.\n" << "1 - challenge (single player)\n" << "2 - competition (two players)\n";
    std::cin >> mode;
    //creating Players
    if (mode == 1)
    {
        std::cout << "Great! Now let me know your name - type it in!\n";
        std::cin >> pName;
        Player player(pName);
        players.push_back(player);
    }
    else if (mode == 2)
    {
        for (int i = 0; i < mode; i++)
        {
            std::cout << "Player " << i + 1 << ", please, type your name in: ";
            std::cin >> pName;
            Player player(pName);
            players.push_back(player);
            std::cout << std::endl;
        }
    }
    //choosing difficulty level
    std::cout << "Choose a difficulty level for your game\n"
        << "1 - easy\n" << "2 - medium\n" << "3 - expert\n" << "4 - random\n";
    std::cin >> level;
   if (level == 1)
      q = new Easy;
    else if (level == 2)
       q = new Medium;
    else if (level == 3)
       q = new Expert;
    else if (level == 4)
       q = new Question;
    else
        {
            q = new Question;
            std::cout << "Wrong number, bye.\n";
            return 0;
        }

    q->read();
    //trying an exception
    /*try
    {
        noRepeats(mode * 10);
    }
    catch (double)
    {
        std::cout << "I'm sorry you can't stick to the rules.\nSee you next time!\n";
        return 0;
    }*/
    play(mode);
    for (int i = 0; i < mode; i++)
        players[i].printScore();

    delete con;
}

