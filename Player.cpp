#include "Player.h"
#include "CharacterFactory.h"
#include <utility>

using namespace std;

bool Player::Create(PlayerClass playerClass)
{
	currentCharacter = CharacterFactory::CreateCharacter(playerClass);
	
	if (currentCharacter == nullptr)
		return false;
	
	currentCharacter->Create();

	return true;
}

NPC* Player::GetCharacter()
{
	return currentCharacter.get();
}