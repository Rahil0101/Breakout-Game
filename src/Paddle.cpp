#include "../include/Paddle.hpp"




Paddle::Paddle (sf::Texture & paddle_texture , float LENGTH, float BREADTH , float PADDLE_SPEED) : paddle(paddle_texture) , LENGTH(LENGTH) , BREADTH(BREADTH) , PADDLE_SPEED(PADDLE_SPEED){

    sf::FloatRect paddle_bounds = paddle.getLocalBounds();

    paddle.setScale({ LENGTH / paddle_bounds.size.x , BREADTH / paddle_bounds.size.y});

    
    paddle.setOrigin({paddle_bounds.size.x / 2.f , paddle_bounds.size.y / 2.f});
}


void Paddle::update (float delta_time) {
    paddle.move({PADDLE_SPEED * delta_time ,0.f});
}

sf::FloatRect  Paddle::get_global_bounds ()
{
    return paddle.getGlobalBounds();
}


void Paddle::set_pos (sf::Vector2f position){
    paddle.setPosition(position);
}
