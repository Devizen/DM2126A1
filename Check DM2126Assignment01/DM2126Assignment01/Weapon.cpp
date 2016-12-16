#include "Weapon.h"

Weapon::Weapon(const string& name, const int& durability, const int& damage) : Item(name, durability), kAttackDmg(damage)
{

}

Weapon::~Weapon()
{

}

const int Weapon::getAttackDmg()
{
    if (durability_ <= 0)
    {
        return 0;
    }
    else
    {
        return kAttackDmg;
    }
}

void Weapon::receiveDamage(const int& damage)
{
    durability_ -= (damage / 2);
}