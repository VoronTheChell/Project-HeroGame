#pragma once
#include <string>

class NPC {
protected:
	std::string name{ "name" };
	std::string className{ "NPC" };

	unsigned int damage{ 2 };
	unsigned int health{ 10 };
	unsigned int armor{ 5 };

	short lvl = 1;

	virtual void PrepareCharacter() = 0;
	virtual void ShowEquipment() = 0;

public:

	void Create();

	virtual void GetInfo();

	friend void TakeDamage(NPC* npc, unsigned int damage);

	virtual ~NPC() = default;
};