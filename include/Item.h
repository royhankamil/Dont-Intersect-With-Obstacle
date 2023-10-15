#ifndef ITEM_H
#define ITEM_H

#include <SFML/Graphics.hpp>

class Item
{
    public:
        sf::Sprite healItem;
        sf::Texture *healTexture;

        Item();
        void itemDraw(sf::RenderTarget& target);
        virtual ~Item();

    private:
        void shapeSetting();
        void initItem();
};
#endif
