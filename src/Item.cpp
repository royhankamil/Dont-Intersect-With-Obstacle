#include "Item.h"

Item::Item()
{
    this->initItem();
    this->shapeSetting();
}

void Item::initItem()
{
    this->healTexture = new sf::Texture;
    this->healTexture->loadFromFile("assets/Healer.png");
}

void Item::shapeSetting()
{
    this->healItem.setPosition(sf::Vector2f(800 + rand()% 100, 0 + rand()% 600));
    this->healItem.setTexture(*this->healTexture);
    this->healItem.setScale(0.129, 0.129);
}

void Item::itemDraw(sf::RenderTarget& target)
{
    target.draw(this->healItem);
}

Item::~Item()
{
    //dtor
}


