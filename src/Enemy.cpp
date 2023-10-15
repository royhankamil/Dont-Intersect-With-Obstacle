#include "Enemy.h"

Enemy::Enemy(short leveling)
{
    this->initVar();
    this->enemySetting(leveling);
}

void Enemy::initVar()
{
    this->textureEneLv1 = new sf::Texture;
    this->textureEneLv1->loadFromFile("assets/enemy 1.png");

    this->textureEneLv2 = new sf::Texture;
    this->textureEneLv2->loadFromFile("assets/Meteor.png");

    this->textureEneLv3 = new sf::Texture;
    this->textureEneLv3->loadFromFile("assets/Rock.png");
}

void Enemy::enemySetting(short &lvl)
{
    short randomScaleEneLv2 = (20+rand()%40) * 0.1;
    short randomScaleEneLv3 = (10+rand()%20) * 0.1;

    this->enemyLv1.setTexture(*this->textureEneLv1);
    this->enemyLv1.setScale(0.129, 0.129);

    this->enemyLv2.setTexture(*this->textureEneLv2);
    this->enemyLv2.setTextureRect(sf::IntRect(0, 0, 32, 32));
    this->enemyLv2.setScale(randomScaleEneLv2, randomScaleEneLv2);

    this->enemyLv3.setTexture(*this->textureEneLv3);
    this->enemyLv3.setTextureRect(sf::IntRect(0, 0, 32, 32));
    this->enemyLv3.setScale(randomScaleEneLv3, randomScaleEneLv3);

    if (lvl == 1)
    {
        this->enemyLv1.setPosition(sf::Vector2f(800 + rand()% 1000, rand()% 600));
        this->enemyLv2.setPosition(sf::Vector2f(20 + rand()% 880,-40));
        this->enemyLv3.setPosition(sf::Vector2f(20 + rand()% 880, 800));

    }
    if (lvl == 2)
    {
        this->enemyLv1.setPosition(sf::Vector2f(5 + rand()% 800, 0));
        this->enemyLv1.rotate(-90);
        this->enemyLv2.setPosition(sf::Vector2f(100 + rand()% 880, -40));
        this->enemyLv3.setPosition(sf::Vector2f(20 + rand()% 580, 600 + rand() % 700));
    }

    if (lvl == 3)
    {
        this->enemyLv1.setPosition(sf::Vector2f(0, 5 + rand()% 800));
        this->enemyLv1.rotate(270);
    }
}

void Enemy::draw1(sf::RenderTarget &target)
{
    target.draw(this->enemyLv1);
}

void Enemy::draw2(sf::RenderTarget &target)
{
    target.draw(this->enemyLv2);
}


void Enemy::draw3(sf::RenderTarget &target)
{
    target.draw(this->enemyLv3);
}

Enemy::~Enemy()
{
    //dtor
}
