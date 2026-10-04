#pragma once

#include<SFML/Graphics.hpp>

class Paddle {

    float LENGTH;
    float BREADTH;
    float PADDLE_SPEED;
    sf::Sprite paddle;

    public:
        Paddle(sf::Texture &texture_paddle, float LENGTH , float BREADTH, float PADDLE_SPEED);
        void update (float deltatime);
        void set_pos (sf::Vector2f position);
        sf::FloatRect get_global_bounds();
};