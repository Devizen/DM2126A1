#ifndef WEAPON_H
#define WEAPON_H
#include "Item.h"

class Weapon : public Item
{
public:
	Weapon(const string& name, const int& durability, const int& damage);
	~Weapon();
    //Print attack damage.
	const int getAttackDmg();

    //Damage to Weapon durability.
    virtual void receiveDamage(const int& damage);

protected:
    //Weapon Damage.
	const int kAttackDmg = 0;

private:

};

#endif