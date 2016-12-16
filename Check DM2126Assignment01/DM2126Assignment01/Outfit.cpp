#include "Outfit.h"

Outfit::Outfit(const string& name, const int& durability, const int& special) : Item(name, durability), kSPECIAL(special)
{

}

Outfit::~Outfit()
{

}

const int Outfit::getSPECIAL()
{
    if (Outfit::Item::durability_ <= 0)
    {
        return 0;
    }
    else
    {
        return kSPECIAL;
    }
}


void Outfit::receiveDamage(const int& damage)
{
    durability_ -= damage;

    if (durability_ < 0)
    {
        durability_ = 0;
    }
}