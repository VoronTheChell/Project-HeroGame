#include <iostream>
#include <windows.h>
#include <memory>
#include <vector>

#include "NPC.h"
#include "Warrior.h"
#include "Wizard.h"
#include "Paladin.h"
#include "Evil.h"

using namespace std;

// Game v0.0.6.5 - 16.10.2026

class Player
{
	private:
		unique_ptr<NPC> currentCharacter{nullptr};
	
	public:
		void Create(unique_ptr <NPC> player)
		{
			currentCharacter = move(player);
			currentCharacter->Create();
		}

		NPC* GetCharacter()
		{
			return currentCharacter.get();
		}
};

int main()
{
	//setlocale(LC_ALL, "Rus");
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);

	Player player;

	// TODO: На будующее расписать интересный текст с таймером.
	cout << "Выбор персонажа:" << endl;
	cout << "\t1 - Войн\n\t2 - Волшебник\n\t3 - паладин" << endl;
	short choise = 0;
	cout << ">> ", cin >> choise;

	switch (choise)
	{
	case 1:
		player.Create(make_unique<Warrior>());
		break;

	case 2:
		player.Create(make_unique<Wizard>());
		break;

	case 3:
		player.Create(make_unique<Paladin>());
		break;

	default:
		cout << "Таких героев нет,тебя не звали!\n";
		return 0;
	}

	TakeDamage(player.GetCharacter(), 5);

	return 0;
}