#include "Player.h"

#include <utility>

using namespace std;

void Player::Create(unique_ptr <NPC> player)
{
	currentCharacter = move(player);
	currentCharacter->Create();
}

NPC* Player::GetCharacter()
{
	return currentCharacter.get();
}