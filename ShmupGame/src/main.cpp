#include <SFML/Graphics.hpp>
#include <iostream>

void WatchInput(sf::CircleShape* spaceship, sf::Keyboard::Key pressedKey, const sf::FloatRect* windowBounds)
{
    const float SPEED = 5.f;

    sf::Vector2f currPos = spaceship->getPosition();
    sf::Vector2f newPos = currPos;

    //TODO This system doesn't support multiple inputs (diagonal move) - need to find a solution
    if(pressedKey == sf::Keyboard::Left || pressedKey == sf::Keyboard::A)
    {
        float newX = currPos.x - SPEED;
        if (newX < windowBounds->left)
        {
            //prevent exit screen
            newX = windowBounds->left;
        }
        newPos = sf::Vector2f(newX, currPos.y);
    }
    else if (pressedKey == sf::Keyboard::Right || pressedKey == sf::Keyboard::D)
    {
        float newX = currPos.x + SPEED;
        float screenLimit = windowBounds->width - (spaceship->getRadius() * 2);

        if (newX > screenLimit)
        {
            //prevent exit screen
            newX = screenLimit;
        }

        newPos = sf::Vector2f(newX, currPos.y);
    }

    if (pressedKey == sf::Keyboard::Up || pressedKey == sf::Keyboard::W)
    {
        float newY = currPos.y - SPEED;
        if (newY < windowBounds->top)
        {
            //prevent exit screen
            newY = windowBounds->top;
        }

        newPos = sf::Vector2f(currPos.x, newY);
    }
    else if (pressedKey == sf::Keyboard::Down || pressedKey == sf::Keyboard::S)
    {
        float newY = currPos.y + SPEED;
        float screenLimit = windowBounds->height - (spaceship->getRadius() * 2);

        if (newY > screenLimit)
        {
            //prevent exit screen
            newY = screenLimit;
        }

        newPos = sf::Vector2f(currPos.x, newY);
    }

    if (pressedKey == sf::Keyboard::Space)
    {
        //Shoot
    }

    spaceship->setPosition(newPos);
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Space Invaders 2.0");
    sf::FloatRect windowBounds(sf::Vector2f(0.f, 0.f), window.getDefaultView().getSize());

    const float SPACESHIP_SIZE = 40.f;
    sf::CircleShape triangle(SPACESHIP_SIZE, 3);
    triangle.setFillColor(sf::Color::Yellow);

   /* sf::Thread inputThread(&WatchInput, &window);
    inputThread.launch();*/
    //sf::Vector2f newPos(0, 0);

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::KeyPressed)
            {
                std::cout << "DEBUG: Key Pressed" << std::endl;
                WatchInput(&triangle, event.key.code, &windowBounds);
            }

            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            window.close();
        }

        sf::Vector2f curPos = triangle.getPosition();

        /*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            newPos = sf::Vector2f(curPos.x - SPEED, curPos.y );            
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            newPos = sf::Vector2f( curPos.x + SPEED, curPos.y );
        }*/

       //trriangle.setPosition(newPos);

        //if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        /*{
            triangle.move(SPEED, 0);
        }*/
        
        window.clear(sf::Color::Black);

        window.draw(triangle);

        window.display(); 
    }

    return 0;
}