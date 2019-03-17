#ifndef MONSTER_H
#define MONSTER_H
#include <QLabel>
class magicTower:public QLabel {
    Q_OBJECT
};

class gamePerson : public magicTower {
public:
    int lifeValue;//生命值
    int attackPower;//攻击力
    int defense;//防御力
public:
    int getLV() { return lifeValue; }

    int getaP() { return attackPower; }

    int getdefense() { return defense; }
};
class null:public magicTower{
public:
    //0;
    null(){}
};
class wall:public magicTower{
public:
    //1;
    wall(){}
};
class door:public magicTower{
public:
    //2;
    door(){}
};
class stair_up:public magicTower{
public:
    //3
    stair_up(){}
};
class stair_down:public magicTower
{
public:
    //4
    stair_down(){}
};
class key:public magicTower{
public:
    //5;
    key(){}
};
class blood_bottle:public magicTower
{
public:
    //6
    blood_bottle(){blood_up=100;}
    int blood_up;
};
class red_stone:public magicTower{
public:
    //7;
    red_stone(){attack_up=100;}
    int attack_up;
};
class blue_stone:public magicTower{
public:
    //8;
    blue_stone(){defense_up=100;}
    int defense_up;
};
class hero:public gamePerson{
public:
    int key_number;
    int getKey() { return key_number; }
public:
    //15;
    hero();
    bool attack(gamePerson*);
};
class skeleton:public gamePerson{
public:
    //20
    skeleton();
};
class bigskeleton:public gamePerson{
public:
    //21;
    bigskeleton();
};
class red_slime:public gamePerson{
public:
    //23;
    red_slime();
};
class green_slime:public gamePerson
{
public:
    //22
    green_slime();
};
class bat:public gamePerson{
public:
    //24;
    bat();
};
class ghost:public gamePerson{
public:
    //25;
    ghost();
};
class boss:public gamePerson{
public:
    //26
    boss();
};

#endif // MONSTER_H
