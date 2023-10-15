#include "Game.h"

int main()
{
    //get variable
    srand(time(0));
     Game game;


	// Start the game loop
    while (game.gameLooping())
    {
        game.pollEvent();
        game.update();
        game.draw();
    }



    return 0;
}
