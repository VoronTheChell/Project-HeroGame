#include "NPC.h"
#include "Evil.h"
#include <iostream>
#include <windows.h>

using namespace std;

Evil::Evil()
{
	name = "evil_npc";
	damage = 5;
	armor = 3;
}

// ВНИМАНИЕ: ДАННЫЙ ПРИМЕР ИСПОЛЬЗУЕТСЯ В ОБРОЗОВАТЕЛЬНЫХ ЦЕЛЯХ, НЕ ИСПОЛЬЗОВАТЬ НА ПРАКТИКЕ!
/*
Evil(string name) // Делегирование конструтора (т.е. вызывается в начале базовых)
{
	this->name = name;
}

Evil(string name, unsigned int damage) : Evil(name)
{
	this->damage = damage;
}

Evil(string name, unsigned int damage, unsigned int health) : Evil(name, damage)
{
	this->health = health;
}

Evil(string name, unsigned int damage, unsigned int health, unsigned int armor) : Evil(name, damage, health)
{
	this->armor = armor;
}
*/