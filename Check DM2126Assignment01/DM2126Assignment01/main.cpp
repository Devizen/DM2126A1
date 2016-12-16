#include <iostream>
using std::cout;
using std::endl;

#include "Dweller.h"
#include "Outfit.h"
#include "Weapon.h"
#include "Item.h"
#include "GameObject.h"
#include "Vec2D.h"

void testNames();
void shouldNotCompile();

int main()
{
    testNames();
    shouldNotCompile();

    Dweller d("One", 7624221);
    Outfit o("Test Name", 12, 6969696);

    //Left Int Durability Right Int Damage.
    Weapon testWeap("TestWeap", 12, 222);
    d.assignWeapon(&testWeap);
    d.assignOutfit(&o);

    cout << "Nothing should appear above" << endl;
    cout << "Dweller Name" << endl;
    cout << d.getName() << "\n" << endl;

    cout << "Dweller Health" << endl;
    cout << d.getCurrentHealth() << "\n" << endl;

    cout << "Dweller Count" << endl;
    cout << d.getCount() << "\n" << endl;

    cout << "Dweller Special" << endl;
    cout << d.getSPECIAL() << "\n" << endl;

    cout << "Dweller Attack" << endl;
    cout << d.getAttackDmg() << "\n" << endl;

    cout << "Outfit Name" << endl;
    cout << o.getName() << "\n" << endl;

    cout << "Outfit Special" << endl;
    cout << o.getSPECIAL() << "\n" << endl;

    cout << "Outfit Durability" << endl;
    cout << o.getDurability() << "\n" << endl;

    cout << "Weapon Name" << endl;
    cout << testWeap.getName() << "\n" << endl;

    cout << "Weapon Durability" << endl;
    cout << testWeap.getDurability() << "\n" << endl;

    cout << "Weapon Damage" << endl;
    cout << testWeap.getAttackDmg() << "\n" << endl;

    d.receiveEquipmentDamage(24);

    o.receiveDamage(6);
    testWeap.receiveDamage(6);

    cout << "Outfit Durability After Damage" << endl;
    cout << o.getDurability() << "\n" << endl;

    cout << "Weapon Durability After Damage" << endl;
    cout << testWeap.getDurability() << "\n" << endl;

    
    cout << "Dweller Special" << endl;
    cout << d.getSPECIAL() << "\n" << endl;

    cout << "Outfit Special" << endl;
    cout << o.getSPECIAL() << "\n" << endl;

    cout << "Weapon Damage" << endl;
    cout << testWeap.getAttackDmg() << "\n" << endl;

    cout << "Dweller Attack" << endl;
    cout << d.getAttackDmg() << "\n" << endl;

    Weapon testWeap2("TestWeap2", 1, 444);
    d.assignWeapon(&testWeap2);
    cout << "Dweller Attack After New Weapon" << endl;
    cout << d.getAttackDmg() << "\n" << endl;

    cout << "Dweller Health" << endl;
    cout << d.getCurrentHealth() << "\n" << endl;


    d.receiveRadDamage(1);

    cout << "Dweller Health After Radiation" << endl;
    cout << d.getCurrentHealth() << "\n" << endl;

    d.addRadAway(1);
    d.useRadAway();
    cout << "Dweller Health After RadAway" << endl;
    cout << d.getCurrentHealth() << "\n" << endl;

    cout << "Dweller is dead?" << endl;
    cout << d.isDead() << "\n" << endl;

    d.receiveRadDamage(100);
    cout << "Dweller is dead after Radiation?" << endl;
    cout << d.isDead() << "\n" << endl;

    d.addRadAway(1);
    d.useRadAway();
    cout << "Dweller is dead after RadAway?" << endl;
    cout << d.isDead() << "\n" << endl;

    cout << "Dweller Name" << endl;
    cout << d.getName() << "\n" << endl;

    cout << "Dweller Health" << endl;
    cout << d.getCurrentHealth() << "\n" << endl;

    cout << "Dweller Count" << endl;
    cout << d.getCount() << "\n" << endl;

    cout << "Dweller Special" << endl;
    cout << d.getSPECIAL() << "\n" << endl;

    cout << "Dweller Attack" << endl;
    cout << d.getAttackDmg() << "\n" << endl;


    d.addStimpak(1);
    d.useStimpak();
    d.receiveRadDamage(0);
    Outfit* shirt = new Outfit("shirt", 1, 1000000);

    cout << "Dweller is dead after Stimpak?" << endl;
    cout << d.isDead() << "\n" << endl;

    cout << "Dweller Name" << endl;
    cout << d.getName() << "\n" << endl;

    cout << "Dweller Health" << endl;
    cout << d.getCurrentHealth() << "\n" << endl;

    cout << "Dweller Count" << endl;
    cout << d.getCount() << "\n" << endl;

    cout << "Dweller Special" << endl;
    cout << d.getSPECIAL() << "\n" << endl;

    cout << "Dweller Attack" << endl;
    cout << d.getAttackDmg() << "\n" << endl;

    d.assignOutfit(shirt);
    cout << "Dweller Special" << endl;
    cout << d.getSPECIAL() << "\n" << endl;

    system("pause");
    return 0;

}