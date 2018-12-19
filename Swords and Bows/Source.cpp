#include <iostream>
#include <string>
#include <math.h>
#include <map>
#include <new>
#include <time.h>
#include <vector>
#include "Stats.h"
#include "Item.h"

class Entity {
	int entityID;
	int entityType; //0 = player, 1 = monster, 2 = NPC, 3= merchant
	int level;
	std::string name;
	Stats * mainStats;
	Stats * finalStats;


public: 
	Entity(std::string name, int entityID, int entityType, int level) {
		this->level = level;
		this->name = name;
		this->entityID = entityID;
	}

	int getLevel() {
		return level;
	}

	void setLevel(int value) {
		this->level = value; 
	}

	void increaseLevel() {
		level++;
	} 

	std::string getName() {
		return name;
	}

	void setFinalStats() {

	};
};

class Inventory {
	std::vector<Item*> inventory;
	int size;
public:
	~Inventory() {
		std::cout << "Inventory destroyed" << std::endl << std::endl;
	}

 	Inventory(int size) {
		this->size = size;
		for (int i = 0; i < size; i++) {
			inventory.push_back(nullptr);
		}
	}
	void addItemAt(int pos,Item *item) {
		if (inventory.at(pos) != nullptr) {
			Item * tmp = inventory.at(pos);
			addItem(tmp);
		}
		inventory.at(pos) = item;
	};

	void addItem(Item* item) {
		inventory.at(getPos()) = item;
	};

	void deleteItem(int pos) {
		inventory.at(pos) = nullptr;
	};

	void clearInventory() {
		int max = inventory.size();
		for (int i = 0; i < max; i++)
		{
			inventory.at(i) = nullptr;
		}
	};

	int getPos() {
		int max = inventory.size();
		for (int i = 0; i < max; i++)
		{
			if (inventory.at(i) == nullptr)
			{
				return i;
			}
		}
		return NULL;
	};

	void showInventory() {
		for (int i = 0; i < inventory.size(); i++) {
			if (inventory.at(i) == nullptr) {
				std::cout << "empty slot" << "--------------------" << std::endl << std::endl;
			}
			else {
				std::cout << inventory.at(i)->getItemID() << "--------------------" << std::endl << std::endl;
			}		
		}
	}
};

class Weapon : public Item {
	int damage;
public:
	Weapon(int value, int id) : Item(value, id) {
		std::cout << "Weapon s ID: "<< id << " nacitany" << std::endl;
	};
	void showItem() {
		showStats();
	};
	void showDamage() {
		std::cout << "damage: " << this->damage << std::endl;
	}
};

class MeleeWeapon : public Weapon {
	int swingSpeed;
	MeleeWeapon(int value, int id) : Weapon(value, id) {
	}
};

class LongRangeWeapon : public Weapon {
	int range;
	int firespeed;
public:
	LongRangeWeapon(int value, int id) : Weapon(value, id) {

	};

};

class Warrior : public Entity {
	int maxHealth = NULL;
	int health = NULL;
	int experience = NULL;
	int maxExp = NULL;
	Inventory * inventory = nullptr;
	Item * leftHand = nullptr;
	Item * rightHand = nullptr;
	
public: 
	Warrior(std::string name, int entityID, int level) : Entity(name, entityID ,0 ,level) {
		maxExp = (int)10 * pow(1.2, getLevel()-1);
		this->inventory = new Inventory(10);
	}

	void addExperience(int value) { //ziskanie exp po zabiti alebo spraveni 
		if (value > 0) {
			this->experience += value;
			while (experience >= maxExp) {
				lvlUP();
			}
		}
	}

	void lvlUP() { //zvys level a zmen expy
		experience -= maxExp;
		increaseLevel();
		maxExp = (int)10 * pow(1.5, getLevel()-1);
	}

	void addHealth(int value) {
		if (value > 0) {
			this->health += value;
			if (this->health > maxHealth) {
				this->health = maxHealth;
			}
		}
	}

	void removeHealth(int value) {
		if (value > 0) {
			this->health -= value;
			if (this->health < 1) {
				std::cout << "Warrior is dead!!!\n" << std::endl;
			}
		}
	}

	void showAttributes() {
		std::cout
			<< "meno: " << getName() << std::endl
			<< "level: " << getLevel() << std::endl
			<< "maxXP: " << maxExp << std::endl
			<< "XP: " << experience << std::endl << std::endl;
	}

	void addRightHand(Item * item) {
		this->rightHand = item;
	}

	void showRightHand() {
		this->rightHand->showDamage();
	}

};

class Monster : public Entity{
	int maxHealth = NULL;
	int health = NULL;
	int damage = NULL;
public:
	Monster(std::string name, int entityID, int level) : Entity(name, entityID, 0, level){
		maxHealth = getLevel() * 30 + rand() % 30;
		damage = getLevel() + rand() % 10;
		health = maxHealth;
	};
	void getMaxHealth() {
		std::cout << "MaxHealt: " << maxHealth << std::endl << std::endl;
	};

	void getHealth() {
		std::cout << "MaxHealt: " << health << std::endl << std::endl;
	};

	void getDamage() {
		std::cout << "MaxHealt: " << damage << std::endl << std::endl;
	};
	
	void getStats() {
		getMaxHealth();
		getHealth();
		getDamage();
	};

	void removeHealth(int value) {
		this->health -= value;
		if (health <= 0) {
			std::cout << "Monster died" << std::endl << std::endl;
		}
	};
};

class NPC {

};

class Merchant {

};

class Armor : public Item {
	int armor;
public: 
}; //vsetky kusy armoru

class Gear : public Item  { //prstene, opasok, nahrdelnik

};

class Ring : public Gear { 

};

class Necklace : public Gear {

};

class Belt : public Gear {

};

int main() {
	srand(time(NULL));
	
	int entityID = 0;
	int itemID = 0;

	Weapon * sword = new Weapon(0, itemID++);

	sword->showStats();

	Weapon * sword1 = new Weapon(3, itemID++);
	
	sword1->showStats();

	Weapon * sword2 = new Weapon(6, itemID++);

	sword2->showStats();

	Weapon * sword3 = new Weapon(3, itemID++);
	Weapon * sword4 = new Weapon(3, itemID++);
	Weapon * sword5 = new Weapon(3, itemID++);
	Weapon * sword6 = new Weapon(3, itemID++);

	std::cout << std::endl << std::endl;

	Warrior * warrior1 = new Warrior("TestSubject", 1, 1);

	/*for (int i = 1; i < 15; i++) {

		std::cout << "pridavam " << i*10 << std::endl;
		warrior1->addExperience(10*i);
		warrior1->showAttributes();

	} */
	std::cout << std::endl << std::endl;
	warrior1->addRightHand(sword1);
	warrior1->showRightHand();
	Inventory * inv = new Inventory(5);
	inv->addItem(sword);
	inv->addItem(sword1);
	inv->addItem(sword2);
	inv->showInventory();
	inv->addItem(sword3);
	inv->addItem(sword4);
	inv->addItem(sword5);
	inv->showInventory();

	Monster * testingObject1 = new Monster("test1", 0, entityID++);
	Monster * testingObject2 = new Monster("test2", 0, entityID++);
	Monster * testingObject3 = new Monster("test3", 0, entityID++);
	Monster * testingObject4 = new Monster("test4", 0, entityID++);
	Warrior * testWarrior = new Warrior("warrior1", 1, entityID++);
	Monster * testingObject5 = new Monster("test5", 0, entityID++);
	return 0;
}