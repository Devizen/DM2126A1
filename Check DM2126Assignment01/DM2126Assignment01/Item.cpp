#include "Item.h"

Item::Item(const string& name, const int& durability) : GameObject(name)
{
    this->durability_ = durability;
}

Item::~Item()
{

}

void Item::receiveDamage(const int& damage)
{
    durability_ -= damage;
}

const int Item::getDurability()
{
    return durability_;
}

