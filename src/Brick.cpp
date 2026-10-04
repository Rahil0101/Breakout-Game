#include <SFML/Graphics.hpp>
#include "../include/Brick.hpp"




Brick::Brick(sf::Texture& texture , float BRICK_LENGTH, float BRICK_HEIGHT) : shape(texture) ,  BRICK_LENGTH(BRICK_LENGTH) , BRICK_HEIGHT(BRICK_HEIGHT) {

     sf::FloatRect brick_bounds = shape.getLocalBounds();

    shape.setScale({ BRICK_LENGTH / brick_bounds.size.x , BRICK_HEIGHT / brick_bounds.size.y});
    shape.setOrigin({0.f, 0.f}); 
}

sf::FloatRect Brick::get_global_bounds()
{
    return shape.getGlobalBounds();
}


void Brick::set_position (sf::Vector2f position)
{
    shape.setPosition(position);
}



