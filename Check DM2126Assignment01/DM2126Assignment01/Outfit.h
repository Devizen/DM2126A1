#ifndef OUTFIT_H
#define OUTFIT_H
#include "Item.h"


class Outfit : public Item
{
public:
    Outfit(const string& name, const int& durability, const int& special);
	~Outfit();
    //Print kSPECIAL value.
	const int getSPECIAL();

    //Damage to Outfit Durability.
    virtual void receiveDamage(const int& damage);

protected:
    //SPECIAL attributes for Dweller.
	const int kSPECIAL;

private:
};

#endif