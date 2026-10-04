#pragma once

#include<vector>

#include<SFML/Graphics.hpp>








class LevelConfig {
    Level level;
    std::vector<Brick> bricks;
    Ball ball;
    Paddle paddle;


    void setLevel();
};