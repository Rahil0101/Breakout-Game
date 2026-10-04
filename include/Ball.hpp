#pragma once
#include <SFML/Graphics.hpp>

class Ball{


    float RADIUS;
    float BALLSPEED;
    sf::Vector2f velocity;
    sf::Sprite ball;


    public: 
        Ball(sf::Texture & texture, float RADIUS , float BALLSPEED);   //to initialise the sprite with the texture
        void update(float deltatime);  //function for updating the ball position
        void set_pos(sf::Vector2f position);
        sf::FloatRect get_global_bounds();


};