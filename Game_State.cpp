#include "Game_State.h"

Game_State::Game_State(sf::RenderWindow* window, std::map<std::string,int>* supportedKeys):State(window, supportedKeys)
{
   this->InitKeybinds(); //ctor
}

Game_State::~Game_State()
{
    //dtor
}

void Game_State::Update(const float& dt){
    this->UpdateInput(dt);
    this->player.Update(dt);
}
void Game_State::Render(sf::RenderTarget* target){
    if(!target)
        target = this->window;
    this->player.Render(target);

}

void Game_State::UpdateInput(const float& dt){
    this->CheckForQuit();
//update input
      if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_LEFT"))))
        this->player.move(dt, -1.f, 0.f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_RIGHT"))))
        this->player.move(dt, 1.f, 0.f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_UP"))))
        this->player.move(dt, 0.f, -1.f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_DOWN"))))
        this->player.move(dt, 0.f, 1.f);
}

void Game_State::EndState(){
    std::cout << "Ending gs" << "\n";
}

void InitKeybinds(){
    this->keybinds["CLOSE"] = this->supportedKeys->at("Escape");
    this->keybinds["MOVE_LEFT"] = this->supportedKeys->at("A");
    this->keybinds["MOVE_RIGHT"]=this->supportedKeys->at("D");
    this->keybinds["MOVE_UP"]=this->supportedKeys->at("W");
    this->keybinds["MOVE_DOWN"]=this->supportedKeys->at("S");
}
