#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics.hpp>
#include <ctime>


class Enemy
{
    public:
        sf::Sprite enemyLv1;
        sf::Sprite enemyLv2;
        sf::Sprite enemyLv3;
        sf::Texture *textureEneLv1;
        sf::Texture *textureEneLv2;
        sf::Texture *textureEneLv3;
        Enemy(short leveling);
        void draw1(sf::RenderTarget &target);
        void draw2(sf::RenderTarget &target);
        void draw3(sf::RenderTarget &target);
        virtual ~Enemy();

    private:
        void initVar();
        void enemySetting(short &lvl);
};

#endif // ENEMY_H
