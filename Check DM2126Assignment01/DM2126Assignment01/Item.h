#ifndef ITEM_H
#define ITEM_H

#include "GameObject.h"

class Item : public GameObject
{
public:
    Item(const string& name, const int& durability);
	virtual ~Item() = 0;
	virtual void receiveDamage(const int& damage) = 0;
	virtual const int getDurability();


protected:
    //Durability of Outfit and Weapon.
	int durability_;

//private:
//	int count;
};

#endif