//
//  characters.cpp
//

#include <iostream>
#include "characters.h"

using namespace std;

void AttackBehavior::attack()
{
	
}

void ExecutionerBehavior::attack()
{
	cout << "exec Executioner::attack" << endl;
}

void SwordsManBehavior::attack()
{
	cout << "exec SwordsMan::attack" << endl;
}

void ArcherBehavior::attack()
{
	cout << "exec Archer::attack" << endl;
}


Character::Character():_attackBehavior(NULL)
{
}

void Character::attack()
{
	if (!_attackBehavior)return;

	_attackBehavior->attack();
}

void Character::setAttackBehavior(AttackBehavior *attackBehavior)
{
	_attackBehavior = attackBehavior;
}

AttackBehavior* Character::getAttackBehavior()
{
	return _attackBehavior;
}

int main(int argc, char const *argv[])
{
	SwordsManBehavior swordsManBehavior;
	ArcherBehavior 	  archerBehavior;

	SwordsMan character;
	character.setAttackBehavior(&swordsManBehavior);
	character.attack();

	character.setAttackBehavior(&archerBehavior);
	character.attack();

	return 0;
}