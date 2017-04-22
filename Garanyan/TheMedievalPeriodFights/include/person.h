/**
 * @brief  The class describes characters, types of characters,
 * their skills (HP,Strength, Speed, weapon mastery, agility, luck)
 */
#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED
#include "../include/armor.h"
#include "../include/weapon.h"
#include <iostream>
#include <memory>
using Points = int;
class Person
{
    public:
    virtual ~Person();
	Person(const std::string & name);

    Person(const Person& copied) = delete;
	Person& operator=(const Person& copied) = delete;

	Person(Person&& movied) {
		charArmor.reset(movied.charArmor.release());
		charWeapon.reset(movied.charWeapon.release());
		//return *this;
	}

	Person& operator=(Person&& movied)
	{
		charArmor.reset(movied.charArmor.release());
		charWeapon.reset(movied.charWeapon.release());
		return *this;
	}

    void attacked(Person&);
     void setWeapon(std::unique_ptr<Weapon> weapon);
	 void setArmor(std::unique_ptr<Armor> armor);

	 std::unique_ptr<Armor> takeOffArmor();
    std::unique_ptr<Weapon> takeOffWeapon();
    protected:
        std::unique_ptr <Weapon> charWeapon;
		std::unique_ptr <Armor> charArmor;
        std::string name;
		Points healthPoints;
		Points strength;
		Points speed;
		Points agility;
		Points luck;
};

class Knight final: public Person
{
	public:
		Knight(const std::string& name);
};

class Peasant final: public Person
{
public:
	Peasant(const std::string& name);

};
class Sharp final: public Person
{
public:
	Sharp(const std::string& name);
};

#endif // PERSON_H_INCLUDED
