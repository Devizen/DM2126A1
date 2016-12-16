#include "Dweller.h"

Dweller::Dweller(const string& name, const int& special) : GameObject(name)
{
    this->SPECIAL_ = special;
}

Dweller::~Dweller()
{

}

const int Dweller::getSPECIAL()
{
    if (!outfit_)
    {
        return SPECIAL_;
    }
    else
    {
        int d[7] = {};
        int divide[7] = { 1000000, 100000, 10000, 1000, 100, 10, 1 };

        for (int i = 0; i < 7; i++)
        {
            d[i] = { ((this->SPECIAL_ / divide[i]) % 10) + ((outfit_->getSPECIAL() / divide[i]) % 10) };
            if (d[i] > 9)
            {
                d[i] = 9;
            }
        }

        SPECIAL_ = 0;

        for (int i = 0; i < 7; i++)
        {
            SPECIAL_ += (d[i] * divide[i]);
        }

        return SPECIAL_;
    }
}

const int Dweller::getCurrentHealth()
{
    return health_;
}

const int Dweller::getCurrentRadDamage()
{
    return radiation_;
}

const int Dweller::getAttackDmg()
{
    if (!weapon_)
    {
        return 1;
    }
    else
    {
        return weapon_->getAttackDmg();
    }
}

void Dweller::setPosition(const Vec2D& name)
{
    position_.x = name.x;
    position_.y = name.y;
}

const Vec2D Dweller::getPosition()
{
    return Vec2D(position_.x, position_.y);
}

void Dweller::receiveHealthDamage(const int& damage)
{
    this->health_ -= damage;
}

void Dweller::receiveRadDamage(const int& rad)
{
    this->health_ -= rad;
}

void Dweller::receiveEquipmentDamage(const int&)
{

}

void Dweller::addStimpak(const int&)
{
    stimpak_++;
}

void Dweller::addRadAway(const int&)
{
    radaway_++;
}

void Dweller::useStimpak()
{

}

void Dweller::useRadAway()
{

}

Outfit* Dweller::assignOutfit(Outfit* name)
{
    return outfit_ = name;
}

Weapon* Dweller::assignWeapon(Weapon* name)
{
    return weapon_ = name;
}

bool Dweller::isDead()
{
    if (this->health_ <= 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}