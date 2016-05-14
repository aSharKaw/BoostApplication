#include "Game.h"
#include "Enemy.h"
#include "Save.h"
#include "Load.h"

Enemy enemy;
Save save;
Load load;

Game::Game()
{
	player_name = "";
	player_level = player_maxhp = player_hp = player_maxmp = player_mp = player_exp = 0;
	

	//enemy_name = enemy.getEnemyName("enemy1.Name");
	//enemy_hp = enemy.getEnemyStatus("enemy1.hp");
	//enemy_mp = enemy.getEnemyStatus("enemy1.mp");
	//enemy_exp = enemy.getEnemyStatus("enemy1.exp");
}


Game::~Game()
{
}

void Game::Title()
{
	string _mode;


	cout << format("%1%%2%%3%") 
		% "-------\n" 
		% " Title\n" 
		% "-------\n\n";
	cout << format("%1%%2%") 
		% "・New  Game\n" 
		% "・Load Game\n";

	cout << "Select Menu->(n/l)" << endl;
	cin >> _mode;

	if (_mode == "n")
	{
		std::system("cls");
		cout << format("%1%%2%%3%")
			% "Welcome World!!\n\n"
			% "Create Player\n"
			% "Player Name? ->";
		cin >> player_name;

		cout << format("%1%")
			% "...OK! Enjoy World!!";

		save.Saving("res/save1.ini", player_name, 1);
	}
	else if (_mode == "l")
	{
		std::system("cls");

		player_name = load.getName();
		player_level = load.getLevel();
	}
	
}

void Game::Buttle()
{
	//敵のロード
	enemy_name = enemy.getEnemyName("Enemy1.Name");
	enemy_hp = enemy.getEnemyStatus("Enemy1.hp");
	enemy_mp = enemy.getEnemyStatus("Enemy1.mp");
	enemy_exp = enemy.getEnemyStatus("Enemy1.exp");

	cout << format("%1%%2%%3%")
		% "Encount "
		% enemy_name
		% "!!\n";
}