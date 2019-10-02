#include "Game.h"

//Initializer
void Game::InitWindow(){
    //creatin window by a wind.ini file
    std::ifstream ifs("Config/window.ini");
    std::string title = "None";
    sf::VideoMode window_bounds(800,600);
    unsigned framerate_limit = 120;
    bool vertical_sync_enabled = false;
    if(ifs.is_open()){
        std::getline(ifs,title);
        ifs >> window_bounds.width >> window_bounds.height;
        ifs >> framerate_limit;
        ifs >> vertical_sync_enabled;
    }
    ifs.close();
    this->window = new sf::RenderWindow(window_bounds, title);
    this->window->setFramerateLimit(framerate_limit);
    this->window->setVerticalSyncEnabled(vertical_sync_enabled);
}

void Game::InitStates(){
        this->states.push(new Game_State (this->window,&this->supportedKeys));
}

void Game::InitKeys(){
    this->supportedKeys["Escape"]=sf::Keyboard::Key::Escape;
    this->supportedKeys["A"]=sf::Keyboard::Key::A;
    this->supportedKeys["D"]=sf::Keyboard::Key::D;
    this->supportedKeys["W"]sf::Keyboard::Key::W;
    this->supportedKeys["S"]=sf::Keyboard::Key::S;
    for (auto i : this->supportedKeys){
        std::cout<<i.first<<i.second<<"\n";
    }
}

//const+dis
Game::Game(){
    this->InitWindow();
    this->InitKeys();
    this->InitStates();

}

Game::~Game(){
    delete this->window;
    while(this->states.empty()){
        delete this->states.top();//remove pointer data
        this->states.pop();//remove pointer
    }
}

//functions

void Game::UpdateDt(){
//update dt variable whit time to render one frame
    this->dt = this->dtClock.restart().asSeconds();

}

void Game::UpdateSFMLEvents(){
    while(this->window->pollEvent(this->sfEvent)){
        if(this->sfEvent.type == sf::Event::Closed)
            this->window->close();
    }
}

void Game::Update(){
    this->UpdateSFMLEvents();
    if(!this->states.empty()){
        this->states.top()->Update(this->dt);

        if(this->states.top()->GetQuit()){
            this->states.top()->EndState();//check
            delete this->states.top();
            this->states.pop();
        }
    }
    //App end
    else{
    this->EndApplication();
        this->window->close();
    }
}


void Game::Render(){
    this->window->clear();
    if(!this->states.empty())
        this->states.top()->Render();//this->window
    this->window->display();

}

void Game::Run(){
    while(window->isOpen()){
        this->UpdateDt();
        this->Update();
        this->Render();
    }

}


void Game::EndApplication(){
    std::cout<<"Ending app"<<"\n";
}
