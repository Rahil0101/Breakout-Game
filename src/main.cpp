#include <SFML/Graphics.hpp>
#include<iostream>
#include<vector>
#include <algorithm>




enum class GameState {
    Playing,
    GameOver,
    LevelComplete
};


struct Bricks {
    sf::Sprite shape;
    bool isShow = true;

    Bricks(sf::Texture & texture) : shape(texture)
    {}
};



int main (){


    int brickCount = 0;
    int score = 0;
    int level = 1;


    float RADIUS = 10.f;
    float LENGTH = 100.f;
    float BREADTH = 20.f;
    float MAX_WIDTH = 850.f;
    float MAX_HEIGHT = 600.f;
    float paddleSpeed = 300.f;
    float BALLSPEED = 300.f;

    float BRICK_LENGTH = 50.f;
    float BRICK_HEIGHT = 25.f;


    float startx = 50.f;
    float starty = 50.f;

    float spacingx = BRICK_LENGTH * 2;
    float spacingy = BRICK_LENGTH;

    std::vector <Bricks> bricks;

    std::vector<std::string> level1 =
{
    "11111111",
    "11111111",
    "11111111",
    "11111111",
    "00111100"
};
    GameState gameState = GameState::Playing;




    sf::Vector2f velocity {BALLSPEED , BALLSPEED};



    sf::RenderWindow window(
        sf::VideoMode({850 , 600}),
        "Breakout"
    );

    
    sf::Texture red_brick_texture;
    red_brick_texture.setSmooth(true);
    sf::Texture ball_texture;
    ball_texture.setSmooth(true);

    sf::Texture paddle_texture;

    if (!red_brick_texture.loadFromFile("assets/img/brick.png")){
        return 1;
    }

    if (!ball_texture.loadFromFile("assets/img/ball.png")){
        return 1;
    }
    if (!paddle_texture.loadFromFile("assets/img/skateboard.png")){
        return 1;
    }

    sf::Sprite ball(ball_texture);
    sf::Sprite paddle (paddle_texture);


    //sf::RectangleShape paddle;

    
    sf::FloatRect paddle_local = paddle.getLocalBounds();

// Scale the PNG to 100 × 20
paddle.setScale({
    LENGTH / paddle_local.size.x,
    BREADTH / paddle_local.size.y
});

// Origin must be in LOCAL coordinates
paddle.setOrigin({
    paddle_local.size.x / 2.f,
    paddle_local.size.y / 2.f
});

    sf::FloatRect paddle_bounds = paddle.getGlobalBounds();


    //paddle.setScale({LENGTH/paddle_bounds.size.x,BREADTH/paddle_bounds.size.y});
    
    //paddle.setOrigin ({LENGTH/2.f,BREADTH/2.f});


    paddle.setPosition({(MAX_WIDTH/2.f),MAX_HEIGHT - (paddle_bounds.size.y/2.f)});





   

    sf::FloatRect ball_global = ball.getGlobalBounds();

    //ball.setOrigin({RADIUS, RADIUS});


    ball.setPosition({paddle.getPosition().x , MAX_HEIGHT - (paddle_bounds.size.y/2.f) - (ball_global.size.x/2.f)});




    sf::Clock clock;
    for (int i = 0; i < level1.size() ; i++)
    {
        for (int j = 0; j < level1[i].size() ; j++)
        {

            if (level1[i][j] == '1')
            {
            Bricks brick (red_brick_texture);
          

            brick.shape.setPosition({startx + j * spacingx , starty + i * spacingy});



            bricks.push_back(brick);
            brickCount++;
            }
        }
    }

  

   
    //brick.setPosition({0.f + BRICK_LENGTH/2, 0.f + BRICK_HEIGHT/2});
    //brick.setPosition({MAX_HEIGHT / 2, MAX_WIDTH / 2});
        float sizex_panel = 500.f;
        float sizey_panel = 350.f;

            sf::RectangleShape gameOverPanel({sizex_panel,sizey_panel});
            gameOverPanel.setOrigin({gameOverPanel.getSize().x/2.f , gameOverPanel.getSize().y/2.f});
            gameOverPanel.setPosition({MAX_WIDTH/2.f , MAX_HEIGHT/2.f});
            gameOverPanel.setFillColor(sf::Color(30,30,30));
            gameOverPanel.setOutlineThickness(2.f);
            gameOverPanel.setOutlineColor(sf::Color::White);
            auto gameOverPanel_bounds = gameOverPanel.getGlobalBounds();

            sf::Text gameOverText (font, "GAME OVER", 50);
            sf::FloatRect bounds = gameOverText.getGlobalBounds();
            gameOverText.setOrigin({bounds.position.x + bounds.size.x/2.f , bounds.position.y + bounds.size.y/2.f});
            gameOverText.setPosition ({gameOverPanel.getPosition().x , gameOverPanel.getPosition().y - gameOverPanel.getSize().y/2.f + 50.f});

            bounds = gameOverText.getGlobalBounds();
            

            sf::Text displayScore(font,"Score : ",30);
            sf::FloatRect score_global_bounds = displayScore.getGlobalBounds();

            //displayScore.setOrigin({score_global_bounds.position.x + score_global_bounds.size.x/2.f , score_global_bounds.position.y + score_global_bounds.size.y/2.f });
            displayScore.setPosition({gameOverPanel_bounds.position.x + 40.f, bounds.position.y + bounds.size.y + 50.f});
            score_global_bounds = displayScore.getGlobalBounds();

            sf::Text displayLevel(font,"Level : ",30);
            sf::FloatRect level_global_bounds = displayLevel.getGlobalBounds();

            //displayLevel.setOrigin({level_global_bounds.position.x + level_global_bounds.size.x/2.f , level_global_bounds.position.y + level_global_bounds.size.y/2.f });
            displayLevel.setPosition({gameOverPanel_bounds.position.x + 40.f , score_global_bounds.position.y + score_global_bounds.size.y + 15.f});
            level_global_bounds = displayLevel.getGlobalBounds();

            sf::Text playagainText(font,"PLAY AGAIN", 30);
            sf::FloatRect playagainText_bounds_global = playagainText.getGlobalBounds();

            playagainText.setOrigin({playagainText_bounds_global.position.x + playagainText_bounds_global.size.x/2.f , playagainText_bounds_global.position.y + playagainText_bounds_global.size.y/2.f});
            playagainText.setPosition ({gameOverPanel_bounds.position.x + playagainText_bounds_global.size.x/2.f + 40.f , gameOverPanel_bounds.position.y + gameOverPanel_bounds.size.y - 50.f});
            playagainText_bounds_global = playagainText.getGlobalBounds();

            sf::RectangleShape playagainBox ({playagainText_bounds_global.size.x + 20.f , playagainText_bounds_global.size.y + 20.f });

            playagainBox.setOrigin ({playagainBox.getSize().x/2.f , playagainBox.getSize().y/2.f});
            playagainBox.setPosition({playagainText.getPosition().x , playagainText.getPosition().y });
            playagainBox.setFillColor(sf::Color(0,0,0,60));


  




    while (window.isOpen()){

    float deltaTime = clock.restart().asSeconds();


     while (std::optional event = window.pollEvent()){


            if (event->is <sf::Event::Closed>())
            {
                window.close();
            }

    if (auto* mouseButton = event->getIf<sf::Event::MouseButtonPressed>())
    {
        if (mouseButton->button == sf::Mouse::Button::Left)
        {
            sf::Vector2f mousePosition =
                window.mapPixelToCoords(mouseButton->position);

            if (playagainBox.getGlobalBounds().contains(mousePosition) && gameState == GameState::GameOver)
            {
                gameState = GameState::Playing;

                score = 0;
                brickCount = 0;

                bricks.clear();

                for (int i = 0; i < level1.size() ; i++)
                {
                    for (int j = 0; j < level1[i].size() ; j++)
                    {

                        if (level1[i][j] == '1')
                        {
                        Bricks brick (red_brick_texture);
                        brick.shape.setOrigin({0.f, 0.f});

                        brick.shape.setPosition({startx + j * spacingx , starty + i * spacingy});



                        bricks.push_back(brick);
                        brickCount++;
                        }
                    }
                }
                paddle.setPosition({(MAX_WIDTH/2.f), MAX_HEIGHT - (paddle_bounds.size.y/2.f)});

                std::cout<<paddle.getPosition().x <<std::endl<< paddle_bounds.size.y/2.f<<std::endl;

                ball.setPosition({paddle.getPosition().x , MAX_HEIGHT - (paddle_bounds.size.y) - (ball_global.size.x/2.f)});

                velocity  = {BALLSPEED , BALLSPEED};

                deltaTime = clock.restart().asSeconds();


                std::cout<<ball.getPosition().x <<std::endl<< ball.getPosition().y<<std::endl;




            }
        }
    }

        } 
     if (gameState == GameState::Playing)

    {   

        sf::Vector2f position = paddle.getPosition();


        sf::Vector2f prev_ball_position = ball.getPosition();


    
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
        {
            paddle.move({paddleSpeed * deltaTime, 0.f});
          
        }
        if (position.x < 0 + (paddle_bounds.size.x/2.f))
            {
                paddle.setPosition({0 + (paddle_bounds.size.x/2.f),position.y});
            }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
        {
            paddle.move({-(paddleSpeed * deltaTime), 0.f});
    
        }
        if (position.x > MAX_WIDTH - (paddle_bounds.size.x/2))
            {
                paddle.setPosition({MAX_WIDTH - (paddle_bounds.size.x/2),position.y});
            }

        ball.move(velocity * deltaTime);

        if (ball.getPosition().x - RADIUS <= 0.f )
        {
            ball.setPosition({0.f + RADIUS , ball.getPosition().y});
            velocity.x = -velocity.x;
        }
        if (ball.getPosition().x + RADIUS >=  MAX_WIDTH)
        {
            ball.setPosition({MAX_WIDTH - RADIUS , ball.getPosition().y});
            velocity.x = -velocity.x;
        }
        if (ball.getPosition().y - RADIUS <= 0.f )
        {
            ball.setPosition({ball.getPosition().x , 0.f + RADIUS});
            velocity.y = -velocity.y;
        }
        if (ball.getPosition().y + RADIUS >=  MAX_HEIGHT)
        {
            ball.setPosition({ball.getPosition().x , MAX_HEIGHT - RADIUS});
            velocity.y = -velocity.y;
        }

        for (auto &it : bricks){
            if (!it.isShow)
            {
                continue;
            }

        if (ball.getGlobalBounds().findIntersection(it.shape.getGlobalBounds()))
            {   
                sf::FloatRect ball_bounds = ball.getGlobalBounds();
                sf::FloatRect brick_bounds = it.shape.getGlobalBounds();
                float overlap_x = std::min(ball_bounds.position.x + ball_bounds.size.x , brick_bounds.position.x + brick_bounds.size.x) - std::max( ball_bounds.position.x , brick_bounds.position.x);
                float overlap_y = std::min(ball_bounds.position.y + ball_bounds.size.y , brick_bounds.position.y + brick_bounds.size.y) - std::max( ball_bounds.position.y , brick_bounds.position.y);

                if (overlap_x <= overlap_y) velocity.x = -velocity.x;

                else if (overlap_x > overlap_y) velocity.y = -velocity.y;

            /*if (prev_ball_position.x > it.shape.getPosition().x + (it.shape.getSize().x/2.f) + ball.getRadius()) {
                ball.setPosition({it.shape.getPosition().x + it.shape.getSize().x/2.f + ball.getRadius() , ball.getPosition().y});
                velocity.x = -velocity.x;
                }
            else  if (prev_ball_position.x < it.shape.getPosition().x - (it.shape.getSize().x/2.f + ball.getRadius()) ) {
                ball.setPosition({it.shape.getPosition().x - (it.shape.getSize().x/2.f + ball.getRadius()) , ball.getPosition().y});
                velocity.x = -velocity.x;
                }
                else if (prev_ball_position.y > it.shape.getPosition().y + (it.shape.getSize().y/2.f) + ball.getRadius()) {
                ball.setPosition({ball.getPosition().x , it.shape.getPosition().y + (it.shape.getSize().y/2.f) + ball.getRadius()});
                velocity.y = -velocity.y;
                }
            else if (prev_ball_position.y < it.shape.getPosition().y - (it.shape.getSize().y/2.f + ball.getRadius()) ) {
                ball.setPosition({ball.getPosition().x , it.shape.getPosition().y - (it.shape.getSize().y/2.f + ball.getRadius())});
                velocity.y = -velocity.y;
                }*/

       
                it.isShow = false;
                brickCount--;
                score++;
       

        }

    }


        if (ball.getGlobalBounds().findIntersection(paddle.getGlobalBounds())){
            //std::cout<<"Collision";
            float normalized_hitspeed = ((ball.getPosition().x - paddle.getPosition().x)/(paddle_bounds.size.x/2));
            ball.setPosition({ball.getPosition().x , MAX_HEIGHT - (paddle_bounds.size.y + (ball_global.size.x/2.f))});
            velocity.y = -velocity.y;
            velocity.x = BALLSPEED * normalized_hitspeed;
            //std::cout<<velocity.x<<std::endl;
        }

   



      
        

    if (ball.getPosition().y >= MAX_HEIGHT - (ball_global.size.x/2.f))
        {
            gameState = GameState::GameOver;
        }
        if (brickCount == 0)
        {
            gameState = GameState::LevelComplete;
        }

         window.clear();


        for(auto &it: bricks){
            if (it.isShow)  window.draw(it.shape);
        }
            window.draw(paddle);
            window.draw(ball);
     }
        else if (gameState == GameState::GameOver)
        {

            sf::RectangleShape gameOverOverlay({MAX_WIDTH , MAX_HEIGHT});
            gameOverOverlay.setFillColor(sf::Color(0,0,0,120));
            displayScore.setString("Score : " + std::to_string(score));
            displayLevel.setString("Level : " + std::to_string(level));







        for(auto &it: bricks){
            if (it.isShow)  window.draw(it.shape);
        }
            window.draw(paddle);
            window.draw(ball);
            window.draw(gameOverOverlay);
            window.draw(gameOverPanel);

            window.draw(gameOverText);
            window.draw(displayScore);
            window.draw(displayLevel);
            window.draw(playagainBox);
            window.draw(playagainText);
        }
        else if (gameState == GameState::LevelComplete)
        {
            window.clear();
        }
     
        window.display();
        //std::cout<<deltaTime<<std::endl;
        

    }
    return 0;
}