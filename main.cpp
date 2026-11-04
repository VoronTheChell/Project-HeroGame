#include <iostream>
#include <windows.h>
#include <memory>
#include <vector>

#include "GameState.h"
#include "PlayerClass.h"
#include "WeaponQuality.h"

#include "NPC.h"
#include "Player.h"

#include "Warrior.h"
#include "Wizard.h"
#include "Paladin.h"

#include "Evil.h"

using namespace std;

// Game v0.0.6.9-a - 04.11.2026

int main()
{
	//setlocale(LC_ALL, "Rus");
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);

	Player player;

	GameState state = GameState::CharacterCreation;

	while (state != GameState::Exit)
	{
		switch (state)
		{
			case GameState::CharacterCreation:
			{
				// TODO: На будующее расписать интересный текст с таймером.
				cout << "Выбор персонажа:" << endl;
				cout << "\t1 - Войн\n\t2 - Волшебник\n\t3 - паладин" << endl;
				short choise = 0;
				cout << ">> ", cin >> choise;

				PlayerClass playerClass = static_cast<PlayerClass>(choise);
				
				if (player.Create(playerClass))
				{
					// Выбор качества оружия (DEBUG)
					WeaponQuality quality = ChooseWeaponQuality();

					ShowWeaponQualityInfo(quality);

					cout << "Числовое значение качества: "
						<< static_cast<int>(quality)
						<< endl;

					state = GameState::MainMenu;
				}

				else
				{
					cout << "Таких героев нет,тебя не звали!\n";
					state = GameState::MainMenu;
				}
				
			}

			case GameState::MainMenu:
			{
				cout << "\n===== Главное меню =====\n";

				cout << "1 - Сюжет\n";
				cout << "2 - Характеристики\n";
				cout << "3 - Создать нового персонажа (DEBUG)\n";
				cout << "4 - Выход\n";

				short choise = 0;

				cout << ">> ";
				cin >> choise;
				switch (choise)
				{
					case 1:
						state = GameState::Story;
						break;

					case 2:
						state = GameState::CharacterInfo;
						break;
					
					case 3:
						state = GameState::CharacterCreation;
						break;

					case 4:
						state = GameState::Exit;
						break;

					default:
						cout << "Такого пункта нет!\n";
						break;
				}
				break;
			}

			case GameState::Story:
			{
				cout << "\nДо героя дошли слухи "
					<< "о пропавшем караване...\n";
				state = GameState::MainMenu;
				break;
			}

			case GameState::CharacterInfo:
			{
				NPC* character = player.GetCharacter();
				if (character != nullptr)
				{
					cout << endl;
					character->GetInfo();
				}
				state = GameState::MainMenu;
				break;
			}

			case GameState::Exit:
				break;

			default:
				break;
		}
	}

	//TakeDamage(player.GetCharacter(), 50);

	cout << "\nИгра завершена...\n";

	return 0;
}