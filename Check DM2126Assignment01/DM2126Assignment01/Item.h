#ifndef ITEM_H
#define ITEM_H

#include "GameObject.h"

class Item : public GameObject
{
public:
    Item(const string& name, const int& durability);
	virtual ~Item() = 0;
	virtual void receiveDamage(const int&);
	virtual const int getDurability();


protected:
	int durability_;

//private:
//	int count;
};

#endif