//
//  characters.h
//

//攻击接口
class AttackBehavior
{
public:
	virtual void attack();
};

//刽子手攻击行为
class ExecutionerBehavior : public AttackBehavior
{
public:	
	void attack();
};

//剑客攻击行为
class SwordsManBehavior : public AttackBehavior
{
public:	
	void attack();
};

//弓箭手攻击行为
class ArcherBehavior : public AttackBehavior
{
public:	
	void attack();
};


//角色-父类
class Character
{
public:
	Character();

	//角色攻击方法
	virtual void attack();

	void setAttackBehavior(AttackBehavior*);
	AttackBehavior* getAttackBehavior();

private:
	//攻击行为变量
	AttackBehavior *_attackBehavior;
};

//角色-刽子手
class Executioner : public Character 
{
};

//角色-剑客
class SwordsMan : public Character 
{
};

//角色-弓箭手
class Archer : public Character 
{
};