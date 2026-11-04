#pragma once

#include <memory>

#include "NPC.h"
#include "PlayerClass.h"

class CharacterFactory
{
	public:
		static std::unique_ptr<NPC> CreateCharacter(PlayerClass playerClass);
};