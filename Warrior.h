#pragma once

#include "NPC.h"

#include <string>
#include <vector>

struct Weapon
{
	std::string name{ "weapon" };
	unsigned int damage{ 1 };
};

class Warrior : virtual public NPC
{
protected:
	short strength{ 21 };
	std::vector<Weapon> weapons;

	void PrepareCharacter() override;

	void ShowEquipment() override;

public:

	Warrior();

	void GetInfo() override;

	void GetWeapon();
};