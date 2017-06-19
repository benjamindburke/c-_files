#include "bat.h"
#include "bear.h"
#include "bird.h"
#include "boss.h"
#include "deer.h"
#include "enemy.h"
#include "hero.h"
#include "rat.h"
#include "wolf.h"

#include <assert.h>
#include <chrono>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <typeinfo>
#include <vector>

bool all_defeated(vector<enemy*> enemies) //Checks vector of enemies to check if all enemies are dead
{
    //returns false if a single enemy is not dead
    for (int i = 0; i < enemies.size(); i++)
    {
	if (!enemies[i]->dead())
	    return false;
    }

    //else it returns true
    return true;
}

void instructions()
{
    //prints out instructions for game which provides information on commands
    cout << endl;
    cout << "Vile, evil creatures have infected this land, and it's your job to bring about an age of peace!" << endl;
    cout << "On this adventure, you have 5 tools at your disposal." << endl;
    cout << "Your sword does damage to hostile enemies!" << endl;
    cout << "Your shield protects you from half of the damage an enemy would normally inflict!" << endl;
    cout << "Your fireballs deal more damage than your sword!" << endl;
    cout << "Your potions heal you for a good chunk of health!" << endl;
    cout << "Your knowledge allows you to reveal tips about the enemy! An enemy will not attack if you ask for a tip." << endl;
    cout << "Now that you know how to defeat the creatures that populate this land, prepare yourself! The first one approaches!"
	 << endl << endl;
}

void print_format(hero player, enemy* my_enemy)
{
    //prints format of gameplay - left is player info, right is enemy info
    string str;

    cout << endl << string(65, '-') << endl;

    cout << "| "; cout.width(30); cout << left << player.name();
    cout << "| "; cout.width(30); cout << left << my_enemy->name(); cout << "|" << endl;

    str = "| health: " + to_string(player.health()) + "/100";
    cout.width(32); cout << left << str;
    str = "| health: " + to_string(my_enemy->health()) + "/"+ to_string(my_enemy->max_health());
    cout.width(32); cout << left << str << "|" << endl;

    str = "| fireballs: " + to_string(player.fireballs()) + "/10";
    cout.width(32); cout << left << str;

    str = "| fireballs: " + to_string(my_enemy->fireballs()) + "/" + to_string(my_enemy->max_fireballs());
    cout.width(32); cout << left << str << "|" << endl;

    str = "| potions: " + to_string(player.potions()) + "/6";
    cout.width(32); cout << left << str;

    str = "| potions:" + to_string(my_enemy->potions()) + "/" + to_string(my_enemy->max_potions());
    cout.width(32); cout << left << str << "|" << endl;

    cout << string(65, '-') << endl;
}

int main()
{
    int num_of_enemies;

    string hero_name;

    //ask for hero name
    cout << "Welcome to Adventure Battle!" << endl;
    cout << "What is your hero's name? ";
    //getline just in case user wants a two word name
    getline(cin, hero_name);
    //create hero player
    hero player(hero_name);

    //asks user for number of enemies
    cout << "How many enemies will there be? " << endl;
    cin >> num_of_enemies;
    //program closes if inputted number is < 0
    assert (num_of_enemies > 0);

    //creates enemy vector
    vector<enemy*> enemies;

    for (int i = 0; i < num_of_enemies - 1; i++) //Add randomly generated enemies and leave one spot for final enemy
    {
	//set random seed
	srand(chrono::system_clock::now().time_since_epoch() / chrono::milliseconds(rand() % 17 + 1));
	int num = rand() % 20;
	//strongest enemies are least likely to be created
	if (num > 16)
	    enemies.push_back(new deer());
	else if (num > 15)
	    enemies.push_back(new bear());
	else if (num > 13)
	    enemies.push_back(new wolf());
	else if (num > 9)
	    enemies.push_back(new rat());
	else if (num > 4)
	    enemies.push_back(new bat());
	else
	    enemies.push_back(new bird());
    }

    //Add boss at end of vector so boss is last enemy fought - boss is only enemy fought if there's only 1 enemy
    enemies.push_back(new boss());

    //Prints out instructions to user
    instructions();

    //Loop game while there are enemies to kill
    while (!all_defeated(enemies))
    {
	//Loop for each enemies
	for (int i = 0; i < enemies.size(); i++) 
	{
	    //print out enemy info
	    cout << endl << enemies[i]->out();

	    //Continues during combat with single enemy
	    while (!enemies[i]->dead())
	    {
		//Set and reset command
		string command = ""; 

		//prints out game in set format
		print_format(player, enemies[i]);

		//asks user for command string
		cout << endl << "Enter command: sword shield fireball potion tip exit" << endl;
		cin >> command;
		cout << endl;

		//handles user input for hero commands
		if (command == "sword")
		{
		    player.attack(enemies[i]);
		    cout << player.name() << " does sword slash attack!" << endl;
		}
		else if (command == "shield")
		{
		    player.shield();
		    cout << player.name() << " hides behind shield!" << endl;
		}
		else if (command == "fireball")
		{
		    player.fireball(enemies[i]);
		    cout << player.name() << " throws a fireball!" << endl;
		}
		else if (command == "potion")
		{
		    player.potion();
		    cout << player.name() << " uses a potion!" << endl;
		}
		else if (command == "tip")
		{
		    cout << enemies[i]->tip() << endl;
		}
		else if (command == "exit")
		{
		    return 0;
		}
		else
		{
		    //if user inputs anything other than what can be handled, hero is not attacked and game loops again with nothing changed
		    cout << "That is an invalid command." << endl;
		    //Fulfills no attack conditional but doesn't output a tip. No need to reinvent the wheel
		    command = "tip";
		}

		//If player asks for a tip about enemy, player is not attacked
		if (!enemies[i]->dead() && command != "tip")
		{
		    enemies[i]->attack(&player);
		    cout << enemies[i]->name() << " " << enemies[i]->attack_name() << " you!" << endl;
		}

		if (player.dead())
		{
		    //game ends if user dies
		    cout << endl << "You died. Try again!" << endl;
		    return 0;
		}
	    }

	    cout << endl << enemies[i]->name() << " has been defeated!" << endl;
	}
	
    }

    //after game is ended
    cout << "You defeated all of the enemies and brought peace to the world! Good job!" << endl;

    return 0;
}