#ifndef GAME_H
#define GAME_H

#include "Enemy.h"
#include "Player.h"
#include "Item.h"
#include "DecorBackground.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <ctime>
#include <vector>
#include <string>
#include <fstream>

class Game
{
    private:
        // Load a sprite to display
        sf::Vector2f velocityMove;//velocity to move
        sf::Vector2f velocityMoveCloud;//velocity to move
        sf::Vector2f velocityMoveSun;//velocity to move
        sf::RenderWindow *window;
        std::vector<Enemy> enemyLv1;
        std::vector<Enemy> enemyLv2;
        std::vector<Enemy> enemyLv3;
        std::vector<Item> heal;
        std::stringstream ss;
        std::stringstream ssScore;
        std::stringstream ssScoreStr;
        sf::Font greatFont;//to take the font
        sf::Text scoreTxt;//score font
        sf::Text gameOverTxt;
        sf::RectangleShape playRect;
        sf::RectangleShape aboutRect;
        sf::RectangleShape exitRect;
        sf::RectangleShape backHome;
        sf::Text backTxt;
        sf::Text playerTxt;
        sf::Text enemyTxt;
        sf::Text playTxt;
        sf::Text aboutTxt;
        sf::Text exitTxt;
        sf::Text insideAboutTxt;
        sf::VideoMode sizeWindow;
        sf::Texture backgroundTexture;
        sf::Sprite background;
        sf::Mouse mouseDetect;
        Player player;
        DecorBackground decBack;

        //get variable
        short w;
        short h;
        short mlsec;
        short maxMlSec;
        short maxspawn;
        short startGame;
        int hightScoreInt;
        int score;
        int cooldown1;
        int cooldown2;
        int cooldown3;
        short theLevel;
        std::string hightScore;

        //to frame rate
        sf::Clock clock;
        float dt;
        float multiplier;

        void initVar();
        void initFontText();
        void gettingText();
        void settingShapeMenu();
        void theMenuText();
        void settingWindow();
        void collision();
        void about();
        void clearEnemy();
        void gameOver();
        void gameMenu();
        void backgroundAnimation();
        void collisionWithEnemy();
        void getHightScore();

    public:
        std::ofstream in;
        std::ifstream out;

        Game();
        bool gameLooping();
        void pollEvent();
        void spawnEnemy();
        void theScore();
        void update();
        void draw();
        virtual ~Game();

};

#endif // GAME_H
