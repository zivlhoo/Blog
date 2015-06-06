title: 笔记-策略模式
date: 2015-05-31 00:40:50
tags: [策略模式,Head First]
categories: [设计模式,笔记]
---

## 需求
同学们都玩过游戏吧！
在游戏世界中有很多角色供我们选择，每个角色的攻击方式都不一样，比如说刀砍、剑刺、射箭...
那么问题来了，我们如何设计多个角色以及他们的攻击行为呢。

## 实现

### 方式1
1. 定义一个角色父类并且提供一个攻击方法
2. 所有子类皆继承此父类

####代码

```
//
//  characters.h
//

//角色父类
class Character
{
public:
	void attack();
};

//刽子手
class Executioner : public Character
{
public:

};
```

```
//
//  characters.cpp
//

#include <iostream>
#include "character.h"

using namespace std;

void Character::attack()
{
	cout << "Character attack" << endl;
}

```
####分析结论
对于目前的需求完全没有问题。可是多个角色该如何实现呢？如果继续延用上面的实现思路让每个角色都继承`Character`类，这样会导致只要子类的攻击行为与父类的不同，子类就必须重写父类的`attack`方法（缺乏灵活）；而又如果有2个子类的攻击方式相同我们又不能复用代码(无法复用)。那我们就试试第二种方式吧。
####缺点
1. 缺乏弹性不够灵活
2. 代码无法复用

### 方式2
1. 将攻击方式提取出来定义成接口
2. 各个角色子类实现此接口

####代码

```
//
//  characters.h
//

class AttackBehavior
{
public:

};

//角色父类
class Character
{
public:
	virtual void attack();
};

//刽子手
class Executioner : public Character ,public AttackBehavior
{
public:
	void attack();
};

//剑客
class SwordsMan : public Character ,public AttackBehavior
{
public:
	void attack();
};

```

```
//
//  characters.cpp
//

#include <iostream>
#include "characters.h"

using namespace std;

void AttackBehavior::attack()
{

}

void Executioner::attack()
{
	cout << "Executioner::attack" << endl;
}

void SwordsMan::attack()
{
	cout << "SwordsMan::attack" << endl;
}

```

####分析结论
这种方式比方式1够灵活，可是代码依然不能复用。
这两种方式都依赖于“实现”，我们被实现绑的死死的，没办法改角色的攻击方式。

####缺点
2. 代码无法复用

### 最终实现
首先这里引出二条设计原则：
+ `找出应用中可能需要变化之处，把它们独立出来，不要和那些不需要变化的代码混在一起。`
+ `针对接口编程，而不是针对实现编程。`

1. 把角色的攻击行为取出来定义成接口，再由其他具体的攻击行为实现它。
2. 在父类中把行为组合到角色中来。

####代码
```
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
```

```
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
```
####分析结论
最终方式迥异于前两种方式，前两种的做法是：行为来自`Character`父类的具体实现，或是继承某个接口并由子类自行实现而来。
这种做法和“继承”不同的地方在于，角色的行为不是继承来的，而是和适当的行为对象“组合”来的。
这是一个很重要的技巧。其实这就是第三个设计原则：

+ `多用组合，少用继承。`

## 总结
###策略模式
定义了算法族，分别封装起来，但它们之间可以互相替换，此模式让算法的变化独立于使用算法的客户。

###设计模式的好处
1. 让开发人员之间有共享的词汇。
2. 可以把你的思考架构的层次提高到模式层面，而不是仅停留在琐碎的对象上。

###设计原则
1. 找出应用中可能需要变化之处，把它们独立出来，不要和那些不需要变化的代码混在一起。
2. 针对接口编程，而不是针对实现编程。
3. 多用组合，少用继承。

###建议
1. 有一些面向对象原则，适用于所有的模式。当你无法找到适当的模式解决问题时，采用这些原则可以帮助你。
2. 建立可维护的OO系统，要诀就在于随时想到系统以后可能需要的变化以及应付变化的原则。
