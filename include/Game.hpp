#pragma once

#include <SFML/Graphics.hpp>
#include <optional>
#include <string>
#include <vector>

class Game {
public:
    Game();
    enum class GameState {
        Playing,
        GameOver,
        LevelComplete
    };

    struct Bricks {
        sf::Sprite shape;
        bool isShow;

        Bricks(sf::Texture& texture) : shape(texture) {}
    };

    int brickCount;
    int score;
    int level;
        float deltaTime;


   
  
    float MAX_WIDTH;
    float MAX_HEIGHT;
    float paddleSpeed;
   

    float BRICK_LENGTH;
    float BRICK_HEIGHT;

    float startx;
    float starty;

    float spacingx;
    float spacingy;

    float overlap_x;
    float overlap_y;

    float sizex_panel;
    float sizey_panel;


    sf::Texture red_brick_texture;




    std::vector<Bricks> bricks;

    std::vector<std::string> level1;

    GameState gameState;
    sf::RenderWindow window;




    sf::Clock clock;

 


    sf::RectangleShape gameOverPanel;
    sf::FloatRect gameOverPanel_bounds;

    sf::Text gameOverText;
    sf::FloatRect bounds;
    sf::Text displayScore;
    sf::FloatRect score_global_bounds;
    sf::Text displayLevel;
    sf::FloatRect level_global_bounds;
    sf::Text playagainText;
    sf::FloatRect playagainText_bounds_global;
    sf::RectangleShape playagainBox;
    sf::RectangleShape gameOverOverlay;

    sf::Vector2f mousePosition;
    float normalized_hitspeed;

    sf::FloatRect ball_bounds_collision;
    sf::FloatRect brick_bounds;
   
};
