#include"NPC.h"
#include <iostream>
#include <windows.h>

using namespace std;

static void SetColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void NPC::Create()
{
	SetColor(11);
	cout << "(i) Инфо: ";
	SetColor(7);

	cout << "Вы создали " << className << "!\n";
	cout << "Введите имя вашего персонажа: ";
	cin >> name;

	PrepareCharacter();

	GetInfo();
	ShowEquipment();
}

void NPC::GetInfo()
{
	cout << "Имя героя: " << name << endl;
	cout << "Класс: " << className << endl;
	cout << "Уровень героя: " << lvl << endl;
	cout << "Здоровье: " << health << endl;
	cout << "Броня: " << armor << endl;
	cout << "Урон: " << damage << endl;
}

void TakeDamage(NPC* npc, unsigned int damage)
{
	if (damage >= npc->health)
		npc->health = 0;
	else
		npc->health -= damage;

	cout << "Вы получили " << damage << " единиц урона!\n";
	cout << "Ваше текущее здоровье: " << npc->health << " HP\n";
}