#include "State.h"

State::State(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys){
    //ctor
    this->window = window;
    this->supportedKeys = supportedKeys;
    this->quit = false;
}

State::~State(){
    //dtor
}

const bool& State::GetQuit() const {
    return this->quit;
}

void State::CheckForQuit(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("CLOSE")))){
        this->quit = true;
    }
}
