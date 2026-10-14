#include <iostream>
#include <windows.h>
#include <memory>
#include <vector>

using namespace std;

static void SetColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// Game v0.0.5.1

// Домашнее Задание: сделать диаграмму которую ты пропустил ДУРЕНЬ! (дедлайн: с 08.10 по 11.10 - НЕ ВКЛЮЧИТЕЛЬНО)

// NPC является абстрактным классом, поскольку содержит чисто виртуальные функции.

class NPC
{
protected:
	string name{ "name_npc" };
	string className{ "NPC" };

	unsigned int damage{ 2 };
	unsigned int health{ 10 };
	unsigned int armor{ 5 };

	short lvl = 1;

	virtual void PrepareCharacter() = 0;
	virtual void ShowEquipment() = 0;

public:

	void Create()
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

	virtual void GetInfo()
	{
		cout << "Имя героя: " << name << endl;
		cout << "Класс: " << className << endl;
		cout << "Уровень героя: " << lvl << endl;
		cout << "Здоровье: " << health << endl;
		cout << "Броня: " << armor << endl;
		cout << "Урон: " << damage << endl;
	}

	friend void TakeDamage(NPC* npc, unsigned int damage);

	virtual ~NPC() = default;
};

struct Weapon
{
	string name{ "weapon" };
	unsigned int damage{ 1 };
};

class Warrior : virtual public NPC
{
	protected:
		short strength{ 21 };
		vector<Weapon> weapons;

		void PrepareCharacter() override
		{
			Weapon weapon;

			weapon.damage = 1;
			weapon.name = "Кулаки";

			weapons.push_back(weapon);
		}

		void ShowEquipment() override
		{
			GetWeapon();
		}

	public:

		Warrior()
		{
			className = "воина";

			damage = 20;
			health = 30;
			armor = 15;
		}

		void GetInfo() override
		{
			NPC::GetInfo();
			cout << "Сила: " << strength << endl;
		}

		void GetWeapon()
		{
			cout << name << " взял в руки оружие: "
				<< weapons[0].name << endl;

			cout << "Добавка к урону: "
				<< weapons[0].damage << endl;
		}
};

struct Spell
{
	string name{ "spell" };
	unsigned int damage{ 1 };
};

class Wizard : virtual public NPC
{
	protected:
		short intellect{ 29 };
		vector<Spell> spells;

		void PrepareCharacter() override
		{
			Spell spell;

			spell.damage = 2;
			spell.name = "Вспышка";

			spells.push_back(spell);
		}

		void ShowEquipment() override
		{
			LearnSpell();
		}

	public:

		Wizard()
		{
			className = "волшебника";

			damage = 27;
			health = 21;
			armor = 10;
		}

		void GetInfo() override
		{
			NPC::GetInfo();
			cout << "Интеллект: " << intellect << endl;
		}

		void LearnSpell()
		{
			cout << name << " изучил заклинание "
				<< spells[0].name << endl;

			cout << "Добавка к урону: "
				<< spells[0].damage << endl;
		}
};

class Evil : public NPC
{
	protected:
		// На будующее
		void PrepareCharacter() override
		{}

		void ShowEquipment() override
		{}

	public:
		Evil()
		{
			name = "evil_npc";
			damage = 5;
			armor = 3;
		}

		// ВНИМАНИЕ: ДАННЫЙ ПРИМЕР ИСПОЛЬЗУЕТСЯ В ОБРОЗОВАТЕЛЬНЫХ ЦЕЛЯХ, НЕ ИСПОЛЬЗОВАТЬ НА ПРАКТИКЕ!

		Evil(string name) // Делегирование конструтора (т.е. вызывается в начале базовых)
		{
			this->name = name;
		}

		Evil(string name, unsigned int damage) : Evil(name)
		{
			this->damage = damage;
		}

		Evil(string name, unsigned int damage, unsigned int health) : Evil(name, damage)
		{
			this->health = health;
		}

		Evil(string name, unsigned int damage, unsigned int health, unsigned int armor) : Evil(name, damage, health)
		{
			this->armor = armor;
		}
};

// Множественное наследие
class Paladin : public Warrior, public Wizard
{
protected:

	void PrepareCharacter() override
	{
		Weapon weapon;
		weapon.damage = 5;
		weapon.name = "Меч новичка";

		weapons.push_back(weapon);


		Spell spell;
		spell.damage = 2;
		spell.name = "Божий шок";

		spells.push_back(spell);
	}

	void ShowEquipment() override
	{
		GetWeapon();
		LearnSpell();
	}

public:

	Paladin()
	{
		className = "паладина";

		intellect = 25;
		strength = 19;

		health = 25;
		damage = 25;
		armor = 20;
	}

	void GetInfo() override
	{
		NPC::GetInfo();

		cout << "Сила: " << strength << endl;
		cout << "Интеллект: " << intellect << endl;
	}

	~Paladin()
	{
		cout << name
			<< " увидел свет в конце тоннеля..."
			<< " но оказалось, это экран загрузки."
			<< endl;
	}
};


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

// Дружественный класс Хранит или принимает аргументом экземпляр другого класса
// благодаря этому может использовать его поля и методы (даже защищенные);

// Дружественная функ. дает доступ к полям, даже если они private функции,
// обязателен прототип с ключевым словом friend внутри самого класа и
// не является частью самого класса.
void TakeDamage(NPC* npc, unsigned int damage)
{
	if (damage >= npc->health)
		npc->health = 0;
	else
		npc->health -= damage;

	cout << "Вы получили " << damage << " единиц урона!\n";
	cout << "Ваше текущее здоровье: " << npc->health << " HP\n";
}

int main()
{
	//setlocale(LC_ALL, "Rus");
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);

	Player player;

	// TODO: На будующее распмсать интересный текст с таймером.
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