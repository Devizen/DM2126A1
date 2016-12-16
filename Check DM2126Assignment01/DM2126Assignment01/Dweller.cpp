#include "Dweller.h"


Dweller::Dweller(const string& name, const int& special) : GameObject(name), SPECIAL_(special)
{

}

Dweller::~Dweller()
{

}

const int Dweller::getSPECIAL()
{
    int d[7] = {};
    static int dOverNine[7] = {};
    static int o[7] = {};
    int divide[7] = { 1000000, 100000, 10000, 1000, 100, 10, 1 };


    if ((health_ - radiation_) <= 0)
    {
        return 0000000;
    }

    else if (!outfit_)
    {
        return SPECIAL_;
    }

    else if (outfit_->getDurability() <= 0)
    {
        for (int i = 0; i < 7; i++)
        {
            d[i] = { dOverNine[i] - o[i] };
        }

        SPECIAL_ = 0;

        for (int i = 0; i < 7; i++)
        {
            SPECIAL_ += (d[i] * divide[i]);
        }

        return SPECIAL_;
    }

    else
    {
        for (int i = 0; i < 7; i++)
        {
            //Get the single digit of Dweller Special and deduct away the single digit of Outfit Special.
            d[i] = { ((this->SPECIAL_ / divide[i]) % 10) + ((outfit_->getSPECIAL() / divide[i]) % 10) };

            //Backup Outfit Special
            o[i] = ((outfit_->getSPECIAL() / divide[i]) % 10);

            //Backup Dweller Special that exceeds 9
            dOverNine[i] = { ((this->SPECIAL_ / divide[i]) % 10) + ((outfit_->getSPECIAL() / divide[i]) % 10) };

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
    return (health_ - radiation_);
}

const int Dweller::getCurrentRadDamage()
{
    return radiation_;
}

const int Dweller::getAttackDmg()
{
    //No damage if Dweller is dead.
    if ((health_ - radiation_) <= 0)
    {
        return 0;
    }

    //Return 1 damage if there are no weapon equipped.
    else if (!weapon_ || weapon_->getDurability() <= 0)
    {
        return 1;
    }
    else
    //Return weapon damage.
    {
        return weapon_->getAttackDmg();
    }
}

void Dweller::setPosition(const Vec2D& name)
{
    //Assign x and y to position.
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

    if ((health_ - radiation_) <= 0)
    {
        health_ = 0;
        radiation_ = 0;
    }
}

void Dweller::receiveRadDamage(const int& damage)
{

    this->radiation_ += damage;

    if (radiation_ > 100)
    {
        radiation_ = 100;
    }

    if ((health_ - radiation_) <= 0)
    {
        health_ = 0;
        radiation_ = 0;
    }
}

void Dweller::receiveEquipmentDamage(const int& damage)
{
    //Only deduct durability if there are equipments.
    if (outfit_)
    {
        outfit_->receiveDamage(damage);
    }

    if (weapon_)
    {
        weapon_->receiveDamage(damage);
    }
}

void Dweller::addStimpak(const int& stimpak)
{
    stimpak_++;
}

void Dweller::addRadAway(const int& radAway)
{
    radaway_++;
}

void Dweller::useStimpak()
{
    if (health_ < 100 && stimpak_ != 0)
    {
        stimpak_--;
        health_ += 20;
    }
}

void Dweller::useRadAway()
{
    if (radaway_ != 0 && radiation_ > 0)
    {
        radaway_--;
        radiation_ -= 10;
        if (radiation_ < 0)
        {
            radiation_ = 0;
        }
    }
}

Outfit* Dweller::assignOutfit(Outfit* name)
{
    //Assign outfit_ to Outfit object.
    return outfit_ = name;
}

Weapon* Dweller::assignWeapon(Weapon* name)
{
    //Assign weapon_ to Weapon object.
    return weapon_ = name;
}

bool Dweller::isDead()
{
    if ((this->health_ - this->radiation_) <= 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}