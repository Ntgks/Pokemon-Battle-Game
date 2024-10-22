#include "Player.h"
#include "define.h"
#include <string>

void Player::draw(bool h, Pokemon* Pokemon)
{
	if (p_state == GAME)
	{
		if (h == true) {
			for (auto pokemon : Pokemons)
			{
				if (Pokemon->getName() == pokemon->getName()) {
					graphics::Brush br;
					br.outline_opacity = 0.0f;
					SETCOLOR(br.fill_color, 0.0f, 0.0f, 0.0f);
					graphics::setFont("FreeSans.ttf");
					graphics::drawText(CANVAS_WIDTH * 0.05f, CANVAS_HEIGHT * 1.2f / 2.0f, 0.7f, pokemon->getName(), br);
					SETCOLOR(br.fill_color, 0.0f, 0.0f, 0.0f);
					graphics::setFont("FreeSans.ttf");
					int a = pokemon->getHP() / pokemon->ReturnConstHp() * 100;
					graphics::drawText(CANVAS_WIDTH * 0.2f, CANVAS_HEIGHT * 1.32f / 2.0f, 0.5f, to_string(a) + "%", br);
					SETCOLOR(br.fill_color, 1.0f, 1.0f, 1.0f);
					br.texture = ASSET_PATH + std::string(pokemon->draw_back());
					graphics::drawRect(pokemon->backposx(), pokemon->backposy(), PLAYER_SIZE_1, PLAYER_SIZE_1, br);

					if (pokemon->getHP() / pokemon->ReturnConstHp() * 100 > 50)
					{
						SETCOLOR(br.fill_color, 0.0f, 100.0f, 0.0f);
						br.texture = "";
						br.outline_opacity = 0.0f;
						float life = Pokemon->getHP() / Pokemon->ReturnConstHp() * 5.0f;
						graphics::drawRect(CANVAS_WIDTH * 0.1f, CANVAS_HEIGHT * 1.3f / 2.0f, life, 0.5f, br);
					}
					else if (pokemon->getHP() / pokemon->ReturnConstHp() * 100 > 25)
					{
						SETCOLOR(br.fill_color, 20.0f, 100.0f, 0.0f);
						br.texture = "";
						br.outline_opacity = 0.0f;
						float life = Pokemon->getHP() / Pokemon->ReturnConstHp() * 5.0f;
						graphics::drawRect(CANVAS_WIDTH * 0.1f, CANVAS_HEIGHT * 1.3f / 2.0f, life, 0.5f, br);
					}
					else if (pokemon->getHP() / pokemon->ReturnConstHp() * 100 <= 25)
					{
						SETCOLOR(br.fill_color, 1.0f, 0.2f, 0.2f);
						br.texture = "";
						br.outline_opacity = 0.0f;
						float life = Pokemon->getHP() / Pokemon->ReturnConstHp() * 5.0f;
						graphics::drawRect(CANVAS_WIDTH * 0.1f, CANVAS_HEIGHT * 1.3f / 2.0f, life, 0.5f, br);
					}
					br.outline_opacity = 1.0f;
					br.gradient = false;
					br.fill_opacity = 0.0f;
					graphics::drawRect(CANVAS_WIDTH * 0.1f, CANVAS_HEIGHT * 1.3f / 2.0f, 5.0f, 0.5f, br);


				}
			}
		}
		else if (h == false)
		{
			for (auto pokemon : Pokemons)
			{
				if (Pokemon->getName() == pokemon->getName()) {
					graphics::Brush br;
					br.outline_opacity = 0.0f;
					SETCOLOR(br.fill_color, 0.0f, 0.0f, 0.0f);
					graphics::setFont("FreeSans.ttf");
					graphics::drawText(CANVAS_WIDTH * 0.05f, CANVAS_HEIGHT * 0.25f / 2.0f, 0.7f, pokemon->getName(), br);
					SETCOLOR(br.fill_color, 0.0f, 0.0f, 0.0f);
					graphics::setFont("FreeSans.ttf");
					int a = pokemon->getHP() / pokemon->ReturnConstHp() * 100;
					graphics::drawText(CANVAS_WIDTH * 0.2f, CANVAS_HEIGHT * 0.37f / 2.0f, 0.5f, to_string(a) + "%", br);
					SETCOLOR(br.fill_color, 1.0f, 1.0f, 1.0f);
					br.texture = ASSET_PATH + std::string(pokemon->draw_front());
					graphics::drawRect(pokemon->frontposx(), pokemon->frontposy(), PLAYER_SIZE_2, PLAYER_SIZE_2, br);

					if (pokemon->getHP() / pokemon->ReturnConstHp() * 100 > 50)
					{
						SETCOLOR(br.fill_color, 0.0f, 100.0f, 0.0f);
						br.texture = "";
						br.outline_opacity = 0.0f;
						float life = Pokemon->getHP() / Pokemon->ReturnConstHp() * 5.0f;
						graphics::drawRect(CANVAS_WIDTH * 0.1f, CANVAS_HEIGHT * 0.35f / 2.0f, life, 0.5f, br);
					}
					else if (pokemon->getHP() / pokemon->ReturnConstHp() * 100 > 25)
					{
						SETCOLOR(br.fill_color, 20.0f, 100.0f, 0.0f);
						br.texture = "";
						br.outline_opacity = 0.0f;
						float life = Pokemon->getHP() / Pokemon->ReturnConstHp() * 5.0f;
						graphics::drawRect(CANVAS_WIDTH * 0.1f, CANVAS_HEIGHT * 0.35f / 2.0f, life, 0.5f, br);
					}
					else if (pokemon->getHP() / pokemon->ReturnConstHp() * 100 <= 25)
					{
						SETCOLOR(br.fill_color, 1.0f, 0.2f, 0.2f);
						br.texture = "";
						br.outline_opacity = 0.0f;
						float life = Pokemon->getHP() / Pokemon->ReturnConstHp() * 5.0f;
						graphics::drawRect(CANVAS_WIDTH * 0.1f, CANVAS_HEIGHT * 0.35f / 2.0f, life, 0.5f, br);
					}


					br.outline_opacity = 1.0f;
					br.gradient = false;
					br.fill_opacity = 0.0f;
					graphics::drawRect(CANVAS_WIDTH * 0.1f, CANVAS_HEIGHT * 0.35f / 2.0f, 5.0f, 0.5f, br);


					SETCOLOR(br.fill_color, 0.0f, 0.0f, 0.0f);
					graphics::setFont("FreeSans.ttf");
					string s = to_string(pokemon->getHP() / pokemon->ReturnConstHp() * 100);
					graphics::drawText(CANVAS_WIDTH * 0.3f, CANVAS_HEIGHT * 0.35f / 2.0f, 0.7f, s + "%", br);
				}
			}
		}
	}
	else if (p_state == FIGHTONE)
	{
		if (h == true) {
			for (auto pokemon : Pokemons)
			{
				if (Pokemon->getName() == pokemon->getName()) {
					graphics::Brush br;
					br.outline_opacity = 0.0f;
					SETCOLOR(br.fill_color, 0.0f, 0.0f, 0.0f);
					graphics::setFont("FreeSans.ttf");
					graphics::drawText(CANVAS_WIDTH * 0.05f, CANVAS_HEIGHT * 1.2f / 2.0f, 0.7f, pokemon->getName(), br);
					SETCOLOR(br.fill_color, 0.0f, 0.0f, 0.0f);
					graphics::setFont("FreeSans.ttf");
					int a = pokemon->getHP() / pokemon->ReturnConstHp() * 100;
					graphics::drawText(CANVAS_WIDTH * 0.2f, CANVAS_HEIGHT * 1.32f / 2.0f, 0.5f, to_string(a) + "%", br);
					SETCOLOR(br.fill_color, 1.0f, 1.0f, 1.0f);
					br.texture = ASSET_PATH + std::string(pokemon->draw_back());
					graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, PLAYER_SIZE_1, PLAYER_SIZE_1, br);

					if (pokemon->getHP() / pokemon->ReturnConstHp() * 100 > 50)
					{
						SETCOLOR(br.fill_color, 0.0f, 100.0f, 0.0f);
						br.texture = "";
						br.outline_opacity = 0.0f;
						float life = Pokemon->getHP() / Pokemon->ReturnConstHp() * 5.0f;
						graphics::drawRect(CANVAS_WIDTH * 0.1f, CANVAS_HEIGHT * 1.3f / 2.0f, life, 0.5f, br);
					}
					else if (pokemon->getHP() / pokemon->ReturnConstHp() * 100 > 25)
					{
						SETCOLOR(br.fill_color, 20.0f, 100.0f, 0.0f);
						br.texture = "";
						br.outline_opacity = 0.0f;
						float life = Pokemon->getHP() / Pokemon->ReturnConstHp() * 5.0f;
						graphics::drawRect(CANVAS_WIDTH * 0.1f, CANVAS_HEIGHT * 1.3f / 2.0f, life, 0.5f, br);
					}
					else if (pokemon->getHP() / pokemon->ReturnConstHp() * 100 <= 25)
					{
						SETCOLOR(br.fill_color, 1.0f, 0.2f, 0.2f);
						br.texture = "";
						br.outline_opacity = 0.0f;
						float life = Pokemon->getHP() / Pokemon->ReturnConstHp() * 5.0f;
						graphics::drawRect(CANVAS_WIDTH * 0.1f, CANVAS_HEIGHT * 1.3f / 2.0f, life, 0.5f, br);
					}
					br.outline_opacity = 1.0f;
					br.gradient = false;
					br.fill_opacity = 0.0f;
					graphics::drawRect(CANVAS_WIDTH * 0.1f, CANVAS_HEIGHT * 1.3f / 2.0f, 5.0f, 0.5f, br);


				}
			}

		}
		else if (h == false)
		{
			for (auto pokemon : Pokemons)
			{
				if (Pokemon->getName() == pokemon->getName())
				{
					graphics::Brush br;
					br.outline_opacity = 0.0f;
					SETCOLOR(br.fill_color, 0.0f, 0.0f, 0.0f);
					graphics::setFont("FreeSans.ttf");
					graphics::drawText(CANVAS_WIDTH * 0.05f, CANVAS_HEIGHT * 0.25f / 2.0f, 0.7f, pokemon->getName(), br);
					SETCOLOR(br.fill_color, 0.0f, 0.0f, 0.0f);
					graphics::setFont("FreeSans.ttf");
					int a = pokemon->getHP() / pokemon->ReturnConstHp() * 100;
					graphics::drawText(CANVAS_WIDTH * 0.2f, CANVAS_HEIGHT * 0.37f / 2.0f, 0.5f, to_string(a) + "%", br);
					SETCOLOR(br.fill_color, 1.0f, 1.0f, 1.0f);
					br.texture = ASSET_PATH + std::string(pokemon->draw_front());
					graphics::drawRect(pokemon->frontposx(), pokemon->frontposy(), PLAYER_SIZE_2, PLAYER_SIZE_2, br);

					if (pokemon->getHP() / pokemon->ReturnConstHp() * 100 > 50)
					{
						SETCOLOR(br.fill_color, 0.0f, 100.0f, 0.0f);
						br.texture = "";
						br.outline_opacity = 0.0f;
						float life = Pokemon->getHP() / Pokemon->ReturnConstHp() * 5.0f;
						graphics::drawRect(CANVAS_WIDTH * 0.1f, CANVAS_HEIGHT * 0.35f / 2.0f, life, 0.5f, br);
					}
					else if (pokemon->getHP() / pokemon->ReturnConstHp() * 100 > 25)
					{
						SETCOLOR(br.fill_color, 20.0f, 100.0f, 0.0f);
						br.texture = "";
						br.outline_opacity = 0.0f;
						float life = Pokemon->getHP() / Pokemon->ReturnConstHp() * 5.0f;
						graphics::drawRect(CANVAS_WIDTH * 0.1f, CANVAS_HEIGHT * 0.35f / 2.0f, life, 0.5f, br);
					}
					else if (pokemon->getHP() / pokemon->ReturnConstHp() * 100 <= 25)
					{
						SETCOLOR(br.fill_color, 1.0f, 0.2f, 0.2f);
						br.texture = "";
						br.outline_opacity = 0.0f;
						float life = Pokemon->getHP() / Pokemon->ReturnConstHp() * 5.0f;
						graphics::drawRect(CANVAS_WIDTH * 0.1f, CANVAS_HEIGHT * 0.35f / 2.0f, life, 0.5f, br);
					}


					br.outline_opacity = 1.0f;
					br.gradient = false;
					br.fill_opacity = 0.0f;
					graphics::drawRect(CANVAS_WIDTH * 0.1f, CANVAS_HEIGHT * 0.35f / 2.0f, 5.0f, 0.5f, br);


					SETCOLOR(br.fill_color, 0.0f, 0.0f, 0.0f);
					graphics::setFont("FreeSans.ttf");
					string s = to_string(pokemon->getHP() / pokemon->ReturnConstHp() * 100);
					graphics::drawText(CANVAS_WIDTH * 0.3f, CANVAS_HEIGHT * 0.35f / 2.0f, 0.7f, s + "%", br);
				}
			}
		}
	}
	else if (p_state == FIGHTTWO)
	{
		if (h == true) {
			for (auto pokemon : Pokemons)
			{
				if (Pokemon->getName() == pokemon->getName()) {
					graphics::Brush br;
					br.outline_opacity = 0.0f;
					SETCOLOR(br.fill_color, 0.0f, 0.0f, 0.0f);
					graphics::setFont("FreeSans.ttf");
					graphics::drawText(CANVAS_WIDTH * 0.05f, CANVAS_HEIGHT * 1.2f / 2.0f, 0.7f, pokemon->getName(), br);
					SETCOLOR(br.fill_color, 0.0f, 0.0f, 0.0f);
					graphics::setFont("FreeSans.ttf");
					int a = pokemon->getHP() / pokemon->ReturnConstHp() * 100;
					graphics::drawText(CANVAS_WIDTH * 0.2f, CANVAS_HEIGHT * 1.32f / 2.0f, 0.5f, to_string(a) + "%", br);
					SETCOLOR(br.fill_color, 1.0f, 1.0f, 1.0f);
					br.texture = ASSET_PATH + std::string(pokemon->draw_back());
					graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, PLAYER_SIZE_1, PLAYER_SIZE_1, br);

					if (pokemon->getHP() / pokemon->ReturnConstHp() * 100 > 50)
					{
						SETCOLOR(br.fill_color, 0.0f, 100.0f, 0.0f);
						br.texture = "";
						br.outline_opacity = 0.0f;
						float life = Pokemon->getHP() / Pokemon->ReturnConstHp() * 5.0f;
						graphics::drawRect(CANVAS_WIDTH * 0.1f, CANVAS_HEIGHT * 1.3f / 2.0f, life, 0.5f, br);
					}
					else if (pokemon->getHP() / pokemon->ReturnConstHp() * 100 > 25)
					{
						SETCOLOR(br.fill_color, 20.0f, 100.0f, 0.0f);
						br.texture = "";
						br.outline_opacity = 0.0f;
						float life = Pokemon->getHP() / Pokemon->ReturnConstHp() * 5.0f;
						graphics::drawRect(CANVAS_WIDTH * 0.1f, CANVAS_HEIGHT * 1.3f / 2.0f, life, 0.5f, br);
					}
					else if (pokemon->getHP() / pokemon->ReturnConstHp() * 100 <= 25)
					{
						SETCOLOR(br.fill_color, 1.0f, 0.2f, 0.2f);
						br.texture = "";
						br.outline_opacity = 0.0f;
						float life = Pokemon->getHP() / Pokemon->ReturnConstHp() * 5.0f;
						graphics::drawRect(CANVAS_WIDTH * 0.1f, CANVAS_HEIGHT * 1.3f / 2.0f, life, 0.5f, br);
					}
					br.outline_opacity = 1.0f;
					br.gradient = false;
					br.fill_opacity = 0.0f;
					graphics::drawRect(CANVAS_WIDTH * 0.1f, CANVAS_HEIGHT * 1.3f / 2.0f, 5.0f, 0.5f, br);


				}
			}
		}
		else if (h == false)
		{
			for (auto pokemon : Pokemons)
			{
				if (Pokemon->getName() == pokemon->getName()) {
					graphics::Brush br;
					br.outline_opacity = 0.0f;
					SETCOLOR(br.fill_color, 0.0f, 0.0f, 0.0f);
					graphics::setFont("FreeSans.ttf");
					graphics::drawText(CANVAS_WIDTH * 0.05f, CANVAS_HEIGHT * 0.25f / 2.0f, 0.7f, pokemon->getName(), br);
					SETCOLOR(br.fill_color, 0.0f, 0.0f, 0.0f);
					graphics::setFont("FreeSans.ttf");
					int a = pokemon->getHP() / pokemon->ReturnConstHp() * 100;
					graphics::drawText(CANVAS_WIDTH * 0.2f, CANVAS_HEIGHT * 0.37f / 2.0f, 0.5f, to_string(a) + "%", br);
					SETCOLOR(br.fill_color, 1.0f, 1.0f, 1.0f);
					br.texture = ASSET_PATH + std::string(pokemon->draw_front());
					graphics::drawRect(pokemon->frontposx(), pokemon->frontposy(), PLAYER_SIZE_2, PLAYER_SIZE_2, br);

					if (pokemon->getHP() / pokemon->ReturnConstHp() * 100 > 50)
					{
						SETCOLOR(br.fill_color, 0.0f, 100.0f, 0.0f);
						br.texture = "";
						br.outline_opacity = 0.0f;
						float life = Pokemon->getHP() / Pokemon->ReturnConstHp() * 5.0f;
						graphics::drawRect(CANVAS_WIDTH * 0.1f, CANVAS_HEIGHT * 0.35f / 2.0f, life, 0.5f, br);
					}
					else if (pokemon->getHP() / pokemon->ReturnConstHp() * 100 > 25)
					{
						SETCOLOR(br.fill_color, 20.0f, 100.0f, 0.0f);
						br.texture = "";
						br.outline_opacity = 0.0f;
						float life = Pokemon->getHP() / Pokemon->ReturnConstHp() * 5.0f;
						graphics::drawRect(CANVAS_WIDTH * 0.1f, CANVAS_HEIGHT * 0.35f / 2.0f, life, 0.5f, br);
					}
					else if (pokemon->getHP() / pokemon->ReturnConstHp() * 100 <= 25)
					{
						SETCOLOR(br.fill_color, 1.0f, 0.2f, 0.2f);
						br.texture = "";
						br.outline_opacity = 0.0f;
						float life = Pokemon->getHP() / Pokemon->ReturnConstHp() * 5.0f;
						graphics::drawRect(CANVAS_WIDTH * 0.1f, CANVAS_HEIGHT * 0.35f / 2.0f, life, 0.5f, br);
					}


					br.outline_opacity = 1.0f;
					br.gradient = false;
					br.fill_opacity = 0.0f;
					graphics::drawRect(CANVAS_WIDTH * 0.1f, CANVAS_HEIGHT * 0.35f / 2.0f, 5.0f, 0.5f, br);


					SETCOLOR(br.fill_color, 0.0f, 0.0f, 0.0f);
					graphics::setFont("FreeSans.ttf");
					string s = to_string(pokemon->getHP() / pokemon->ReturnConstHp() * 100);
					graphics::drawText(CANVAS_WIDTH * 0.3f, CANVAS_HEIGHT * 0.35f / 2.0f, 0.7f, s + "%", br);
				}
			}
		}
	}

}

void Player::update()
{
}

void Player::create_players_team()
{
	PokemonArray* a = new PokemonArray();
	a->createarray();
	a->ReturnList();
	Pokemons.push_back(a->ReturnPokemon1());
	Pokemons.push_back(a->ReturnPokemon2());
	Pokemons.push_back(a->ReturnPokemon3());
}

Pokemon* Player::ReturnPokemon1()
{
	int i = 0;
	for (auto pokemon : Pokemons)
	{
		if (i == 0)
		{
			return pokemon;
		}
		else
		{
			i = i + 1;
		}
	}
}

Pokemon* Player::ReturnPokemon2()
{
	int i = 0;
	for (auto pokemon : Pokemons)
	{
		if (i == 1)
		{
			return pokemon;
		}
		else
		{
			i = i + 1;
		}
	}
}

Pokemon* Player::ReturnPokemon3()
{
	int i = 0;
	for (auto pokemon : Pokemons)
	{
		if (i == 2)
		{
			return pokemon;
		}
		else
		{
			i = i + 1;
		}
	}
}