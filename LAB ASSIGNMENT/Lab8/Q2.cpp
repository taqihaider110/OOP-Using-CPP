#include <iostream>
using namespace std;
class Character
{
protected:
    string name;
    int level;
    float health;

public:
    Character(const string &name, int level, float health)
        : name(name), level(level), health(health) {}
};
class Warrior : virtual public Character
{
protected:
    float strength;
    int meleeWeaponProficiency;

public:
    Warrior(float strength, int meleeWeaponProficiency, const string &name, int level, float health) : Character(name, level, health), strength(strength), meleeWeaponProficiency(meleeWeaponProficiency) {}
    void slash()
    {
        cout << "Slash Attack used by Warrior" << endl;
    }
};
class Mage : virtual public Character
{
protected:
    float intelligence;
    int spellCastingProficiency;

public:
    Mage(float intelligence, int spellCastingProficiency, const string &name, int level, float health)
        : Character(name, level, health), intelligence(intelligence),
          spellCastingProficiency(spellCastingProficiency) {}
    void fireball()
    {
        cout << "Fireball thrown by Mage" << endl;
    }
};
class Archer : public Character
{
protected:
    float dexterity;
    int rangedWeaponProficiency;

public:
    Archer(float dexterity, int rangedWeaponProficiency, const string &name, int level, float health)
        : Character(name, level, health), dexterity(dexterity),
          rangedWeaponProficiency(rangedWeaponProficiency) {}
    void rapidShot()
    {
        cout << "Rapid Shot by Archer" << endl;
    }
};
class NPC : public Character
{
protected:
    string dialogue = "Hey!";

public:
    NPC(const string &name, int level, float health) : Character(name, level, health) {}
    void say()
    {
        cout << dialogue << endl;
    }
};
class Mighty : public Warrior, public Mage
{
public:
    Mighty(float strength, int meleeWeaponProficiency, float intelligence, int spellCastingProficiency,
           const string &name, int level, float health)
        : Warrior(strength, meleeWeaponProficiency, name, level, health),
          Mage(intelligence, spellCastingProficiency, name, level, health),
          Character(name, level, health) {}
};
int main()
{
    Mighty m1(20, 10, 20, 50, "Hitler", 70, 100);
    m1.slash();
    m1.fireball();
    return 0;
}
