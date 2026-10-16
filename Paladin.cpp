#include "Paladin.h"
#include "Warrior.h"
#include "Wizard.h"

#include <iostream>
#include <windows.h>

using namespace std;

Paladin::Paladin()
{
	className = "паладина";

	intellect = 25;
	strength = 19;

	health = 25;
	damage = 25;
	armor = 20;
}

void Paladin::PrepareCharacter()
{
	Weapon weapon;
	weapon.damage = 5;
	weapon.name = "Меч новичка";

	weapons.push_back(weapon);


	Spell spell;
	spell.damage = 2;
	spell.name = "Божий шок";

	spells.push_back(spell);
}

void Paladin::ShowEquipment()
{
	GetWeapon();
	LearnSpell();
}

void Paladin::GetInfo()
{
	NPC::GetInfo();

	cout << "Сила: " << strength << endl;
	cout << "Интеллект: " << intellect << endl;
}

Paladin::~Paladin()
{
	cout << name
		<< " увидел свет в конце тоннеля..."
		<< " но оказалось, это экран загрузки."
		<< endl;
}
