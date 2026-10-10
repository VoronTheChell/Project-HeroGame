#include <iostream>
#include <windows.h>
#include <vector>

using namespace std;

static void SetColor(int color) // От себя добавление ХЫ
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

// Game v0.0.5.1

// Домашнее Задание: сделать диаграмму которую ты пропустил ДУРЕНЬ! (дедлайн: с 08.10 по 11.10 - НЕ ВКЛЮЧИТЕЛЬНО)
// И незабудь сделать все TODO которые ты здесь пометил! (дедлайн: с 08.10 по 11.10 - НЕ ВКЛЮЧИТЕЛЬНО)

// TODO: Реализовать проверку условия, так что бы класс именно выбирался а не тупо сносили Create() в каждом из классе
class NPC
{
protected:
	string name{ "name_npc" };
	unsigned int damage{ 2 };
	unsigned int health{ 10 };
	unsigned int armor{ 5 };
	short lvl = 1;

private:
	bool isEnemy = true;

public:
	// TODO: Подправь (надо продумать данные механики и доработать)
	unsigned int GetDamage() { return damage; };
	unsigned int GetHealth() { return health; };
	void SetHealth(unsigned int health) { this->health = health; };

	// Создать NPC нельзя, => весь класс - виртуальным!
	virtual void Create()
	{
		/*
		cout << "Вы создали война!\nВведите имя вашего персонажа: ", cin >> name, "\n";

		Weapon weapon;
		weapon.damage = 1;
		weapon.name = "Кулаки";
		weapons.push_back(weapon);

		GetInfo();
		GetWeapon();
		*/
	}

	virtual void GetInfo()
	{
		cout << "Имя героя: " << name << endl;
		cout << "Уровень героя: " << lvl << endl;
		cout << "Здоровье: " << health << endl;
		cout << "Броня: " << armor << endl;
		cout << "Урон: " << damage << endl;

		// cout << "Сила: " << strength << endl;
	}

	// you my friend now ~()`P
	friend void TakeDamage(unique_ptr<NPC> npc, unsigned int damage);

	void LvLUp()
	{
		cout << name << " - получил новый уровень!" << endl;
		lvl++;
		Relaculate();
	}

	void Relaculate()
	{
		damage += (1 + lvl * 0.1);
		health += (1 + lvl * 0.05);
		armor += (1 + lvl * 0.75);
	}
	
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

public:
	// Конструктор по умолчанию
	Warrior()
	{
		damage = 20;
		health = 30;
		armor = 15;
	}

	// Кастомный конструтор
	Warrior(string name, unsigned int lvl)
	{
		this->name = name; // Такой способ задания поля уместен тока для Setter'a
		for (size_t i = 0; i < lvl; i++)
			LvLUp();

		// this->lvl = lvl; // this - он указывает на конкретный экз. класса
	}

	void Create() override
	{
		SetColor(11);
		cout << "(i) Инфо: ";
		SetColor(7);
		cout << "Вы создали война!\nВведите имя вашего персонажа: ", cin >> name, "\n";

		Weapon weapon;
		weapon.damage = 1;
		weapon.name = "Кулаки";
		weapons.push_back(weapon);

		GetInfo();
		GetWeapon();

	}

	void GetInfo()
	{
		NPC::GetInfo();
		cout << "Сила: " << strength << endl;
	}

	void GetWeapon()
	{
		SetColor(11);
		cout << "(i) Инфо: ";
		SetColor(7);
		cout << name << " взял в руки оружие: " << weapons[0].name;
		cout << " добавка к урону = " << weapons[0].damage << endl;
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

public:
	Wizard()
	{
		damage = 27;
		health = 21;
		armor = 10;
	}

	void Create() override
	{
		cout << "Вы создали волшебника!\nВведите имя вашего персонажа: ", cin >> name, "\n";

		Spell spell;
		spell.damage = 2;
		spell.name = "Вспышка";
		spells.push_back(spell);

		GetInfo();
		LearnSpell();
	};

	void GetInfo()
	{
		NPC::GetInfo();
		cout << "Интеллект: " << intellect << endl;
	};

	void LearnSpell()
	{

		cout << name << " изучил заклинание " << spells[0].name;
		cout << " добавка к урону = " << spells[0].damage << endl;
	};
};

class Evil : public NPC
{
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

// TODO: Исправить проблему с спавном Воина и Волшебника в Поладине
// Множественное наследие
class Paladin : public Warrior, public Wizard
{
public:
	Paladin()
	{
		intellect = 25;
		strength = 19;
		health = 25;
		damage = 25;
	}

	void Create() override
	{
		// TODO: Реализовать это в NPC (храните название класса в каком-то поле)
		cout << "Вы создали Паладина!\nВведите имя вашего персонажа: ", cin >> name, "\n";

		Weapon weapon;
		weapon.damage = 5;
		weapon.name = "Мечь новичка";
		weapons.push_back(weapon);

		Spell spell;
		spell.damage = 2;
		spell.name = "Божий шок";
		spells.push_back(spell);

		GetInfo();

		GetWeapon();
		LearnSpell();
	};

	void GetInfo()
	{
		Warrior::GetInfo();
		cout << "Интеллект: " << intellect << endl;
	};

	~Paladin()
	{
		// TODO сделать посмешнее хех
		cout << "Отправился к праотцам..." << endl;
	}
};

// Дружественный класс Хранит или принимает аргументом экземпляр другого класса
// благодаря этому может использовать его поля и методы (даже защищенные);
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

		unique_ptr <NPC> GetCharacter()
		{
			return move(currentCharacter);
		}
};

// Дружественная функ. дает доступ к полям, даже если они private функции,
// обязателен прототип с ключевым словом friend внутри самого класа и
// не является частью самого класса.
void TakeDamage(unique_ptr<NPC> npc, unsigned int damage)
{
	npc->health -= damage;
	cout << "Вы получили " << damage << " едениц урона!\n";
	cout << "Ваше текущее здоровье: " << npc->health << "HP\n";
}

int main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);

	Player player;

	// TODO: На будующее распмсать интересный текст с таймером.
	cout << "Выбор персонажа:" << endl;
	cout << "\t1 - Войн\n\t2 - Волшебник\n\t3 - паладин" << endl;
	short choise = 0;
	cout << ">> ", cin >> choise;

	// TODO: валидация выбора (лучше сунуть в функцию)
	// TODO: поправить за косяком препода хех

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
		break;
	}

	TakeDamage(player.GetCharacter(), 5);

	return 0;
}