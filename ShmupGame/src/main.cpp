#include "main.h"
#include "spaceship.h"

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
    //--------------------------------------- INITIALIZE ---------------------------------------
    sf::RenderWindow window(sf::VideoMode(800, 600), "Space Invaders 2.0");
    sf::FloatRect windowBounds(sf::Vector2f(0.f, 0.f), window.getDefaultView().getSize());
    //--------------------------------------- INITIALIZE END ---------------------------------------


    //--------------------------------------- PLAYER ---------------------------------------
    const float SPACESHIP_SIZE = 40.f;
    const size_t POINT_COUNT = 3;
    Spaceship spaceship(&SPACESHIP_SIZE, &POINT_COUNT, &windowBounds);
    //--------------------------------------- PLAYER END ---------------------------------------


    //--------------------------------------- BULLET ---------------------------------------
   
    //--------------------------------------- BULLET END ---------------------------------------

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::KeyPressed)
            {
                std::cout << "DEBUG: Key Pressed" << std::endl;
                WatchInput(spaceship.GetSpaceship(), event.key.code, &windowBounds);
            }

            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            window.close();
        }
        
        window.clear(sf::Color::Black);

        window.draw(*spaceship.GetSpaceship());
        //window.draw(bullet);

        window.display(); 
    }

    return 0;
}