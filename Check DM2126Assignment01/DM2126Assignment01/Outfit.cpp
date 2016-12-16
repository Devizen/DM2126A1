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