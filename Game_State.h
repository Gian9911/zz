#ifndef GAME_STATE_H
#define GAME_STATE_H


#include"State.h"

class Game_State: public State{
    public:
        Game_State(sf::RenderWindow* window,std::map<std::string,int>* supportedKeys);
        virtual ~Game_State();

        //func
        void Update(const float& dt);
        void Render(sf::RenderTarget* target);
        void UpdateInput(const float& dt);
        void EndState();

    protected:

    private:
     //func
    void InitKeybinds();
    //var
    Entity player;

};

#endif // GAME_STATE_H
