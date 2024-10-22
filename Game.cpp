#include "Game.h"
#include <iostream>

void Game::draw()
{
	if (g_state == STATE_INIT)
	{
		for (auto pic : background_3)
		{
			pic->draw();
		}
		return;
	}
	if (g_state == STATE_PREGAME)
	{
		for (auto pic : background)
		{
			pic->draw();
		}
		for (auto button : Start_button)
		{
			button->draw();
		}
	}
	else if (g_state == STATE_GAME_FOR_PLAYER_ONE)
	{
		for (auto pic : background_2)
		{
			pic->draw();
		}
		for (auto p : Players)
		{
			p->draw(true, bench);
		}
		for (auto p2 : Players_2)
		{
			p2->draw(false, bench_2);
		}
		for (auto button : fight_button)
		{
			button->draw();
		}
		graphics::Brush br;
		br.outline_opacity = 0.0f;
		SETCOLOR(br.fill_color, 0.0f, 0.0f, 0.0f);
		graphics::setFont("FreeSans.ttf");
		graphics::drawText(CANVAS_WIDTH / 3.2, CANVAS_HEIGHT * 1.77f / 2.0f, 1.0f, "Player  1  plays....", br);
	}
	else if (g_state == STATE_MOVE_SELECTION)
	{
		for (auto pic : msb)
		{
			pic->draw();
		}
		bench->ReturnMove1()->draw(0);
		bench->ReturnMove2()->draw(1);
		bench->ReturnMove3()->draw(2);
		bench->ReturnMove4()->draw(3);
		for (auto button : pb)
		{
			button->draw();
		}
	}
	else if (g_state == STATE_GAME_FOR_PLAYER_TWO)
	{
		for (auto pic : background_2)
		{
			pic->draw();
		}
		for (auto p : Players)
		{
			p->draw(false, bench);
		}
		for (auto p : Players_2)
		{
			p->draw(true, bench_2);
		}
		for (auto button : fight_button)
		{
			button->draw();
		}
		graphics::Brush br;
		br.outline_opacity = 0.0f;
		SETCOLOR(br.fill_color, 0.0f, 0.0f, 0.0f);
		graphics::setFont("FreeSans.ttf");
		graphics::drawText(CANVAS_WIDTH / 3.2, CANVAS_HEIGHT * 1.77f / 2.0f, 1.0f, "Player  2  plays....", br);
	}
	else if (g_state == STATE_SELECT_POKEMON)
	{
		for (auto pic : bfsp)
		{
			pic->draw();
		}
		for (auto button : gb_list)
		{
			button->draw();
		}
		int i = 0;
		for (auto pokemon : Pokemons_Player1)
		{
			if (bench != pokemon && i == 0)
			{
				pokemon->drawminifigure(bench);
				i = i + 1;
			}
			else if (bench == pokemon)
			{
				pokemon->drawminifigure(bench);
			}
			else if (bench != pokemon && i == 1)
			{
				pokemon->drawminifigure(bench);
				i = i + 1;
			}
		}
		graphics::Brush br;
		br.outline_opacity = 0.0f;
		SETCOLOR(br.fill_color, 1.0f, 1.0f, 1.0f);
		graphics::setFont("FreeSans.ttf");
		graphics::drawText(CANVAS_WIDTH / 7.4f, CANVAS_HEIGHT * 0.2f / 2.0f, 1.0f, "Click at the Pokemon you want to swap with " + bench->getName() + "!", br);
	}
	else if (g_state == STATE_MOVE_SELECTION_2)
	{
		for (auto pic : msb)
		{
			pic->draw();
		}
		bench_2->ReturnMove1()->draw(0);
		bench_2->ReturnMove2()->draw(1);
		bench_2->ReturnMove3()->draw(2);
		bench_2->ReturnMove4()->draw(3);
		for (auto button : pb)
		{
			button->draw();
		}
	}
	else if (g_state == STATE_SELECT_POKEMON_2)
	{
		for (auto pic : bfsp)
		{
			pic->draw();
		}
		for (auto button : gb_list)
		{
			button->draw();
		}
		int i = 0;
		for (auto pokemon : Pokemons_Player2)
		{
			if (bench_2 != pokemon && i == 0)
			{
				pokemon->drawminifigure(bench_2);
				i = i + 1;
			}
			else if (bench_2 == pokemon)
			{
				pokemon->drawminifigure(bench_2);
			}
			else if (bench_2 != pokemon && i == i)
			{
				pokemon->drawminifigure(bench_2);
				i = i + 1;
			}
		}
		graphics::Brush br;
		br.outline_opacity = 0.0f;
		SETCOLOR(br.fill_color, 1.0f, 1.0f, 1.0f);
		graphics::setFont("FreeSans.ttf");
		graphics::drawText(CANVAS_WIDTH / 7.4f, CANVAS_HEIGHT * 0.2f / 2.0f, 1.0f, "Click at the Pokemon you want to swap with " + bench_2->getName() + "!", br);
	}
	else if (g_state == STATE_FIGHT_FOR_PLAYER_ONE)
	{
		for (auto pic : background_2)
		{
			pic->draw();
		}
		for (auto p : Players)
		{
			if (player1_used_move)
			{
				p->Change_To_FightOne();
			}
			p->draw(true, bench);
		}
		for (auto p2 : Players_2)
		{
			p2->draw(false, bench_2);
		}
		for (auto button : cb_list)
		{
			button->draw();
		}

		if (player1_switched_pokemon)
		{
			graphics::Brush br;
			br.outline_opacity = 0.0f;
			SETCOLOR(br.fill_color, 0.0f, 0.0f, 0.0f);
			graphics::setFont("FreeSans.ttf");
			graphics::drawText(CANVAS_WIDTH / 13.5, CANVAS_HEIGHT * 1.77f / 2.0f, 1.0f, "Player  1  switched his pokemon with " + bench->getName(), br);
		}
		else if (player1_used_move)
		{
			graphics::Brush br;
			br.outline_opacity = 0.0f;
			SETCOLOR(br.fill_color, 0.0f, 0.0f, 0.0f);
			graphics::setFont("FreeSans.ttf");
			graphics::drawText(CANVAS_WIDTH / 4.8, CANVAS_HEIGHT * 1.77f / 2.0f, 1.0f, bench->getName() + " used " + move_for_player_1->getName(), br);
		}
	}
	else if (g_state == STATE_FIGHT_FOR_PLAYER_TWO)
	{
		for (auto pic : background_2)
		{
			pic->draw();
		}
		for (auto p : Players)
		{
			p->draw(false, bench);
		}
		for (auto p2 : Players_2)
		{
			if (player2_used_move)
			{
				p2->Change_To_FightTwo();
			}
			p2->draw(true, bench_2);
		}
		for (auto button : cb_list)
		{
			button->draw();
		}
		if (player2_switched_pokemon)
		{
			graphics::Brush br;
			br.outline_opacity = 0.0f;
			SETCOLOR(br.fill_color, 0.0f, 0.0f, 0.0f);
			graphics::setFont("FreeSans.ttf");
			graphics::drawText(CANVAS_WIDTH / 13.5, CANVAS_HEIGHT * 1.77f / 2.0f, 1.0f, "Player  2  switched his pokemon with " + bench_2->getName(), br);
		}
		else if (player2_used_move)
		{
			graphics::Brush br;
			br.outline_opacity = 0.0f;
			SETCOLOR(br.fill_color, 0.0f, 0.0f, 0.0f);
			graphics::setFont("FreeSans.ttf");
			graphics::drawText(CANVAS_WIDTH / 4.8, CANVAS_HEIGHT * 1.77f / 2.0f, 1.0f, bench_2->getName() + " used " + move_for_player_2->getName(), br);
		}
	}
	else if (g_state == STATE_FIGHT_FOR_PLAYER_ONE_PARTB)
	{
		for (auto pic : background_2)
		{
			pic->draw();
		}
		for (auto p : Players)
		{
			p->Change_To_Game();
			p->draw(true, bench);
		}
		for (auto p2 : Players_2)
		{
			p2->draw(false, bench_2);
		}
		for (auto button : cb_list)
		{
			button->draw();
		}
		Damage* d = new Damage();
		graphics::Brush br;
		br.outline_opacity = 0.0f;
		SETCOLOR(br.fill_color, 0.0f, 0.0f, 0.0f);
		graphics::setFont("FreeSans.ttf");
		graphics::drawText(CANVAS_WIDTH / 3.5, CANVAS_HEIGHT * 1.77f / 2.0f, 1.0f, d->dmg(bench, bench_2, move_for_player_1), br);
	}
	else if (g_state == STATE_FIGHT_FOR_PLAYER_TWO_PARTB)
	{
		for (auto pic : background_2)
		{
			pic->draw();
		}
		for (auto p : Players)
		{
			p->draw(false, bench);
		}
		for (auto p2 : Players_2)
		{
			p2->Change_To_Game();
			p2->draw(true, bench_2);
		}
		for (auto button : cb_list)
		{
			button->draw();
		}
		Damage* d = new Damage();
		graphics::Brush br;
		br.outline_opacity = 0.0f;
		SETCOLOR(br.fill_color, 0.0f, 0.0f, 0.0f);
		graphics::setFont("FreeSans.ttf");
		graphics::drawText(CANVAS_WIDTH / 3.5, CANVAS_HEIGHT * 1.77f / 2.0f, 1.0f, d->dmg(bench_2, bench, move_for_player_2), br);
	}
	else if (g_state == STATE_DEADPOKEMON_PLAYERTWO)
	{
		for (auto pic : background_2)
		{
			pic->draw();
		}
		for (auto p : Players)
		{
			p->draw(true, bench);
		}
		for (auto p2 : Players_2)
		{
			p2->draw(false, bench_2);
		}
		for (auto button : cb_list)
		{
			button->draw();
		}
		graphics::Brush br;
		br.outline_opacity = 0.0f;
		SETCOLOR(br.fill_color, 0.0f, 0.0f, 0.0f);
		graphics::setFont("FreeSans.ttf");
		graphics::drawText(CANVAS_WIDTH / 3.5, CANVAS_HEIGHT * 1.77f / 2.0f, 1.0f, bench_2->getName() + " fainted!", br);
	}
	else if (g_state == STATE_SELECT_DEADPOKEMON_TWO)
	{
		for (auto pic : bfsp)
		{
			pic->draw();
		}
		int i = 0;
		for (auto pokemon : Pokemons_Player2)
		{
			if (bench_2 != pokemon && i == 0)
			{
				pokemon->drawminifigure(bench_2);
				i = i + 1;
			}
			else if (bench_2 == pokemon)
			{
				pokemon->drawminifigure(bench_2);
			}
			else if (bench_2 != pokemon && i == i)
			{
				pokemon->drawminifigure(bench_2);
				i = i + 1;
			}
		}
		graphics::Brush br;
		br.outline_opacity = 0.0f;
		SETCOLOR(br.fill_color, 1.0f, 1.0f, 1.0f);
		graphics::setFont("FreeSans.ttf");
		graphics::drawText(CANVAS_WIDTH / 7.4f, CANVAS_HEIGHT * 0.2f / 2.0f, 1.0f, bench_2->getName() + " is dead! Select an other pokemon!", br);
	}
	else if (g_state == STATE_DEADPOKEMON_PLAYERONE)
	{
		for (auto pic : background_2)
		{
			pic->draw();
		}
		for (auto p : Players)
		{
			p->draw(true, bench);
		}
		for (auto p2 : Players_2)
		{
			p2->draw(false, bench_2);
		}
		for (auto button : cb_list)
		{
			button->draw();
		}
		graphics::Brush br;
		br.outline_opacity = 0.0f;
		SETCOLOR(br.fill_color, 0.0f, 0.0f, 0.0f);
		graphics::setFont("FreeSans.ttf");
		graphics::drawText(CANVAS_WIDTH / 3.5, CANVAS_HEIGHT * 1.77f / 2.0f, 1.0f, bench->getName() + " fainted!", br);
	}
	else if (g_state == STATE_SELECT_DEADPOKEMON_ONE)
	{
		for (auto pic : bfsp)
		{
			pic->draw();
		}
		int i = 0;
		for (auto pokemon : Pokemons_Player1)
		{
			if (bench != pokemon && i == 0)
			{
				pokemon->drawminifigure(bench);
				i = i + 1;
			}
			else if (bench_2 == pokemon)
			{
				pokemon->drawminifigure(bench);
			}
			else if (bench_2 != pokemon && i == i)
			{
				pokemon->drawminifigure(bench);
				i = i + 1;
			}
		}
		graphics::Brush br;
		br.outline_opacity = 0.0f;
		SETCOLOR(br.fill_color, 1.0f, 1.0f, 1.0f);
		graphics::setFont("FreeSans.ttf");
		graphics::drawText(CANVAS_WIDTH / 7.4f, CANVAS_HEIGHT * 0.2f / 2.0f, 1.0f, bench->getName() + " is dead! Select an other pokemon!", br);
	}
	else if (g_state == STATE_PLAYERONE_WINNER)
	{
		for (auto background : vb_list)
		{
			background->draw();
		}
		graphics::Brush br;
		br.outline_opacity = 0.0f;
		SETCOLOR(br.fill_color, 1.0f, 1.0f, 1.0f);
		graphics::setFont("FreeSans.ttf");
		graphics::drawText(CANVAS_WIDTH / 4.4f, CANVAS_HEIGHT * 0.2f / 2.0f, 1.5f, "CONGRATULATIONS!!", br);
		graphics::setFont("FreeSans.ttf");
		graphics::drawText(CANVAS_WIDTH / 3.5, CANVAS_HEIGHT * 0.5f / 2.0f, 1.5f, "PLAYER1 WON!", br);
		int i = 0;
		for (auto pokemon : Pokemons_Player1)
		{
			if (i == 0)
			{
				graphics::Brush br;
				br.outline_opacity = 0.0f;
				br.texture = ASSET_PATH + std::string(pokemon->draw_front());
				graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT * 1.66f / 2.0f, MINI_SIZE, MINI_SIZE, br);
			}
			else if (i == 1)
			{
				graphics::Brush br;
				br.outline_opacity = 0.0f;
				br.texture = ASSET_PATH + std::string(pokemon->draw_front());
				graphics::drawRect(CANVAS_WIDTH * 0.42f / 2.0f, CANVAS_HEIGHT / 2, MINI_SIZE, MINI_SIZE, br);
			}
			else if (i == 2)
			{
				graphics::Brush br;
				br.outline_opacity = 0.0f;
				br.texture = ASSET_PATH + std::string(pokemon->draw_front());
				graphics::drawRect(CANVAS_WIDTH * 1.62f / 2.0f, CANVAS_HEIGHT / 2, MINI_SIZE, MINI_SIZE, br);
			}
			i = i + 1;
		}

	}
	else if (g_state == STATE_PLAYERTWO_WINNER)
	{
		for (auto background : vb_list)
		{
			background->draw();
		}
		graphics::Brush br;
		br.outline_opacity = 0.0f;
		SETCOLOR(br.fill_color, 1.0f, 1.0f, 1.0f);
		graphics::setFont("FreeSans.ttf");
		graphics::drawText(CANVAS_WIDTH / 4.4f, CANVAS_HEIGHT * 0.2f / 2.0f, 1.5f, "CONGRATULATIONS!!", br);
		graphics::setFont("FreeSans.ttf");
		graphics::drawText(CANVAS_WIDTH / 3.5, CANVAS_HEIGHT * 0.5f / 2.0f, 1.5f, "PLAYER2 WON!", br);
		int i = 0;
		for (auto pokemon : Pokemons_Player2)
		{
			if (i == 0)
			{
				graphics::Brush br;
				br.outline_opacity = 0.0f;
				br.texture = ASSET_PATH + std::string(pokemon->draw_front());
				graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT * 1.66f / 2.0f, MINI_SIZE, MINI_SIZE, br);
			}
			else if (i == 1)
			{
				graphics::Brush br;
				br.outline_opacity = 0.0f;
				br.texture = ASSET_PATH + std::string(pokemon->draw_front());
				graphics::drawRect(CANVAS_WIDTH * 0.42f / 2.0f, CANVAS_HEIGHT / 2, MINI_SIZE, MINI_SIZE, br);
			}
			else if (i == 2)
			{
				graphics::Brush br;
				br.outline_opacity = 0.0f;
				br.texture = ASSET_PATH + std::string(pokemon->draw_front());
				graphics::drawRect(CANVAS_WIDTH * 1.62f / 2.0f, CANVAS_HEIGHT / 2, MINI_SIZE, MINI_SIZE, br);
			}
			i = i + 1;
		}
	}
}
void Game::update()
{
	if (g_state == STATE_INIT)
	{
		init_for_Player();
	}
	graphics::MouseState ms;
	graphics::getMouseState(ms);
	float mx = graphics::windowToCanvasX(ms.cur_pos_x);
	float my = graphics::windowToCanvasY(ms.cur_pos_y);
	if (g_state == STATE_START) {
		g_state = STATE_PREGAME;
		draw();
	}
	for (auto button : Start_button)
	{
		if (button->contains(mx, my))
		{
			button->setHighlighted(true);
		}
		else
		{
			button->setHighlighted(false);
		}
		if (button->ReturnHighlighted() && ms.button_left_pressed)
		{
			delete button;
			for (auto pic : background)
			{
				delete pic;
				g_state = STATE_GAME_FOR_PLAYER_ONE;
			}
			background.clear();
		}
	}
	if (g_state == STATE_GAME_FOR_PLAYER_ONE)
	{
		for (auto but : fight_button)
		{
			if (but->contains(mx, my))
			{
				but->SetHighlighted(true);
			}
			else
			{
				but->SetHighlighted(false);
			}
			if (but->ReturnHighlighted() && ms.button_left_pressed)
			{
				g_state = STATE_MOVE_SELECTION;
			}
		}
	}
	if (g_state == STATE_MOVE_SELECTION)
	{
		if (bench->ReturnMove1()->contains(mx, my))
		{
			bench->ReturnMove1()->SetHighlighted(true);
		}
		else
		{
			bench->ReturnMove1()->SetHighlighted(false);
		}
		if (bench->ReturnMove1()->ReturnHighlighted() && ms.button_left_pressed)
		{
			player1_switched_pokemon = false;
			move_for_player_1 = bench->ReturnMove1();
			player1_used_move = true;
			g_state = STATE_GAME_FOR_PLAYER_TWO;
			draw();
		}
		if (bench->ReturnMove2()->contains(mx, my))
		{
			bench->ReturnMove2()->SetHighlighted(true);
		}
		else
		{
			bench->ReturnMove2()->SetHighlighted(false);
		}
		if (bench->ReturnMove2()->ReturnHighlighted() && ms.button_left_pressed)
		{
			player1_switched_pokemon = false;
			move_for_player_1 = bench->ReturnMove2();
			player1_used_move = true;
			g_state = STATE_GAME_FOR_PLAYER_TWO;
			draw();
		}
		if (bench->ReturnMove3()->contains(mx, my))
		{
			bench->ReturnMove3()->SetHighlighted(true);
		}
		else
		{
			bench->ReturnMove3()->SetHighlighted(false);
		}
		if (bench->ReturnMove3()->ReturnHighlighted() && ms.button_left_pressed)
		{
			player1_switched_pokemon = false;
			move_for_player_1 = bench->ReturnMove3();
			player1_used_move = true;
			g_state = STATE_GAME_FOR_PLAYER_TWO;
			draw();
		}
		if (bench->ReturnMove4()->contains(mx, my))
		{
			bench->ReturnMove4()->SetHighlighted(true);
		}
		else
		{
			bench->ReturnMove4()->SetHighlighted(false);
		}
		if (bench->ReturnMove4()->ReturnHighlighted() && ms.button_left_pressed)
		{
			player1_switched_pokemon = false;
			move_for_player_1 = bench->ReturnMove4();
			player1_used_move = true;
			g_state = STATE_GAME_FOR_PLAYER_TWO;
			draw();
		}
		for (auto button : pb)
		{
			if (button->contains(mx, my))
			{
				button->SetHighlighted(true);
			}
			else {
				button->SetHighlighted(false);
			}
			if (button->ReturnHighlighted() && ms.button_left_pressed)
			{
				g_state = STATE_SELECT_POKEMON;
			}
		}
	}
	else if (g_state == STATE_SELECT_POKEMON)
	{
		for (auto pokemon : Pokemons_Player1)
		{
			if (pokemon->contains(mx, my) && pokemon != bench && pokemon->getHP() > 0)
			{
				pokemon->SetHighlighted(true);
			}
			else {
				pokemon->SetHighlighted(false);
			}
			if (pokemon->ReturnHighlighted() && ms.button_left_pressed)
			{
				player1_used_move = false;
				bool h = pokemon->ReturnValueDone();
				bench->setValueDone(h);
				bench_b = pokemon;
				bench->switchPokemonsPos(bench_b);
				player1_switched_pokemon = true;
				g_state = STATE_GAME_FOR_PLAYER_TWO;
			}
		}
		for (auto button : gb_list)
		{
			if (button->contains(mx, my))
			{
				button->setHighlighted(true);
			}
			else
			{
				button->setHighlighted(false);
			}

			if (button->ReturnHighlithed() && ms.button_left_pressed)
			{
				g_state = STATE_MOVE_SELECTION;
			}
		}
	}
	else if (g_state == STATE_GAME_FOR_PLAYER_TWO)
	{
		for (auto but : fight_button)
		{
			if (but->contains(mx, my))
			{
				but->SetHighlighted(true);
			}
			else
			{
				but->SetHighlighted(false);
			}
			if (but->ReturnHighlighted() && ms.button_left_pressed)
			{
				g_state = STATE_MOVE_SELECTION_2;
			}
		}
	}
	else if (g_state == STATE_MOVE_SELECTION_2)
	{
		if (bench_2->ReturnMove1()->contains(mx, my))
		{
			bench_2->ReturnMove1()->SetHighlighted(true);
		}
		else
		{
			bench_2->ReturnMove1()->SetHighlighted(false);
		}
		if (bench_2->ReturnMove1()->ReturnHighlighted() && ms.button_left_pressed)
		{
			move_for_player_2 = bench_2->ReturnMove1();
			bench = bench_b;
			player2_switched_pokemon = false;
			player2_used_move = true;
			if (player1_used_move)
			{
				if (bench_2->getSpeed() > bench->getSpeed())
				{
					g_state = STATE_FIGHT_FOR_PLAYER_TWO;
				}
				else if (bench->getSpeed() >= bench_2->getSpeed())
				{
					g_state = STATE_FIGHT_FOR_PLAYER_ONE;
				}
			}
			else if (player1_switched_pokemon)
			{
				g_state = STATE_FIGHT_FOR_PLAYER_ONE;
			}
		}
		if (bench_2->ReturnMove2()->contains(mx, my))
		{
			bench_2->ReturnMove2()->SetHighlighted(true);
		}
		else
		{
			bench_2->ReturnMove2()->SetHighlighted(false);
		}
		if (bench_2->ReturnMove2()->ReturnHighlighted() && ms.button_left_pressed)
		{
			move_for_player_2 = bench_2->ReturnMove2();
			bench = bench_b;
			player2_used_move = true;
			player2_switched_pokemon = false;
			if (player1_used_move)
			{
				if (bench_2->getSpeed() > bench->getSpeed())
				{
					g_state = STATE_FIGHT_FOR_PLAYER_TWO;
				}
				else if (bench->getSpeed() >= bench_2->getSpeed())
				{
					g_state = STATE_FIGHT_FOR_PLAYER_ONE;
				}
			}
			else if (player1_switched_pokemon)
			{
				g_state = STATE_FIGHT_FOR_PLAYER_ONE;
			}
		}
		if (bench_2->ReturnMove3()->contains(mx, my))
		{
			bench_2->ReturnMove3()->SetHighlighted(true);
		}
		else
		{
			bench_2->ReturnMove3()->SetHighlighted(false);
		}
		if (bench_2->ReturnMove3()->ReturnHighlighted() && ms.button_left_pressed)
		{
			move_for_player_2 = bench_2->ReturnMove3();
			bench = bench_b;
			player2_used_move = true;
			player2_switched_pokemon = false;
			if (player1_used_move)
			{
				if (bench_2->getSpeed() > bench->getSpeed())
				{
					g_state = STATE_FIGHT_FOR_PLAYER_TWO;
				}
				else if (bench->getSpeed() >= bench_2->getSpeed())
				{
					g_state = STATE_FIGHT_FOR_PLAYER_ONE;
				}
			}
			else if (player1_switched_pokemon)
			{
				g_state = STATE_FIGHT_FOR_PLAYER_ONE;
			}
			else if (player1_switched_pokemon)
			{
				g_state = STATE_FIGHT_FOR_PLAYER_ONE;
			}
		}
		if (bench_2->ReturnMove4()->contains(mx, my))
		{
			bench_2->ReturnMove4()->SetHighlighted(true);
		}
		else
		{
			bench_2->ReturnMove4()->SetHighlighted(false);
		}
		if (bench_2->ReturnMove4()->ReturnHighlighted() && ms.button_left_pressed)
		{
			move_for_player_2 = bench_2->ReturnMove4();
			bench = bench_b;
			player2_used_move = true;
			player2_switched_pokemon = false;
			if (player1_used_move)
			{
				if (bench_2->getSpeed() > bench->getSpeed())
				{
					g_state = STATE_FIGHT_FOR_PLAYER_TWO;
				}
				else if (bench->getSpeed() >= bench_2->getSpeed())
				{
					g_state = STATE_FIGHT_FOR_PLAYER_ONE;
				}
			}
			else if (player1_switched_pokemon)
			{
				g_state = STATE_FIGHT_FOR_PLAYER_ONE;
			}
		}

		for (auto button : pb)
		{
			if (button->contains(mx, my))
			{
				button->SetHighlighted(true);
			}
			else {
				button->SetHighlighted(false);
			}
			if (button->ReturnHighlighted() && ms.button_left_pressed)
			{
				g_state = STATE_SELECT_POKEMON_2;
			}
		}
	}
	else if (g_state == STATE_SELECT_POKEMON_2)
	{
		Pokemon* bench_2b;
		bench = bench_b;
		for (auto pokemon : Pokemons_Player2)
		{
			if (pokemon->contains(mx, my) && pokemon != bench_2 && pokemon->getHP() > 0)
			{
				pokemon->SetHighlighted(true);
			}
			else {
				pokemon->SetHighlighted(false);
			}
			if (pokemon->ReturnHighlighted() && ms.button_left_pressed)
			{
				bool h = pokemon->ReturnValueDone();
				bench_2->setValueDone(h);
				bench_2b = pokemon;
				bench_2->switchPokemonsPos(bench_2b);
				bench_2 = bench_2b;
				bench_2->SetHighlighted(false);
				player2_switched_pokemon = true;
				player2_used_move = false;
				if (player1_used_move == true)
				{
					g_state = STATE_FIGHT_FOR_PLAYER_TWO;
				}
				else if (player1_switched_pokemon == true)
				{
					g_state = STATE_FIGHT_FOR_PLAYER_ONE;
				}
				break;
			}
		}
		for (auto button : gb_list)
		{
			if (button->contains(mx, my))
			{
				button->setHighlighted(true);
			}
			else
			{
				button->setHighlighted(false);
			}

			if (button->ReturnHighlithed() && ms.button_left_pressed)
			{
				g_state = STATE_MOVE_SELECTION_2;
			}
		}
	}
	else if (g_state == STATE_FIGHT_FOR_PLAYER_ONE)
	{
		for (auto button : cb_list)
		{
			if (button->contains(mx, my))
			{
				button->SetHighlighted(true);
			}
			else {
				button->SetHighlighted(false);
			}

			if (button->ReturnHighlighted() && ms.button_left_pressed)
			{
				if (player1_used_move)
				{
					Damage* d = new Damage();
					int b = d->damage(bench, bench_2, move_for_player_1);
					bench_2->ReduceHP(b);
					g_state = STATE_FIGHT_FOR_PLAYER_ONE_PARTB;
					draw();
				}
				else if (player1_switched_pokemon)
				{
					g_state = STATE_FIGHT_FOR_PLAYER_TWO;
				}
			}
		}
	}
	else if (g_state == STATE_FIGHT_FOR_PLAYER_TWO)
	{
		for (auto button : cb_list)
		{
			if (button->contains(mx, my))
			{
				button->SetHighlighted(true);
			}
			else {
				button->SetHighlighted(false);
			}

			if (button->ReturnHighlighted() && ms.button_left_pressed)
			{
				if (player2_used_move)
				{
					Damage* d = new Damage();
					int b = d->damage(bench_2, bench, move_for_player_2);
					bench->ReduceHP(b);
					g_state = STATE_FIGHT_FOR_PLAYER_TWO_PARTB;
				}
				else if (player2_switched_pokemon == true && player1_switched_pokemon == false)
				{
					g_state = STATE_FIGHT_FOR_PLAYER_ONE;
				}
				else if (player2_switched_pokemon == true && player1_switched_pokemon == true)
				{
					g_state = STATE_GAME_FOR_PLAYER_ONE;
				}
			}
		}
	}
	else if (g_state == STATE_FIGHT_FOR_PLAYER_ONE_PARTB)
	{
		for (auto button : cb_list)
		{
			if (button->contains(mx, my))
			{
				button->SetHighlighted(true);
			}
			else {
				button->SetHighlighted(false);
			}

			if (button->ReturnHighlighted() && ms.button_left_pressed)
			{
				if (bench_2->getHP() == 0)
				{
					g_state = STATE_DEADPOKEMON_PLAYERTWO;
				}
				else
				{
					if (player2_switched_pokemon == false && bench->getSpeed() >= bench_2->getSpeed())
					{
						g_state = STATE_FIGHT_FOR_PLAYER_TWO;
					}
					else
					{
						g_state = STATE_GAME_FOR_PLAYER_ONE;
					}
				}
			}
		}
	}
	else if (g_state == STATE_FIGHT_FOR_PLAYER_TWO_PARTB)
	{
		for (auto button : cb_list)
		{
			if (button->contains(mx, my))
			{
				button->SetHighlighted(true);
			}
			else {
				button->SetHighlighted(false);
			}

			if (button->ReturnHighlighted() && ms.button_left_pressed)
			{
				if (bench->getHP() == 0)
				{
					g_state = STATE_DEADPOKEMON_PLAYERONE;
				}
				else
				{
					if (player1_switched_pokemon == false && bench_2->getSpeed() > bench->getSpeed())
					{
						g_state = STATE_FIGHT_FOR_PLAYER_ONE;
					}
					else if (player1_switched_pokemon == false && bench->getSpeed() >= bench_2->getSpeed())
					{
						g_state = STATE_GAME_FOR_PLAYER_ONE;
					}
					else if (player1_switched_pokemon == true)
					{
						g_state = STATE_GAME_FOR_PLAYER_ONE;
					}
				}
			}
		}
	}
	else if (g_state == STATE_DEADPOKEMON_PLAYERTWO)
	{
		for (auto button : cb_list)
		{
			if (button->contains(mx, my))
			{
				button->SetHighlighted(true);
			}
			else {
				button->SetHighlighted(false);
			}

			if (button->ReturnHighlighted() && ms.button_left_pressed)
			{
				pokemon_player2 = pokemon_player2 - 1;
				bench_2->isalive(false);
				if (pokemon_player2 == 0)
				{
					g_state = STATE_PLAYERONE_WINNER;
				}
				else
				{
					g_state = STATE_SELECT_DEADPOKEMON_TWO;
				}
			}
		}
	}
	else if (g_state == STATE_SELECT_DEADPOKEMON_TWO)
	{
		Pokemon* bench_2b;
		for (auto pokemon : Pokemons_Player2)
		{
			if (pokemon->contains(mx, my) && pokemon != bench_2 && pokemon->getHP() > 0)
			{
				pokemon->SetHighlighted(true);
			}
			else {
				pokemon->SetHighlighted(false);
			}
			if (pokemon->ReturnHighlighted() && ms.button_left_pressed)
			{
				bool h = pokemon->ReturnValueDone();
				bench_2->setValueDone(h);
				bench_2b = pokemon;
				bench_2->switchPokemonsPos(bench_2b);
				bench_2 = bench_2b;
				bench_2->SetHighlighted(false);
				g_state = STATE_GAME_FOR_PLAYER_ONE;
				break;
			}
		}
	}
	else if (g_state == STATE_DEADPOKEMON_PLAYERONE)
	{
		for (auto button : cb_list)
		{
			if (button->contains(mx, my))
			{
				button->SetHighlighted(true);
			}
			else {
				button->SetHighlighted(false);
			}

			if (button->ReturnHighlighted() && ms.button_left_pressed)
			{
				pokemon_player1 = pokemon_player1 - 1;
				bench->isalive(false);
				if (pokemon_player1 == 0)
				{
					g_state = STATE_PLAYERTWO_WINNER;
				}
				else
				{
					g_state = STATE_SELECT_DEADPOKEMON_ONE;
				}
			}
		}
	}
	else if (g_state == STATE_SELECT_DEADPOKEMON_ONE)
	{
		for (auto pokemon : Pokemons_Player1)
		{
			if (pokemon->contains(mx, my) && pokemon != bench && pokemon->getHP() > 0)
			{
				pokemon->SetHighlighted(true);
			}
			else {
				pokemon->SetHighlighted(false);
			}
			if (pokemon->ReturnHighlighted() && ms.button_left_pressed)
			{
				bool h = pokemon->ReturnValueDone();
				bench->setValueDone(h);
				bench_b = pokemon;
				bench->switchPokemonsPos(bench_b);
				bench = bench_b;
				bench->SetHighlighted(false);
				g_state = STATE_GAME_FOR_PLAYER_ONE;
				break;
			}
		}
	}
}
//PreGame Background
void Game::init_for_PreGameBackground()
{
	PreGameBackground* pic = new PreGameBackground();
	background.push_front(pic);
	pic->setPosX(CANVAS_WIDTH / 2);
	pic->setPosY(CANVAS_HEIGHT / 2);
}
//Start Button
void Game::init_for_Start_Button()
{
	Start* button = new Start();
	Start_button.push_back(button);
	button->setposx(CANVAS_WIDTH / 2);
	button->setposy(CANVAS_HEIGHT / 2);
}
//Game Background
void Game::init_for_Gamebackground()
{
	GameBackground* pic = new GameBackground();
	background_2.push_back(pic);
	pic->setPosX(CANVAS_WIDTH / 2);
	pic->setPosY(CANVAS_HEIGHT / 2);
}
//Create Players and their Pokemons
void Game::init_for_Player()
{
	Player* p = new Player();
	Players.push_back(p);
	p->create_players_team();
	Pokemons_Player1.push_back(p->ReturnPokemon1());
	Pokemons_Player1.push_back(p->ReturnPokemon2());
	Pokemons_Player1.push_back(p->ReturnPokemon3());
	bench = p->ReturnPokemon1();
	bench_b = p->ReturnPokemon1();
	for (auto pokemon : Pokemons_Player1)
	{
		Move* m1 = pokemon->ReturnMove1();
		m1->setposx(CANVAS_WIDTH * 1.0f / 4.0f);
		m1->setposy(CANVAS_HEIGHT * 1.0f / 4.0f);
		Move* m2 = pokemon->ReturnMove2();
		m2->setposx(CANVAS_WIDTH * 3.0f / 4.0f);
		m2->setposy(CANVAS_HEIGHT * 1.0f / 4.0f);
		Move* m3 = pokemon->ReturnMove3();
		m3->setposx(CANVAS_WIDTH * 3.0f / 4.0f);
		m3->setposy(CANVAS_HEIGHT * 1.5f / 2.0f);
		Move* m4 = pokemon->ReturnMove4();
		m4->setposx(CANVAS_WIDTH * 1.0f / 4.0f);
		m4->setposy(CANVAS_HEIGHT * 1.5f / 2.0f);
		moves.push_back(m4);
	}
	int i = 0;
	for (auto pokemon : Pokemons_Player1)
	{
		if (i == 1)
		{
			pokemon->setValueDone(true);
		}
		else if (i == 2)
		{
			pokemon->setValueDone(false);
		}
		i = i + 1;
	}
	Player* p2 = new Player();
	Players_2.push_back(p2);
	p2->create_players_team();
	Pokemons_Player2.push_back(p2->ReturnPokemon1());
	Pokemons_Player2.push_back(p2->ReturnPokemon2());
	Pokemons_Player2.push_back(p2->ReturnPokemon3());
	bench_2 = p2->ReturnPokemon1();
	int j = 0;
	for (auto pokemon : Pokemons_Player2)
	{
		Move* m1 = pokemon->ReturnMove1();
		m1->setposx(CANVAS_WIDTH * 1.0f / 4.0f);
		m1->setposy(CANVAS_HEIGHT * 1.0f / 4.0f);
		Move* m2 = pokemon->ReturnMove2();
		m2->setposx(CANVAS_WIDTH * 3.0f / 4.0f);
		m2->setposy(CANVAS_HEIGHT * 1.0f / 4.0f);
		Move* m3 = pokemon->ReturnMove3();
		m3->setposx(CANVAS_WIDTH * 3.0f / 4.0f);
		m3->setposy(CANVAS_HEIGHT * 1.5f / 2.0f);
		Move* m4 = pokemon->ReturnMove4();
		m4->setposx(CANVAS_WIDTH * 1.0f / 4.0f);
		m4->setposy(CANVAS_HEIGHT * 1.5f / 2.0f);
	}
	for (auto pokemon : Pokemons_Player2)
	{
		if (j == 1)
		{
			pokemon->setValueDone(true);
		}
		else if (j == 2)
		{
			pokemon->setValueDone(false);
		}
		j = j + 1;
	}
	Damage* d = new Damage();

	graphics::preloadBitmaps(ASSET_PATH);
	graphics::playMusic(std::string(ASSET_PATH) + "Pokemon.mp3", 1.0f, true, 4000);
	init_for_PreGameBackground();
	init_for_Start_Button();
	init_for_Gamebackground();
	init_for_Fight_Button();
	init_for_MoveSelectionBackground();
	init_for_Pokemon_Button();
	init_for_SwitchingPokemonsBackground();
	init_for_continue_button();
	init_for_VictoryBackground();
	init_for_GoBackButton();
	g_state = STATE_START;

	draw();
}
//Create loading Screen
void Game::init_for_LoadingScreen()
{
	LoadingScreen* ls = new LoadingScreen();
	background_3.push_back(ls);
	ls->setPosX(CANVAS_WIDTH / 2);
	ls->setPosY(CANVAS_HEIGHT / 2);
}
//create fight button
void Game::init_for_Fight_Button()
{
	Fight* button = new Fight();
	fight_button.push_back(button);
	button->setposx(CANVAS_WIDTH * 0.9f);
	button->setposy(CANVAS_HEIGHT * 1.6f / 2.0f);
}
//create move selection pic
void Game::init_for_MoveSelectionBackground()
{
	MoveSelectionBackground* background = new MoveSelectionBackground();
	msb.push_back(background);
	background->setposx(CANVAS_WIDTH / 2);
	background->setposy(CANVAS_HEIGHT / 2);
}
//create pokemon's moves
void Game::init_for_Moves()
{
	int i = 0;
	for (auto pokemon : Pokemons_Player1)
	{
		if (i == 0) 
		{
			Move* m1 = pokemon->ReturnMove1();
			moves.push_back(m1);
			Move* m2 = pokemon->ReturnMove2();
			moves.push_back(m2);
			Move* m3 = pokemon->ReturnMove3();
			moves.push_back(m3);
			Move* m4 = pokemon->ReturnMove4();
			moves.push_back(m4);
		}
		i = i + 1;
	}
}
//create button to see ur squad
void Game::init_for_Pokemon_Button()
{
	Pokemon_Button* button = new Pokemon_Button();
	pb.push_back(button);
	button->setposx(CANVAS_WIDTH / 2.0f);
	button->setposy(CANVAS_HEIGHT * 1.67f / 2.0f);
}
//create a switching pokemons pic
void Game::init_for_SwitchingPokemonsBackground()
{
	BackgroundForSwitchingPokemons* background = new BackgroundForSwitchingPokemons();
	bfsp.push_back(background);
	background->setposx(CANVAS_WIDTH / 2);
	background->setposy(CANVAS_HEIGHT / 2);
}
//create continue button
void Game::init_for_continue_button()
{
	ContinueButton* button = new ContinueButton();
	cb_list.push_back(button);
	button->Setposx(CANVAS_WIDTH * 0.9f);
	button->Setposy(CANVAS_HEIGHT * 1.6f / 2.0f);
}
//creata a victory background
void Game::init_for_VictoryBackground()
{
	VictoryBackground* background = new VictoryBackground();
	vb_list.push_back(background);
	background->setposx(CANVAS_WIDTH / 2);
	background->setposy(CANVAS_HEIGHT / 2);
}
//create a go back button
void Game::init_for_GoBackButton()
{
	GoBackButton* button = new GoBackButton();
	gb_list.push_back(button);
	button->setposx(CANVAS_WIDTH / 2.03f);
	button->setposy(CANVAS_HEIGHT /2);
}




// delete objects
Game::~Game()
{
	for (auto p : Players)
	{
		delete p;
	}

	for (auto p : Players_2)
	{
		delete p;
	}
	for (auto p : Pokemons_Player1)
	{
		delete p;
	}
	for (auto p : Pokemons_Player2)
	{
		delete p;
	}
	for (auto pic : background)
	{
		delete pic;
	}
	for (auto pic : background_2)
	{
		delete pic;
	}
	for (auto pic : background_3)
	{
		delete pic;
	}
	for (auto button : fight_button)
	{
		delete button;
	}
	for (auto move : moves)
	{
		delete move;
	}
	for (auto pic : msb)
	{
		delete pic;
	}
	for (auto button : pb)
	{
		delete button;
	}
	for (auto pic : bfsp)
	{
		delete pic;
	}
	for (auto move : moves_2)
	{
		delete move;
	}
	for (auto button : cb_list)
	{
		delete button;
	}
	for (auto pic : vb_list)
	{
		delete pic;
	}
	delete move_for_player_1;
	delete move_for_player_2;
}




Game* Game::getInstance()
{
	if (!m_instance)
		m_instance = new Game();
	return m_instance;
}


Game* Game::m_instance = nullptr;