#pragma once

#include "NPC.h"

#include <string>
#include <vector>

struct Spell
{
	std::string name{ "spell" };
	unsigned int damage{ 1 };
};

class Wizard : virtual public NPC
{
	protected:
		short intellect{ 29 };
		std::vector<Spell> spells;

		void PrepareCharacter() override;
		void ShowEquipment() override;

	public:
		Wizard();
		void GetInfo() override;
		void LearnSpell();
};

