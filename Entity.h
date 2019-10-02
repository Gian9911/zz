#ifndef ENTITY_H
#define ENTITY_H

#include<vector>
#include<iostream>
#include<fstream>
#include<sstream>
#include<ctime>
#include<cstdlib>
#include<stack>
#include<map>
#include"Graphics.hpp"
#include"System.hpp"
#include"Network.hpp"
#include"Audio.hpp"
#include"Window.hpp"

class Entity
{
    public:
        Entity();
        virtual ~Entity();

        //func
        virtual void move(const float& dt, const float& x, const float& y);
        virtual void Update(const float& dt);
        virtual void Render(sf::RenderTarget* target);

    protected:
        sf::RectangleShape shape;
        float movementSpeed;

    private:
};

#endif // ENTITY_H
