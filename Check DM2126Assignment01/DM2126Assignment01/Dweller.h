#ifndef DWELLER_H
#define DWELLER_H
#include "GameObject.h"
#include "Vec2D.h"
#include "Outfit.h"
#include "Weapon.h"

class Dweller : public GameObject
{
public:
	Dweller(const string&, const int&);
	~Dweller();

    //Getters
	const int getSPECIAL();
	const int getCurrentHealth();
	const int getCurrentRadDamage();
    const int getAttackDmg();

    //Positions
	void setPosition(const Vec2D&);
	const Vec2D getPosition();

    //Damages
	void receiveHealthDamage(const int& damage);
	void receiveRadDamage(const int& damage);
	void receiveEquipmentDamage(const int& damage);


	void addStimpak(const int& stimpak);
	void addRadAway(const int& radAway);
	void useStimpak();
	void useRadAway();
	Outfit* assignOutfit(Outfit*);
	Weapon* assignWeapon(Weapon*);

    //Check if player is dead.
	bool isDead();

protected:
	Vec2D position_ = Vec2D(0.0, 0.0);
	int SPECIAL_ = 0000000;
	int health_ = 100;
	int radiation_ = 0;
	int stimpak_ = 0;
	int radaway_ = 0;
	Outfit* outfit_ = NULL;
	Weapon* weapon_ = NULL;

private:

};

#endif