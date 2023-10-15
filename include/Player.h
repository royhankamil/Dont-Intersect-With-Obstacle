#ifndef PLAYER_H
#define PLAYER_H

#include <SFML/Graphics.hpp>


class Player
{
    public:
        sf::Sprite player;
        sf::Texture playerTexture;
        sf::RectangleShape hpBox;
        sf::RectangleShape outlineHp;

        Player();
        sf::Vector2f toGetMove(sf::Vector2f &velocityMove);
        void drawPlayer(sf::RenderTarget &target);
        void getDamage(short powerDamage);
        void getHeal(short powerHeal);
        void beginning();
        short infoHp();
        short hp;
        virtual ~Player();

    private:
        void initVar();
        void playerShape();
        void hpBoxShape();

        sf::Clock clock;
        short maxHp;
        float dt;
        float multiplier;
};

#endif // PLAYER_H
