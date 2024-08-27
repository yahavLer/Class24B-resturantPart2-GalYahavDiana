#ifndef __INGREDIENT_H
#define __INGREDIENT_H

#include <iostream>
using namespace std;
class Ingredient
{
public:
	enum eSection { HERBS, DAIRY, MEAT, FISH, VEGETABLES };
	
	Ingredient();
	Ingredient(std::string& name, eSection section, int quantity);


	inline string getName() const { return const_cast<char*>(name); }
	inline int getQuantity() const { return quantityIng;  }
    inline eSection getSection() const { return section; }

	bool setName(const std::string& name);
	bool setSection(eSection section);
	bool setQuantity(int quantity);
	void print();

private:
	char name[20];
	eSection section;
	int quantityIng;
};
#endif// __INGREDIENT_H