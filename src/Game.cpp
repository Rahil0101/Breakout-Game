#include "../include/Game.hpp"
#include "LoadAssets.cpp"
#include "Ball.cpp"
#include "Paddle.cpp"




Game::Game() : window(sf::VideoMode({850, 600}), "Breakout") {
    LoadAssets assets;
    Ball ball(assets.ball_texture ,10.f , 300.f);
    Paddle paddle (assets.paddle_texture , 100.f , 20.f , 300.f);

};
