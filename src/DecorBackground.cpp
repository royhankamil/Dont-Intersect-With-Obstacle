#include "DecorBackground.h"

DecorBackground::DecorBackground()
{
    this->initVar();
    this->settingSprite();
}

void DecorBackground::initVar()
{
        this->cloudTexture1.loadFromFile("assets/Cloud 1.png");
        this->cloudTexture2.loadFromFile("assets/Cloud 2.png");
        this->cloudTexture3.loadFromFile("assets/Cloud 3.png");
        this->sunTexture.loadFromFile("assets/Sun.png");
}

void DecorBackground::settingSprite()
{
    this->cloud1.setTexture(this->cloudTexture1);
    this->cloud1.setPosition(sf::Vector2f(500, 100));
    this->cloud1.setScale(0.5, 0.5);

    this->cloud2.setTexture(this->cloudTexture2);
    this->cloud2.setPosition(sf::Vector2f(200, 100));
    this->cloud2.setScale(0.5, 0.5);


    this->cloud3.setTexture(this->cloudTexture3);
    this->cloud3.setPosition(sf::Vector2f(800, 100));
    this->cloud3.setScale(0.5, 0.5);

    this->sun.setTexture(this->sunTexture);
    this->sun.setPosition(sf::Vector2f(600, 100));
    this->sun.setScale(0.3, 0.3);
}

sf::Vector2f DecorBackground::cloudMove(sf::Vector2f &velocityMove)
{
    velocityMove.x = 0.f;
    velocityMove.y = 0.f;

    velocityMove.x = -0.25f;
    return velocityMove;
}

sf::Vector2f DecorBackground::sunMove(sf::Vector2f &velocityMove)
{
    velocityMove.x = 0.f;
    velocityMove.y = 0.f;

    velocityMove.x = -0.0125f;
    return velocityMove;
}

void DecorBackground::draw(sf::RenderTarget &target)
{
    target.draw(this->sun);
    target.draw(this->cloud1);
    target.draw(this->cloud2);
    target.draw(this->cloud3);
}


DecorBackground::~DecorBackground()
{
    //dtor
}
