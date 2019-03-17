#include"magictower.h"
hero::hero()
{
    lifeValue=1000;
    attackPower=10;
    defense=10;
    key_number=0;
}
bool hero::attack(gamePerson* m)
{
    int lv = lifeValue;
    int mlv = m->getLV();
    int md = m->getdefense();
    int ma = m->getaP();
    if (attackPower > md) {
        while (lv > 0 && mlv > 0) {
            mlv -= (attackPower - md);
            lv -= ((ma - defense) < 0 ? 0 : (ma - defense));
        }
        if (lv > 0) {
            lifeValue = lv-(ma-defense);
            return 1;
        }
        else return 0;
    }
    else return 0;
}
skeleton::skeleton()
{
    lifeValue=120;
    attackPower=25;
    defense=5;
}
bigskeleton::bigskeleton()
{
    lifeValue=150;
    attackPower=30;
    defense=10;
}
red_slime::red_slime()
{
    lifeValue=100;
    attackPower=15;
    defense=2;
}
green_slime::green_slime()
{
    lifeValue=100;
    attackPower=20;
    defense=1;
}
bat::bat()
{
    lifeValue=100;
    attackPower=20;
    defense=5;
}
ghost::ghost()
{
    lifeValue=100;
    attackPower=20;
    defense=10;
}
boss::boss()
{
    lifeValue=200;
    attackPower=50;
    defense=50;
}
