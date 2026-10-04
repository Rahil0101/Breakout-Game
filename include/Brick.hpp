#include<SFML/Graphics.hpp>


class Brick {



    float BRICK_LENGTH;
    float BRICK_HEIGHT;



    public : 



        sf::Sprite shape;
        bool isShow;


        sf::FloatRect get_global_bounds();

        void set_position (sf::Vector2f position);

        Brick (sf::Texture& texture, float BRICK_LENGTH , float BRICK_HEIGHT);

};