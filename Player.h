#pragma once

#include <memory>

#include "NPC.h"

class Player
{
private:
	std::unique_ptr<NPC> currentCharacter{ nullptr };

public:
	void Create(std::unique_ptr <NPC> player);
	NPC* GetCharacter();
};