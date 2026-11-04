#include "WeaponQuality.h"

#include <iostream>

WeaponQuality ChooseWeaponQuality()
{
	int weaponChoice = 0;

	while (true)
	{
		std::cout << "\nВыберите качество оружия:\n";
		std::cout << "1 - Обычное\n";
		std::cout << "2 - Необычное\n";
		std::cout << "3 - Редкое\n";
		std::cout << "4 - Эпическое\n";
		std::cout << "5 - Легендарное\n";

		std::cout << ">> ";
		std::cin >> weaponChoice;

		if (weaponChoice < 1 || weaponChoice > 5)
		{
			std::cout << "Такого качества оружия нет!\n";
			continue;
		}

		return static_cast<WeaponQuality>(weaponChoice);
	}
}


void ShowWeaponQualityInfo(WeaponQuality quality)
{
	switch (quality)
	{
	case WeaponQuality::Common:
		std::cout
			<< "Обычное оружие. Без дополнительных бонусов.\n";
		break;

	case WeaponQuality::Uncommon:
		std::cout
			<< "Необычное оружие. Небольшой бонус к характеристикам.\n";
		break;

	case WeaponQuality::Rare:
		std::cout
			<< "Редкое оружие. Хороший бонус к урону.\n";
		break;

	case WeaponQuality::Epic:
		std::cout
			<< "Эпическое оружие. Очень мощный предмет.\n";
		break;

	case WeaponQuality::Legendary:
		std::cout
			<< "Легендарное оружие! Максимальные бонусы.\n";
		break;
	}
}