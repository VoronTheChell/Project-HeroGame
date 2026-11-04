#pragma once

enum class WeaponQuality
{
	Common = 1,
	Uncommon,
	Rare,
	Epic,
	Legendary
};

WeaponQuality ChooseWeaponQuality();

void ShowWeaponQualityInfo(WeaponQuality quality);