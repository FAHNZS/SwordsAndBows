#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "Stats.h"
 
Stats::Stats(int value, int id) { //Constructor na autogenerovanie hodnot podla kvality 
	int n = (pow(2, value) / 2);
	if (value == 0) {
		this->strength = rand() % 2;
		this->vitality = rand() % 2;
		this->resistance = rand() % 2;
		this->dexterity = rand() % 2;
		this->intelligence = rand() % 2;
		this->charisma = rand() % 2;
		this->awareness = rand() % 2;
		this->luck = rand() % 2;
	} else {
		this->strength = (rand() % (n + 1)) + n;
		this->vitality = (rand() % (n + 1)) + n;
		this->resistance = (rand() % (n + 1)) + n;
		this->dexterity = (rand() % (n + 1)) + n;
		this->intelligence = (rand() % (n + 1)) + n;
		this->charisma = (rand() % (n + 1)) + n;
		this->awareness = (rand() % (n + 1)) + n;
		this->luck = (rand() % (n + 1)) + n;
	}
};

Stats::Stats(int *values) { //Constructor na vytvorenie objektu zo save-u
	this->strength = values[0];
	this->vitality = values[1];
	this->resistance= values[2];
	this->dexterity = values[3];
	this->intelligence= values[4];
	this->charisma = values[5];
	this->awareness= values[6];
	this->luck = values[7];
};

Stats::Stats(Stats *stats) { //Constructor na kopirovanie statov
	this->strength = stats->strength;
	this->vitality = stats->vitality;
	this->resistance = stats->resistance;
	this->dexterity = stats->dexterity;
	this->intelligence = stats->intelligence;
	this->charisma = stats->charisma;
	this->awareness = stats->awareness;
	this->luck = stats->luck;
};

void Stats::setAttributes(int * arr) { //nacitanie so save-u

};

void Stats::showAttributes() { //vypis atributov
	//system("Color 1A");
	std::cout
		<< "--------------------------------" << std::endl
		<< " Str:" << this->strength << std::endl
		<< " Vit:" << this->vitality << std::endl
		<< " Res:" << this->resistance << std::endl
		<< " Dex:" << this->dexterity << std::endl
		<< " Int:" << this->intelligence << std::endl
		<< " Cha:" << this->charisma << std::endl
		<< " Awa:" << this->awareness << std::endl
		<< " Luc:" << this->luck << std::endl
		<< "--------------------------------" << std::endl
		<< std::endl;
	//system("Color F0");
};

int Stats::getTotalStats() {
	return (
		this->strength +
		this->vitality +
		this->resistance +
		this->dexterity +
		this->intelligence +
		this->charisma +
		this->awareness +
		this->luck);
};

int Stats::getStrengthStat() {
	return (this->strength);
}

int Stats::getVitalityStat() {
	return (this->vitality);
}

int Stats::getResistanceStat() {
	return (this->resistance);
}

int Stats::getDexterityStat() {
	return (this->dexterity);
}

int Stats::getIntelligenceStat() {
	return (this->intelligence);
}

int Stats::getCharismaStat() {
	return (this->charisma);
}

int Stats::getAwarenessStat() {
	return (this->awareness);
}

int Stats::getLuckStat() {
	return (this->luck);
}