#pragma once
#include <chrono>
#include <thread>
#include <stdlib.h>
#include <chrono>


inline void sleep(int ms)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}
#define CANVAS_WIDTH 28.0f
#define CANVAS_HEIGHT 16.0f
#define CANVAS_WIDTH_LOADING 20.f
#define CANVAS_HEIGHT_LOADING 12.0f

#define ASSET_PATH ".\\assets\\"

#define PLAYER_SIZE_2 6.0f
#define PLAYER_SIZE_1 6.0f
#define BLASTOISE_SIZE 11.0f
#define BLASTOISE_SIZE_2 7.0f
#define TAG_SIZE 2.0f
#define PLAY_BUTTON_SIZE 6.0f
#define CONTINUE_BUTTON_SIZE 1.0f
#define BENCH_MINI_FIGURE 3.0f


#define SETCOLOR(c, r, g, b){c[0] = r; c[1] = g; c[2] = b;}

#define RAND0TO1() ( rand()/(float) RAND_MAX)
#define FIGHT_BUTTON 3.0f
#define POKEBALL_LOGO 1.0f
#define POKEBALL_LOGO2 0.65
#define MOVES 7.0f
#define POKEMON_BUTTON 4.0f
#define CIRCLE 6.0f
#define MINI_SIZE 4.5f
#define GO_BACK_BUTTON 2.0f
inline float distance(float x1, float y1, float x2, float y2)
{
	float dx = x1 - x2;
	float dy = y1 - y2;
	return sqrtf(dx * dx + dy * dy);
}