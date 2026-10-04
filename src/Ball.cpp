#include "../include/Ball.hpp"


Ball::Ball(sf::Texture & texture , float RADIUS , float BALLSPEED) : ball(texture) , RADIUS(RADIUS) , BALLSPEED(BALLSPEED){

    velocity = {BALLSPEED,BALLSPEED};


    sf::FloatRect ball_bounds = ball.getLocalBounds();

    ball.setScale({ RADIUS * 2.f/ball_bounds.size.x , RADIUS * 2.f / ball_bounds.size.y});

    
    ball.setOrigin({ball_bounds.size.x / 2.f , ball_bounds.size.y / 2.f});
    
}

void Ball::update (float deltatime)
{
    ball.move(velocity * deltatime);
}

void Ball::set_pos(sf::Vector2f position){
    ball.setPosition(position);
}


sf::FloatRect Ball::get_global_bounds(){
    return ball.getGlobalBounds();
}








