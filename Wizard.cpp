#include "Wizard.h"

#include <iostream>

using namespace std;

Wizard::Wizard()
{
	Spell spell;

	spell.damage = 2;
	spell.name = "Вспышка";

	spells.push_back(spell);
}

void Wizard::PrepareCharacter()
{
	Spell spell;

	spell.damage = 2;
	spell.name = "Вспышка";

	spells.push_back(spell);
}

void Wizard::ShowEquipment()
{
	LearnSpell();
}

void Wizard::GetInfo()
{
	NPC::GetInfo();
	cout << "Интеллект: " << intellect << endl;
}

void Wizard::LearnSpell()
{
	cout << name << " изучил заклинание "
		<< spells[0].name << endl;

	cout << "Добавка к урону: "
		<< spells[0].damage << endl;
}