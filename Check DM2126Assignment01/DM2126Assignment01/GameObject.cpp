#include"GameObject.h"

int GameObject::count_ = 0;

GameObject::GameObject(const string& name) : kName(name)
{
    count_++;
}

GameObject::~GameObject()
{

}

string GameObject::getName(void)
{
    return this->kName;
}

int GameObject::getCount()
{
    return count_;
}