#ifndef STATE_H
#define STATE_H

#include"../Entity.h"

class State{
    public:
        State(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys);
        virtual ~State();
        //funct
        virtual void Update(const float& dt) = 0;
        virtual void Render(sf::RenderTarget* target = NULL) = 0;
        virtual void CheckForQuit();
        const bool& GetQuit() const;
        virtual void UpdateInput(const float& dt) = 0;
        virtual void EndState() = 0;

    protected:
    //func
    virtual void InitKeybinds() = 0;

    //resources
    std::vector<sf::Texture*> textures;

    //var
    sf::RenderWindow* window;
    std::map<std::string, int>* supportedKeys;
    std::map<std::string, int> keybinds;
    bool quit;

    private:

};

#endif // STATE_H
