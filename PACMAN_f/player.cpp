#include"player.h"
int player::getx()
{
    return x;
}

int player::getd()
{
    return direct;
}

int player::gety()
{
    return y;
}

void player::pmove()
{
    if(direct==0) x-=1;
    else if(direct==1) y+=1;
    else if(direct==2) x+=1;
    else if(direct==3) y-=1;
}

void player::setd(int in)
{
    direct=in;
}

void player::setx(int in)
{
    x=in;
}

void player::sety(int in)
{
    y=in;
}
