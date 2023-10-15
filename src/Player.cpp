#include "Player.h"

Player::Player()
{
    this->initVar();
    this->playerShape();
    this->hpBoxShape();
}

void Player::initVar()
{
    this->multiplier = 80.f;
    this->maxHp = 20;
    this->hp = this->maxHp;
}

void Player::playerShape()
{
    //player shape
    this->playerTexture.loadFromFile("assets/Player.png");
    this->player.setTexture(this->playerTexture);
    this->player.setScale(0.2,0.2);
    this->player.setPosition(sf::Vector2f(160, 800/2 - player.getGlobalBounds().height/2));
}


void Player::hpBoxShape()
{
    //health shape
    this->hpBox.setSize(sf::Vector2f(this->hp * 10, 30));
    this->hpBox.setPosition(20, 60);
    this->hpBox.setFillColor(sf::Color::Red);

    //outline hp box
    this->outlineHp.setSize(sf::Vector2f(this->maxHp * 10, 30));
    this->outlineHp.setPosition(20, 60);
    this->outlineHp.setFillColor(sf::Color(0, 0, 0, 0));
    this->outlineHp.setOutlineThickness(3);
    this->outlineHp.setOutlineColor(sf::Color(0, 0, 0));
}

sf::Vector2f Player::toGetMove(sf::Vector2f &velocityMove)
{
     velocityMove.x = 0.f;
     velocityMove.y = 0.f;
     this->dt = this->clock.restart().asSeconds();
     //move with the key
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
//                playerRad -= 5 * dt* multiplier;
                velocityMove.y = -5 * this->dt* this->multiplier;
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
                velocityMove.x = -5 * this->dt* this->multiplier;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
//                 playerRad += 5 * dt* multiplier;
                velocityMove.y = 5 * this->dt* this->multiplier;
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
                velocityMove.x = 5 * this->dt* this->multiplier;
        }


//        if(playerRad > 10 && playerRad < 80)
//            player.setRadius(playerRad);
        return velocityMove;
}

void Player::getDamage(short powerDamage)
{
    this->hp -= powerDamage;
    this->hpBox.setSize(sf::Vector2f(this->hp * 10, 30));
}

void Player::getHeal(short powerHeal)
{
    this->hp += powerHeal;
    if (this->hp > this->maxHp)
        this->hp = this->maxHp;
    this->hpBox.setSize(sf::Vector2f(this->hp * 10, 30));
}

short Player::infoHp()
{
    return this->hp;
}

void Player::beginning()
{
    this->hp = this->maxHp;
    this->hpBox.setSize(sf::Vector2f(this->hp * 10, 30));
}

void Player::drawPlayer(sf::RenderTarget &target)
{
        target.draw(this->player);
        target.draw(this->hpBox);
        target.draw(this->outlineHp);
}

Player::~Player()
{
    //dtor
}
