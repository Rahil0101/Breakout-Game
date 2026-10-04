#include <SFML/Graphics.hpp>
#include <stdexcept>


class LoadAssets {

    public :


    sf::Font font;
    sf::Texture red_brick_texture;
    sf::Texture ball_texture;
    sf::Texture paddle_texture;

LoadAssets(){
    if (!font.openFromFile("assets/Robo-Italica.ttf"))
        {
            throw std::runtime_error("Failed to load font");
        }
    


    if (!red_brick_texture.loadFromFile("assets/img/brick.png")){

        throw std::runtime_error("Failed to load brick texture");
    }

    if (!ball_texture.loadFromFile("assets/img/ball.png")){
        throw std::runtime_error("Failed to ball texture");

    }
    if (!paddle_texture.loadFromFile("assets/img/skateboard.png")){
        throw std::runtime_error("Failed to load paddle texture");

    }
    red_brick_texture.setSmooth(true);
    ball_texture.setSmooth(true);

}


};