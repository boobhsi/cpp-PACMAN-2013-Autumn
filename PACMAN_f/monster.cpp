#include"player.h"
#include"monster.h"
#include<cmath>
#include<ctime>
#include<cstdlib>

extern int x,y;

int monster::monsterh=5;
int monster::monsterw=13;

void monster::mmove()
{
    if(direct==0) x-=1;
    else if(direct==1) y+=1;
    else if(direct==2) x+=1;
    else if(direct==3) y-=1;
}

void monster::turn()
{
    int xg=(::x)-x,yg=(::y)-y;
    if(fabs(xg)>monsterh&fabs(yg)>monsterw)
    {
        for(int i=0;i<4;i++)
        {
            int a=rand()%4;
            while(randdire[a])
            {
                a=rand()%4;
            }
            direction[i]=a;
            randdire[a]=1;
        }
        for(int i=0;i<4;i++) randdire[i]=0;
    }
    else
    {
        if(xg>0)
        {
            if(yg>0)
            {
                int a=rand()%2;
                if(a==0)
                {
                    direction[0]=1;
                    direction[1]=2;
                }
                else
                {
                    direction[1]=1;
                    direction[0]=2;
                }
                a=rand()%2;
                if(a==0)
                {
                    direction[2]=3;
                    direction[3]=0;
                }
                else
                {
                    direction[3]=3;
                    direction[2]=0;
                }
            }
            else if(yg<0)
            {
                int a=rand()%2;
                if(a==0)
                {
                    direction[0]=2;
                    direction[1]=3;
                }
                else
                {
                    direction[1]=2;
                    direction[0]=3;
                }
                a=rand()%2;
                if(a==0)
                {
                    direction[2]=1;
                    direction[3]=0;
                }
                else
                {
                    direction[3]=1;
                    direction[2]=0;
                }
            }
            else if(yg==0)
            {
                direction[0]=2;
                randdire[2]=1;
                for(int i=1;i<4;i++)
                {
                    int a=rand()%4;
                    while(randdire[a])
                    {
                        a=rand()%4;
                    }
                    direction[i]=a;
                    randdire[a]=1;
                }
                for(int i=0;i<4;i++) randdire[i]=0;
            }
        }
        else if(xg<0)
        {
            if(yg>0)
            {
                int a=rand()%2;
                if(a==0)
                {
                    direction[0]=1;
                    direction[1]=0;
                }
                else
                {
                    direction[1]=1;
                    direction[0]=0;
                }
                a=rand()%2;
                if(a==0)
                {
                    direction[2]=3;
                    direction[3]=2;
                }
                else
                {
                    direction[3]=3;
                    direction[2]=2;
                }
            }
            else if(yg<0)
            {
                int a=rand()%2;
                if(a==0)
                {
                    direction[0]=0;
                    direction[1]=3;
                }
                else
                {
                    direction[1]=0;
                    direction[0]=3;
                }
                a=rand()%2;
                if(a==0)
                {
                    direction[2]=1;
                    direction[3]=2;
                }
                else
                {
                    direction[3]=1;
                    direction[2]=2;
                }
            }
            else if(yg==0)
            {
                direction[0]=0;
                randdire[0]=1;
                for(int i=1;i<4;i++)
                {
                    int a=rand()%4;
                    while(randdire[a])
                    {
                        a=rand()%4;
                    }
                    direction[i]=a;
                    randdire[a]=1;
                }
                for(int i=0;i<4;i++) randdire[i]=0;
            }
        }
        else if(xg==0)
        {
            if(yg>0)
            {
                direction[0]=1;
                randdire[1]=1;
                for(int i=1;i<4;i++)
                {
                    int a=rand()%4;
                    while(randdire[a])
                    {
                        a=rand()%4;
                    }
                    direction[i]=a;
                    randdire[a]=1;
                }
                for(int i=0;i<4;i++) randdire[i]=0;
            }
            else if(yg<0)
            {
                direction[0]=3;
                randdire[3]=1;
                for(int i=1;i<4;i++)
                {
                    int a=rand()%4;
                    while(randdire[a])
                    {
                        a=rand()%4;
                    }
                    direction[i]=a;
                    randdire[a]=1;
                }
                for(int i=0;i<4;i++) randdire[i]=0;
            }
        }
    }
}

int monster::getx()
{
    return x;
}

int monster::getd()
{
    return direct;
}

int monster::gety()
{
    return y;
}

void monster::setx(int in)
{
    x=in;
}

void monster::sety(int in)
{
    y=in;
}

void monster::setd(int in)
{
    direct=in;
}
