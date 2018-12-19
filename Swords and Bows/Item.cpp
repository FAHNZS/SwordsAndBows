#include <string>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include "Stats.h"
#include "Item.h"
#include "Definitions.h"



Item::Item() {
};

Item::Item(int stats, int id) {
	std::cout << "ITEM NACITANY" << std::endl;
	this->itemID = id;
	this->stats = new Stats(stats, id);


	//zmazat (len pre weapony)

	this->name = meleeWeaponTypeList.at(rand() % meleeWeaponTypeList.size());
	this->prefix = itemPrefixList.at(rand() % itemPrefixList.size());
	
	std::cout << this->prefix << " " << this->name << std::endl << std::endl;
	this->stats->showAttributes();
	
};

Item::~Item() {
	std::cout << " Item destroyed" << std::endl << std::endl;
}

void Item::setID() {
	this->itemID = rand() % 100;
	int i=0;
	do {
		i++;
	} while (i < 3000);
}

void Item::setStats(int * values) {
};

void Item::showStats() {
	std::cout << "-----------------" << std::endl << stats->getTotalStats() << std::endl << "-----------------" << std::endl;
};

void Item::showDamage() {
};

int Item::getItemID() {
	return itemID;
}
