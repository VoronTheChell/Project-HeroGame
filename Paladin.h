#pragma once
#include <string>
#include "Warrior.h"
#include "Wizard.h"

class Paladin : public Warrior, public Wizard
{
	protected:
		void PrepareCharacter() override;
		void ShowEquipment() override;

	public:

		Paladin();
		void GetInfo() override;
		~Paladin();
};