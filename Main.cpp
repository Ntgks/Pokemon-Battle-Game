#include "sgg/graphics.h"
#include "define.h"
#include"Game.h"
#include <iostream>
#include "Pokemon_Array.h"
#include "Pokemon.h"
#include <list>
#include "Damage.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void draw()
{
	Game* mygame = Game::getInstance();
	mygame->draw();
}

void update(float ms)
{
	Game* mygame = Game::getInstance();
	mygame->update();
}

int main(int argc, char** argv)
{
	srand(time(NULL));


	graphics::createWindow(1200, 800, "Pokemon v0.1");
	Game* game = Game::getInstance();
	graphics::setCanvasSize(CANVAS_WIDTH, CANVAS_HEIGHT);
	graphics::setCanvasScaleMode(graphics::CANVAS_SCALE_FIT);
	//graphics::playMusic(std::string(ASSET_PATH) + "1-Pokemon Theme (Season Theme).mp3", 1.5f, true, 4000);
	game->init_for_LoadingScreen();
	graphics::setDrawFunction(draw);
	graphics::setUpdateFunction(update);

	graphics::startMessageLoop();
	Game::releaseInstance();
	return 0;
}