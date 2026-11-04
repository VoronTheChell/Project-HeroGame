#pragma once

#include <memory>

#include "NPC.h"
#include "PlayerClass.h"

class Player
{
private:
	std::unique_ptr<NPC> currentCharacter{ nullptr };

public:
	bool Create(PlayerClass playerClass);

	//void Create(std::unique_ptr <NPC> player);
	NPC* GetCharacter();
};