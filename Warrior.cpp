#include "Warrior.h"
#include <iostream>

using namespace std;

Warrior::Warrior()
{
	className = "воина";

	damage = 20;
	health = 30;
	armor = 15;
}

void Warrior::PrepareCharacter() 
{
	Weapon weapon;

	weapon.damage = 1;
	weapon.name = "Кулаки";

	weapons.push_back(weapon);
}

void Warrior::ShowEquipment()
{
	GetWeapon();
}

void Warrior::GetInfo()
{
	NPC::GetInfo();

	cout << "Сила: " << strength << endl;
}

void Warrior::GetWeapon()
{
	cout << name << " взял в руки оружие: "
		<< weapons[0].name << endl;

	cout << "Добавка к урону: "
		<< weapons[0].damage << endl;
}