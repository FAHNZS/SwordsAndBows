class Stats
{
	int strength;
	int vitality;
	int resistance;
	int dexterity;
	int intelligence;
	int charisma;
	int awareness;
	int luck;
public:
	Stats(int value, int id);
	Stats(int *values);
	Stats(Stats *stats);
	void setAttributes(int * arr);
	void showAttributes();
	int getTotalStats();
	int getStrengthStat();
	int getVitalityStat();
	int getResistanceStat();
	int getDexterityStat();
	int getIntelligenceStat();
	int getCharismaStat();
	int getAwarenessStat();
	int getLuckStat();
};
