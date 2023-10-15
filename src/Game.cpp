#include "Game.h"

Game::Game()
{
    this->settingWindow();
    this->initVar();
    this->initFontText();
    this->getHightScore();
}

void Game::initVar()
{
    ssScore << this->hightScore;
    ssScore >> this->hightScoreInt;
    this->w = 800;
    this->h = 600;
    this->startGame = 0;
    this->mlsec = 0;
    this->maxMlSec = 100;
    this->maxspawn = 15;
    this->theLevel = 1;
    this->score = 0;
    this->multiplier = 60.f;
    this->cooldown1 = 1000;
    this->cooldown2 = 5000;
    this->cooldown3 = 3000;
    this->backgroundTexture.loadFromFile("assets/Background.png");
    this->background.setTexture(this->backgroundTexture);
    this->background.setScale(3.125, 2.344);
}

void Game::initFontText()
{
    if(!greatFont.loadFromFile("PressStart2P-Regular.ttf"))
        std::cout << "do you downloading font?" << std::endl;

    this->scoreTxt.setFont(this->greatFont);
    this->scoreTxt.setFillColor(sf::Color::Red);
    this->scoreTxt.setCharacterSize(20);
    this->scoreTxt.setPosition(20, 20);


    this->playerTxt.setFont(this->greatFont);
    this->playerTxt.setFillColor(sf::Color::Black);
    this->playerTxt.setCharacterSize(10);
    this->playerTxt.setString("Player");


    this->enemyTxt.setFont(this->greatFont);
    this->enemyTxt.setFillColor(sf::Color::Black);
    this->enemyTxt.setCharacterSize(13);
    this->enemyTxt.setPosition(20, 120);
    this->enemyTxt.setString("Red, Blue, and Yellow is enemy \nGreen is healing");

    //gameOverTxt are not here to initialize but in the methods of gameOver
}

void Game::gettingText()
{
    //to get the text
    ss.str("");//to make clear score
    ss << score ;
    std::cout << "score : " << ss.str() << std::endl;
    scoreTxt.setString("Score : " + ss.str());

    this->playerTxt.setPosition(this->player.player.getPosition().x, this->player.player.getPosition().y - 20);

}

void Game::settingWindow()
{
    this->sizeWindow = sf::VideoMode(800 , 600);
    this->window = new sf::RenderWindow(this->sizeWindow, "Dont toch the obstacle",sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(60);
}

bool Game::gameLooping()
{
    return this->window->isOpen();
}

void Game::collision()
{
    //collision on window
        if(this->player.player.getPosition().x < 0)
            this->player.player.setPosition(sf::Vector2f(0, this->player.player.getPosition().y));
        else if(this->player.player.getPosition().x + this->player.player.getGlobalBounds().width > this->w)
            this->player.player.setPosition(sf::Vector2f(this->w - this->player.player.getGlobalBounds().width, this->player.player.getPosition().y));
        if(this->player.player.getPosition().y < 0)
            this->player.player.setPosition(sf::Vector2f(this->player.player.getPosition().x, 0));
        else if(this->player.player.getPosition().y + this->player.player.getGlobalBounds().height > this->h)
            this->player.player.setPosition(sf::Vector2f(this->player.player.getPosition().x, this->h - this->player.player.getGlobalBounds().height));

    if(this->decBack.cloud1.getPosition().x < 0 - this->decBack.cloud1.getGlobalBounds().width - 20)
    {
        this->decBack.cloud1.setPosition(sf::Vector2f(800, this->decBack.cloud1.getPosition().y));
    }
    if(this->decBack.cloud2.getPosition().x < 0 - this->decBack.cloud2.getGlobalBounds().width - 20)
    {
        this->decBack.cloud2.setPosition(sf::Vector2f(800, this->decBack.cloud2.getPosition().y));
    }
    if(this->decBack.cloud3.getPosition().x < 0 - this->decBack.cloud3.getGlobalBounds().width - 20)
    {
        this->decBack.cloud3.setPosition(sf::Vector2f(800, this->decBack.cloud3.getPosition().y));
    }
    if(this->decBack.sun.getPosition().x < 0 - this->decBack.sun.getGlobalBounds().width - 20)
    {
        this->decBack.sun.setPosition(sf::Vector2f(800, this->decBack.sun.getPosition().y));
    }
}

void Game::spawnEnemy()
{
    sf::IntRect currentFrame1;
    sf::IntRect currentFrame2;

    sf::Clock timer1;
    sf::Clock timer2;
    //to make spawn enemy lv 1
        if (this->enemyLv1.size() < this->maxspawn)//enemy spawn
        {
            if (this->score > 2 )
                this->enemyLv1.push_back(Enemy(this->theLevel));
        }

        for (int i=0; i < this->enemyLv1.size(); i++)
        {
            if (this->score >= 500 ){
                this->enemyLv1[i].enemyLv1.move( 0, 6 * this->dt * this->multiplier);
            }
//            else if (this->score > 500)
//                this->enemyLv1[i].enemyLv1.move(6 * this->dt * this->multiplier, 0);

            else if (this->score < 500)
                this->enemyLv1[i].enemyLv1.move(-6 * this->dt * this->multiplier, 0);

            //to make erase enemy
            if(
               this->enemyLv1[i].enemyLv1.getPosition().y - this->enemyLv1[i].enemyLv1.getGlobalBounds().height > 600
               )
            {
                this->enemyLv1.erase(this->enemyLv1.begin() + i);
            }
            else if(
               this->enemyLv1[i].enemyLv1.getPosition().x + this->enemyLv1[i].enemyLv1.getGlobalBounds().width < 0
               )
            {
                this->enemyLv1.erase(this->enemyLv1.begin() + i);
            }
        }

        //to make spawn enemy lv 2
        if (this->enemyLv2.size() < 1 + rand() % 2)//enemy spawn
        {
            if (this->score > 100)
            {
                if (this->score % (50 + rand() % 60) == 0)
                    this->enemyLv2.push_back(Enemy(this->theLevel));
            }
        }

        for (int i=0; i < this->enemyLv2.size(); i++)
        {
            this->enemyLv2[i].enemyLv2.move(-8 * this->dt * this->multiplier, 6 * this->dt * this->multiplier);
            if(timer1.getElapsedTime().asSeconds() >= 1.f)
            {
                currentFrame1.left += 32.f;
                    if (currentFrame1.left >= 128)
                        currentFrame1.left = 0.f;
                timer1.restart();
                this->enemyLv2[i].enemyLv2.setTextureRect(currentFrame1);
            }

            //to make erase enemy
            if(
               this->enemyLv2[i].enemyLv2.getPosition().y + this->enemyLv2[i].enemyLv2.getGlobalBounds().height > 600
               )
            {
                this->enemyLv2.erase(this->enemyLv2.begin() + i);
            }
        }

        //to make spawn enemy lv 3
        if (this->enemyLv3.size() < 1 + rand() % 3)//enemy spawn
        {
            if (this->score > 20)
            {
                if (this->score % (60 + rand() % 75) == 0 || this->score <100 && this->score % 30)
                    this->enemyLv3.push_back(Enemy(this->theLevel));
            }
        }

        for (int i=0; i < this->enemyLv3.size(); i++)
        {
            this->enemyLv3[i].enemyLv3.move(0, -8 * this->dt * this->multiplier);
            if(timer2.getElapsedTime().asSeconds() >= 1.f)
            {
                currentFrame2.left += 32.f;
                    if (currentFrame2.left >= 320)
                        currentFrame2.left = 0.f;
                timer2.restart();
                this->enemyLv3[i].enemyLv3.setTextureRect(currentFrame2);
            }

            //to make erase enemy
            if(
               this->enemyLv3[i].enemyLv3.getPosition().y + this->enemyLv3[i].enemyLv3.getGlobalBounds().height < 0
               )
            {
                this->enemyLv3.erase(this->enemyLv3.begin() + i);
            }
        }

        //to make spawn heal item
        if (this->heal.size() < 1 )//heal spawn
        {
            if (this->score > 15)
            {
                if (this->score % (50 + rand() % 65) == 0 || this->score <100 && this->score % 25)
                    this->heal.push_back(Item());
            }
        }

        for (int i=0; i < this->heal.size(); i++)
        {
            this->heal[i].healItem.move(-2 * this->dt * this->multiplier, 0);

            //to make erase enemy
            if(
               this->heal[i].healItem.getPosition().x + this->heal[i].healItem.getGlobalBounds().width < 0
               )
            {
                this->heal.erase(this->heal.begin() + i);
            }
        }
}

void Game::theScore()
{
    this->gettingText();
    this->mlsec++;
    std::cout<<this->cooldown1<<std::endl;
    std::cout<<this->cooldown2<<std::endl;
    std::cout<<this->cooldown3<<std::endl;
        if(this->mlsec == this->maxMlSec)
        {
            this->score += 1;
            this->mlsec = 0;
            if (this->maxMlSec > 10)
                this->maxMlSec -=5;
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::H))
        {
            this->score += 30;
        }

    else if(this->score >= 100)
        this->maxspawn = 19;
    if(this->score >= 200)
        this->maxspawn = 23;
    else if(this->score >= 500)
        this->maxspawn = 25;
    else if(this->score >= 700)
        this->maxspawn = 30;
    else if(this->score >= 1000)
        this->maxspawn = 45;
}

void Game::settingShapeMenu()
{
    this->playRect.setFillColor(sf::Color::Green);
    this->playRect.setSize(sf::Vector2f(200.f, 100.f));
    this->playRect.setOutlineThickness(5);
    this->playRect.setPosition(sf::Vector2f(this->w / 2 - this->playRect.getGlobalBounds().width / 2, 100));

    this->aboutRect.setFillColor(sf::Color::Green);
    this->aboutRect.setSize(sf::Vector2f(200.f, 100.f));
    this->aboutRect.setOutlineThickness(5);
    this->aboutRect.setPosition(sf::Vector2f(this->w / 2 - this->playRect.getGlobalBounds().width / 2, 250));

    this->exitRect.setFillColor(sf::Color::Green);
    this->exitRect.setSize(sf::Vector2f(200.f, 100.f));
    this->exitRect.setOutlineThickness(5);
    this->exitRect.setPosition(sf::Vector2f(this->w / 2 - this->playRect.getGlobalBounds().width / 2, 400));

}

void Game::theMenuText()
{
    this->playTxt.setFont(this->greatFont);
    this->playTxt.setFillColor(sf::Color::White);
    this->playTxt.setOutlineColor(sf::Color::Black);
    this->playTxt.setOutlineThickness(1);
    this->playTxt.setCharacterSize(10);
    this->playTxt.setPosition(this->playRect.getPosition().x + this->playRect.getGlobalBounds().width/2 - 30,
                               this->playRect.getPosition().y + this->playRect.getGlobalBounds().height/2-10);
    this->playTxt.setString("PLAY");

    this->aboutTxt.setFont(this->greatFont);
    this->aboutTxt.setFillColor(sf::Color::White);
    this->aboutTxt.setOutlineColor(sf::Color::Black);
    this->aboutTxt.setOutlineThickness(1);
    this->aboutTxt.setCharacterSize(10);
    this->aboutTxt.setPosition(this->aboutRect.getPosition().x + this->aboutRect.getGlobalBounds().width/2 - 30,
                               this->aboutRect.getPosition().y + this->aboutRect.getGlobalBounds().height/2-10);
    this->aboutTxt.setString("ABOUT");

    this->exitTxt.setFont(this->greatFont);
    this->exitTxt.setFillColor(sf::Color::White);
    this->exitTxt.setOutlineColor(sf::Color::Black);
    this->exitTxt.setOutlineThickness(1);
    this->exitTxt.setCharacterSize(10);
    this->exitTxt.setPosition(this->exitRect.getPosition().x + this->exitRect.getGlobalBounds().width/2 - 30,
                               this->exitRect.getPosition().y + this->exitRect.getGlobalBounds().height/2-10);
    this->exitTxt.setString("EXIT");

    if(//play
       this->mouseDetect.getPosition(*this->window).x > this->playRect.getPosition().x
       && this->mouseDetect.getPosition(*this->window).x < this->playRect.getPosition().x + this->playRect.getGlobalBounds().width
       && this->mouseDetect.getPosition(*this->window).y > this->playRect.getPosition().y
       && this->mouseDetect.getPosition(*this->window).y < this->playRect.getPosition().y + this->playRect.getGlobalBounds().height
       )
    {
        this->playRect.setOutlineColor(sf::Color::Black);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            this->startGame = 2;
        }
        std::cout << "collision\n" ;
    }
    if(//about
       this->mouseDetect.getPosition(*this->window).x > this->aboutRect.getPosition().x
       && this->mouseDetect.getPosition(*this->window).x < this->aboutRect.getPosition().x + this->aboutRect.getGlobalBounds().width
       && this->mouseDetect.getPosition(*this->window).y > this->aboutRect.getPosition().y
       && this->mouseDetect.getPosition(*this->window).y < this->aboutRect.getPosition().y + this->aboutRect.getGlobalBounds().height
       )
    {
        this->aboutRect.setOutlineColor(sf::Color::Black);
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            this->startGame = 1;
        }
        std::cout << "collision\n" ;
    }
    if(//exit
       this->mouseDetect.getPosition(*this->window).x > this->exitRect.getPosition().x
       && this->mouseDetect.getPosition(*this->window).x < this->exitRect.getPosition().x + this->exitRect.getGlobalBounds().width
       && this->mouseDetect.getPosition(*this->window).y > this->exitRect.getPosition().y
       && this->mouseDetect.getPosition(*this->window).y < this->exitRect.getPosition().y + this->exitRect.getGlobalBounds().height
       )
    {
        this->exitRect.setOutlineColor(sf::Color::Black);
        std::cout << "collision\n" ;
    }
}

void Game::gameMenu()
{
    this->playRect.setOutlineColor(sf::Color::Transparent);
    this->aboutRect.setOutlineColor(sf::Color::Transparent);
    this->exitRect.setOutlineColor(sf::Color::Transparent);
    this->settingShapeMenu();
    this->theMenuText();

}

void Game::collisionWithEnemy()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::LControl) && sf::Keyboard::isKeyPressed(sf::Keyboard::H))
        {
            this->score += 40;
            this->draw();
        }
    for (int i=0; i < this->enemyLv1.size(); i++)
    {
        if(this->player.player.getGlobalBounds().intersects(this->enemyLv1[i].enemyLv1.getGlobalBounds()))
        {
            this->player.getDamage(1);
            this->enemyLv1.erase(this->enemyLv1.begin() + i);
        }

    }

    for (int i=0; i < this->enemyLv2.size(); i++)
    {
        if(this->player.player.getGlobalBounds().intersects(this->enemyLv2[i].enemyLv2.getGlobalBounds()))
        {
            this->player.getDamage(4);
            this->enemyLv2.erase(this->enemyLv2.begin() + i);
        }

    }

    for (int i=0; i < this->enemyLv3.size(); i++)
    {
        if(this->player.player.getGlobalBounds().intersects(this->enemyLv3[i].enemyLv3.getGlobalBounds()))
        {
            this->player.getDamage(2);
            this->enemyLv3.erase(this->enemyLv3.begin() + i);
        }

    }

    for (int i=0; i < this->heal.size(); i++)
    {
        if(this->player.player.getGlobalBounds().intersects(this->heal[i].healItem.getGlobalBounds()))
        {
            this->player.getHeal(1 + rand() % 3);
            this->heal.erase(this->heal.begin() + i);
        }

    }
}

void Game::pollEvent()
{
    sf::Event ev;
    while (this->window->pollEvent(ev))
    {
        // Close window : exit
        if (ev.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            this->window->close();

    }
}

void Game::update()
{
    //to make smooth move
    this->velocityMove.x = 0.f;
    this->velocityMove.y = 0.f;
    this->dt = this->clock.restart().asSeconds();

    //make different type
    if (score >=500)
        this->theLevel = 2;
//    else if (score >= 500)
//        this->theLevel = 3;

    //make if game still run
    if (player.hp >0)
    {
        if(this->startGame == 0)
        {
            this->gameMenu();
        }

        if(this->startGame == 1)
            this->about();

        if (this->startGame == 2)
        {

            this->pollEvent();
            this->spawnEnemy();
            this->theScore();
            this->collisionWithEnemy();
        }
        this->backgroundAnimation();
        this->collision();
    }
    else//gameover
        {
            this->gameOver();
        }
}

void Game::about()
{
    this->backHome.setFillColor(sf::Color::Black);
    this->backHome.setSize(sf::Vector2f(150.f, 50.f));
    this->backHome.setPosition(sf::Vector2f(this->w / 2 - this->backHome.getGlobalBounds().width / 2, 500));

    this->backTxt.setFont(this->greatFont);
    this->backTxt.setFillColor(sf::Color::White);
    this->backTxt.setCharacterSize(15);
    this->backTxt.setPosition(this->backHome.getPosition().x +10,
                              this->backHome.getPosition().y + this->backTxt.getGlobalBounds().height / 2 +10);
    this->backTxt.setString("<- Back");

    this->insideAboutTxt.setFont(this->greatFont);
    this->insideAboutTxt.setFillColor(sf::Color::White);
    this->insideAboutTxt.setOutlineColor(sf::Color(0, 0, 0, 200));
    this->insideAboutTxt.setOutlineThickness(5);
    this->insideAboutTxt.setCharacterSize(15);
    this->insideAboutTxt.setPosition(100,300);
    this->insideAboutTxt.setString(
                             "Hello im so lazy to make how to play\n\nmaybe not now, hi im the developer my\n\nname is Achmad Royhan Kamil from X   \n\nRPL C maybe thats it"
                             );

    if(//back
       this->mouseDetect.getPosition(*this->window).x > this->backTxt.getPosition().x
       && this->mouseDetect.getPosition(*this->window).x < this->backTxt.getPosition().x + this->backTxt.getGlobalBounds().width
       && this->mouseDetect.getPosition(*this->window).y > this->backTxt.getPosition().y
       && this->mouseDetect.getPosition(*this->window).y < this->backTxt.getPosition().y + this->backTxt.getGlobalBounds().height
       )
    {
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            this->startGame = 0;
        }
    }
}

void Game::backgroundAnimation()
{
    this->player.toGetMove(this->velocityMove);
    this->player.player.move(this->velocityMove);

    this->decBack.cloudMove(this->velocityMoveCloud);
    this->decBack.cloud1.move(this->velocityMoveCloud);

    this->decBack.cloudMove(this->velocityMoveCloud);
    this->decBack.cloud2.move(this->velocityMoveCloud);

    this->decBack.cloudMove(this->velocityMoveCloud);
    this->decBack.cloud3.move(this->velocityMoveCloud);

    this->decBack.sunMove(this->velocityMoveSun);
    this->decBack.sun.move(this->velocityMoveSun);
}
void Game::getHightScore()
{
    Game::out.open("highest-score.txt");
    Game::out >> this->hightScore;
    std::cout << this->hightScore << std::endl;
    if (Game::out.is_open())
        std::cout << "data onok" <<std::endl;
}
void Game::gameOver()
{
    this->gameOverTxt.setFont(this->greatFont);
    this->gameOverTxt.setCharacterSize(60);
    this->gameOverTxt.setFillColor(sf::Color::Black);
    this->gameOverTxt.setPosition(this->w /2 - this->gameOverTxt.getGlobalBounds().width/2, 100);
    this->gameOverTxt.setString("GAME OVER");

    this->scoreTxt.setPosition(this->w /2 - this->scoreTxt.getGlobalBounds().width/2, 300);
    this->scoreTxt.setString("Your Score : " + ss.str());
    this->scoreTxt.Bold;
    this->scoreTxt.setCharacterSize(30);

    this->backTxt.setFont(this->greatFont);
    this->backTxt.setFillColor(sf::Color::Black);
    this->backTxt.setCharacterSize(20);
    this->backTxt.setPosition(sf::Vector2f(this->w/2 - this->backTxt.getGlobalBounds().width/2, 450));
    this->backTxt.setString("Press space to try again");

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        this->initFontText();
        this->clearEnemy();
        this->initVar();
        this->startGame = 2;
        player.beginning();
    }

    if (this->score > this->hightScoreInt)
    {
        ssScoreStr << this->score;
        ssScoreStr >> this->hightScore;
        this->in.open("highest-score.txt", std::ios::trunc |std::ios::out);
//        this->hightScore = ssScoreStr;
        this->in << this->hightScore;
        this->in.close();
    }
}

void Game::clearEnemy()
{
    enemyLv1.clear();
    enemyLv2.clear();
    enemyLv3.clear();
    heal.clear();
}

void Game::draw()
{
    // Clear screen
        this->window->clear();

        this->window->draw(this->background);
        // Draw the sprite
        this->decBack.draw(*this->window);
        if (player.hp > 0)
        {
            if (this->startGame == 0)
            {
                this->window->draw(playRect);
                this->window->draw(playTxt);
                this->window->draw(aboutRect);
                this->window->draw(aboutTxt);
                this->window->draw(exitRect);
                this->window->draw(exitTxt);
            }

            if(this->startGame == 1)
            {
                this->window->draw(this->insideAboutTxt);
                this->window->draw(this->backHome);
                this->window->draw(this->backTxt);
            }

            if (this->startGame == 2)
            {
                for (auto i : this->enemyLv1)
                    i.draw1(*this->window);

                for (auto i : this->enemyLv2)
                    i.draw2(*this->window);

                for (auto i : this->enemyLv3)
                    i.draw3(*this->window);


                for (auto i : this->heal)
                    i.itemDraw(*this->window);

                this->player.drawPlayer(*this->window);
                this->window->draw(this->playerTxt);
                if(this->score < 8)
                    this->window->draw(this->enemyTxt);
            }
        }
        else
        {

            this->window->draw(this->backTxt);
            this->window->draw(this->gameOverTxt);
        }
        this->window->draw(this->scoreTxt);

        this->window->display();
}

Game::~Game()
{
    delete this->window;
}
