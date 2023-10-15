#ifndef DECORBACKGROUND_H
#define DECORBACKGROUND_H


#include <SFML/Graphics.hpp>

class DecorBackground
{
    public:
        sf::Sprite cloud1;
        sf::Sprite cloud2;
        sf::Sprite cloud3;
        sf::Sprite sun;

        DecorBackground();
        sf::Vector2f cloudMove(sf::Vector2f &velocityMove);
        sf::Vector2f sunMove(sf::Vector2f &velocityMove);
        void draw(sf::RenderTarget &target);
        virtual ~DecorBackground();

    private:
        sf::Texture cloudTexture1;
        sf::Texture cloudTexture2;
        sf::Texture cloudTexture3;
        sf::Texture sunTexture;

        void initVar();
        void settingSprite();
};

#endif // DECORBACKGROUND_H
