class Item
{
	int itemID = NULL;
	std::string name = "";
	std::string prefix = "";
	std::string suffix = "";
	int price = NULL;
	int quality = NULL;
	int level = NULL;
	Stats * stats = nullptr;
public:
	Item();
	Item(int stats, int id);
	~Item();
	void setID();
	void setStats(int * values);
	void showStats();
	virtual void showDamage();
	int getItemID();
};

