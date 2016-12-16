#ifndef WEAPON_H
#define WEAPON_H
#include "Item.h"

class Weapon : public Item
{
public:
	Weapon(const string& name, const int& durability, const int& damage);
	~Weapon();
	const int getAttackDmg();

protected:
	const int kAttackDmg = 0;

private:

};

#endif