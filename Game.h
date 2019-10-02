#ifndef GAME_H
#define GAME_H


#include"Game_State.h"

class Game
{
    public:
        Game();
        virtual ~Game();

        //updates
        void Update();
        void UpdateSFMLEvents();
        void UpdateDt();
        //funct
        void EndApplication();
        //render
        void Render();
        //core
        void Run();

    protected:

    private:

    //init
    void InitWindow();
    void InitStates();
    void InitKeys();


    //variables
    sf::RenderWindow* window;
    sf::Event sfEvent;
    float dt;
    sf::Clock dtClock;
    std::stack<State*> states;
    std::map<std::string, int>* supportedKeys;//here
};

#endif // GAME_H
