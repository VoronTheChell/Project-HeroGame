#include "CharacterFactory.h"

#include "Warrior.h"
#include "Wizard.h"
#include "Paladin.h"

using namespace std;

unique_ptr<NPC> CharacterFactory::CreateCharacter(PlayerClass playerClass)
{
	switch (playerClass)
	{
		case PlayerClass::Warrior:
			return make_unique<Warrior>();

		case PlayerClass::Wizard:
			return make_unique<Wizard>();

		case PlayerClass::Paladin:
			return make_unique<Paladin>();

		default:
			return nullptr;
	}
}