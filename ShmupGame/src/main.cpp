#include "main.h"
#include "spaceship.h"
#include "weapon.h"
#include "globals.h"

void WatchInput(Entity* spaceship, sf::Keyboard::Key pressedKey, const sf::FloatRect* windowBounds)
{
    const float SPEED = 8.f;

    sf::CircleShape* spaceshipShape = spaceship->GetEntity();
    sf::Vector2f currPos = spaceshipShape->getPosition();
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
        float screenLimit = windowBounds->width - (spaceshipShape->getRadius() * 2);

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
        float screenLimit = windowBounds->height - (spaceshipShape->getRadius() * 2);

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
        GameGlobals::GetBullets()->push_back(spaceship->Shoot());
    }

    spaceshipShape->setPosition(newPos);
}

int main()
{
    GameGlobals gameGlobals;

    //--------------------------------------- INITIALIZE ---------------------------------------
    sf::RenderWindow window(sf::VideoMode(800, 600), "Space Invaders 2.0");
    sf::FloatRect windowBounds(sf::Vector2f(0.f, 0.f), window.getDefaultView().getSize());
    GameGlobals::SetGameWindowBounds(&windowBounds);
    window.setFramerateLimit(60);
    sf::Clock clock;
    //--------------------------------------- ENEMY INITIALIZE ---------------------------------------
    bool spawnedEnemy = false;
    float enemySpawnTimeControl = 0;
    float randomFloat = (float)(rand()) / (float)(rand());
    float randTime = std::fmod(randomFloat, *gameGlobals.GetMaxSpawnTime() - *gameGlobals.GetMinSpawnTime() ) + *gameGlobals.GetMinSpawnTime();
    //--------------------------------------- INITIALIZE END ------------------------------------

    //--------------------------------------- PLAYER -------------------------------------------
    const float SPACESHIP_SIZE = 40.f;
    const size_t POINT_COUNT = 3;
    Weapon startWeapon(WEAPON_TYPE::REGULAR);
    Entity spaceship(&SPACESHIP_SIZE, &POINT_COUNT, &startWeapon, &windowBounds);
    //--------------------------------------- PLAYER END ---------------------------------------
    
    //--------------------------------------- BULLET -------------------------------------------
    std::vector<Bullet*> bullets;
    gameGlobals.SetBullets(&bullets);
    //--------------------------------------- BULLET END ---------------------------------------

    while (window.isOpen())
    {
        GameGlobals::SetDeltaTime(clock.getElapsedTime());
        sf::Time elapsedTime = clock.restart();

        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::KeyPressed)
            {
                std::cout << "DEBUG: Key Pressed" << std::endl;
                WatchInput(&spaceship, event.key.code, &windowBounds);
            }

            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            window.close();
        }
        
        std::vector<Bullet*>* m_bullets = GameGlobals::GetBullets();
        size_t bulletsVecSize = m_bullets->size();

        for (size_t i = 0; i < bulletsVecSize; ++i)
        {
            if ((*m_bullets)[i]->Move())
            {
                if (bulletsVecSize > 1)
                {
                    std::swap((*m_bullets)[i], (*m_bullets)[bulletsVecSize - 1]); //send element to the end of the vector
                }

                --bulletsVecSize;
                m_bullets->resize(bulletsVecSize);
            }
        }

        std::vector<Enemy*>* m_enemies = GameGlobals::GetEnemies();
        size_t enemyVecSize = m_enemies->size();

        for (size_t i = 0; i < enemyVecSize; ++i)
        {
            if ((*m_enemies)[i]->Move())
            {
                if (enemyVecSize > 1)
                {
                    std::swap((*m_enemies)[i], (*m_enemies)[enemyVecSize - 1]); //send element to the end of the vector
                }

                --enemyVecSize;
                m_enemies->resize(enemyVecSize);
            }
        }
        
        window.clear(sf::Color::Black);

        window.draw(*spaceship.GetEntity());

        //Spawn Enemies

        enemySpawnTimeControl += elapsedTime.asSeconds();

        if (enemySpawnTimeControl >= randTime)
        {
            gameGlobals.SpawnEnemy();

            enemySpawnTimeControl = 0;
            randomFloat = (float)(rand()) / (float)(rand());
            randTime = std::fmod(randomFloat, *gameGlobals.GetMaxSpawnTime() - *gameGlobals.GetMinSpawnTime()) + *gameGlobals.GetMinSpawnTime();
        }
        
        for (size_t i = 0; i < bulletsVecSize; ++i)
        {
            window.draw(*((*m_bullets)[i]->GetBulletShape()));
        }

        for (size_t i = 0; i < enemyVecSize; ++i)
        {
            window.draw(*((*m_enemies)[i]->GetEnemyShape()));
        }

        window.display();
    }

    return 0;
}