#include<iostream>
#include<windows.h>
#include<cstdlib>
#include"curses.h"
#include"clock.h"
#include"irrKlang.h"
#include"monster.h"
#include"player.h"
#include"other.h"
using namespace std;
using namespace irrklang;
int x,y;

int main()
{
    ISoundEngine* engine = createIrrKlangDevice();
    if (!engine) return 0;
    system("cls");
    char repeat='y';
    while(repeat=='y')
    {

        monster::monsterh=5;
        monster::monsterw=13;
        char *cscore=new char[10];
        bool sta=false;
        bool sur=false;
        bool blo=false;
        bool normal=false;
        bool flee=false;
        bool gamenonstart=true;
        bool firstd=true;
        bool todover=false;
        int j;
        int delay=0,pdelay=0;
        int co=0;
        int re=0;
        int surre=0;
        int n=40;
        int staad=2;
        int pn=40;
        int fc=100;
        int ft;
        int reled=n*5;
        int surd=n*15;
        int surv[10][2]={{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{0,0}};
        int surco=0;
        int kill=0;
        int surtotald=n*30;
        int stdn=0;
        player p;
        clockc tiktok;
        do
        {
            cout<<"Choose which mode to play??\n";
            cout<<"(1)Normal mode\n";
            cout<<"(2)Starving mode\n";
            cout<<"(3)Suvival mode\n";
            cout<<"(4)Bloody mode\n";
            int qwer;
            cin>>qwer;
            if(qwer==2) sta=true;
            else if(qwer==3) sur=true;
            else if(qwer==4) blo=true;
            else if(qwer==1) normal=true;
            else
            {
                cout<<"Please input a correct mode number!!\n"<<endl;;
                continue;
            }
            if(sta||normal)
            {
                cout<<"How many monsters do you want??(max:10): ";
                cin>>j;
                if(j>10) cout<<"To maintain the balance of the game.\nPlease choose other mode(bloody and survaval) to have a cruel experiment!\n"<<endl;
                else gamenonstart=false;
            }
            else
            {
                if(blo)
                {
                    reled=n;
                    monster::monsterw=53;
                    monster::monsterh=23;
                }
                else if(sur)
                {
                    reled=n*2;
                }
                j=40000;
                gamenonstart=false;
            }
        }while(gamenonstart);
        init();
        if(blo) engine->play2D("media\\contra.ogg");
        else if(sur) engine->play2D("media\\of.ogg");
        else engine->play2D("media\\Arcade.ogg");
        monster m[j];
        int map[23][53]={
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
            {0,3,1,1,1,1,3,1,1,1,1,1,3,0,0,3,1,1,1,7,1,1,1,1,3,0,0,0,3,1,1,1,1,7,1,1,1,3,0,0,3,1,1,1,1,1,3,1,1,1,1,3,0},
            {0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0},
            {0,2,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,2,0},
            {0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0},
            {0,3,1,1,1,1,3,1,1,3,1,1,3,1,1,3,1,1,3,1,1,3,1,1,3,1,1,1,3,1,1,3,1,1,3,1,1,3,1,1,3,1,1,3,1,1,3,1,1,1,1,3,0},
            {0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,1,0},
            {0,3,1,1,1,1,3,0,0,3,1,1,3,0,0,3,1,1,3,0,0,3,1,1,3,0,0,0,3,1,1,3,0,0,3,1,1,3,0,0,3,1,1,3,0,0,3,1,1,1,1,3,0},
            {0,0,0,0,0,0,1,0,0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,5,0,0,0,5,0,0,0,0,0,0,0,0,1,0,0,1,0,0,1,0,0,1,0,0,0,0,0,0},
            {0,0,0,0,0,0,1,0,0,1,0,0,3,1,1,3,1,1,3,0,0,6,5,5,6,5,6,5,6,5,5,6,0,0,3,1,1,3,1,1,3,0,0,1,0,0,1,0,0,0,0,0,0},
            {0,0,0,0,0,0,1,0,0,1,0,0,7,0,0,0,0,0,1,0,0,5,0,0,0,0,0,0,0,0,0,5,0,0,1,0,0,0,0,0,7,0,0,1,0,0,1,0,0,0,0,0,0},
            {5,5,5,5,5,5,3,1,1,3,1,1,3,0,0,3,1,1,3,5,5,6,0,0,0,0,0,0,0,0,0,6,5,5,3,1,1,3,0,0,3,1,1,3,1,1,3,5,5,5,5,5,5},
            {0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,0,5,0,0,0,0,0,0,0,0,0,5,0,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0},
            {0,0,0,0,0,0,1,0,0,3,1,1,1,1,1,3,1,1,3,0,0,6,5,5,5,5,5,5,5,5,5,6,0,0,3,1,1,3,1,1,1,1,1,3,0,0,1,0,0,0,0,0,0},
            {0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,5,0,0,0,0,0,0,0,0,0,5,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0},
            {0,3,1,1,1,1,3,1,1,3,1,1,3,0,0,3,1,1,3,1,1,3,1,1,3,0,0,0,3,1,1,3,1,1,3,1,1,3,0,0,3,1,1,3,1,1,3,1,1,1,1,3,0},
            {0,1,0,0,0,0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0},
            {0,4,1,3,0,0,3,1,1,3,1,1,3,1,1,3,1,1,3,1,1,3,1,1,3,1,1,1,3,1,1,3,1,1,3,1,1,3,1,1,3,1,1,3,1,1,3,0,0,3,1,4,0},
            {0,0,0,1,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,1,0,0,1,0,0,1,0,0,0},
            {0,3,1,3,1,1,3,0,0,3,1,1,3,0,0,3,1,1,3,0,0,3,1,1,3,0,0,0,3,1,1,3,0,0,3,1,1,3,0,0,3,1,1,3,0,0,3,1,1,3,1,3,0},
            {0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,7,0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,7,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0},
            {0,3,1,1,1,1,1,1,1,1,1,1,3,1,1,3,1,1,1,1,1,1,1,1,3,1,1,1,3,1,1,1,1,1,1,1,1,3,1,1,3,1,1,1,1,1,1,1,1,1,1,3,0},
            {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
        };
        for(int q=0;q<23;q++)
        {
            for(int r=0;r<53;r++)
            {

                if(map[q][r]==0) mvaddch(q,r,'#'|COLOR_PAIR(20));
                if(sur)
                {
                    if(map[q][r]==2||map[q][r]==4||map[q][r]==7) mvaddch(q,r,'@');
                }
                else
                {
                    if(map[q][r]==1||map[q][r]==3||map[q][r]==7) mvaddch(q,r,'*');
                    else if(map[q][r]==2||map[q][r]==4) mvaddch(q,r,'@');
                }

            }
        }
        mvaddch(10,26,'M' | COLOR_PAIR(1));
        mvaddch(1,2,'P'| COLOR_PAIR(25));
        refresh();

        //************************************map*******************************************

        if(blo) napms(5600);
        else if(sur) napms(6200);
        else napms(4500);
        tiktok.start();
        m[0].release=1;
        while(1)
        {
            if(sur&&firstd)
            {
                map[3][1]=1;
                mvaddch(3,1,' ');
                map[3][51]=1;
                mvaddch(3,51,' ');
                map[17][1]=3;
                mvaddch(17,1,' ');
                map[17][51]=3;
                mvaddch(17,51,' ');
                map[1][19]=1;
                mvaddch(1,19,' ');
                map[1][33]=1;
                mvaddch(1,33,' ');
                map[10][12]=1;
                mvaddch(10,12,' ');
                map[10][40]=1;
                mvaddch(10,40,' ');
                map[20][15]=1;
                mvaddch(20,15,' ');
                map[20][37]=1;
                mvaddch(20,37,' ');
            }
            x=p.getx(),y=p.gety();
            if(flee)
            {
                if(delay==n)
                {
                    for(int i=0;i<j;i++)
                    {
                        if(m[i].release)
                        {
                            int mx=m[i].getx(),my=m[i].gety(),md=m[i].getd();
                            if(map[mx][my]==3||map[mx][my]==4||map[mx][my]==6)
                            {
                                srand(clock()*(i+1));
                                m[i].turn();
                                for(int k=3;k>0;k--)
                                {
                                    int d=m[i].direction[k];
                                    if(d==0)
                                    {
                                        if(map[mx-1][my]==0);
                                        else
                                        {
                                            m[i].setx(mx-1);
                                            m[i].setd(0);
                                            break;
                                        }
                                    }
                                    else if(d==1)
                                    {
                                        if(map[mx][my+1]==0);
                                        else
                                        {
                                            m[i].sety(my+1);
                                            m[i].setd(1);
                                            break;
                                        }
                                    }
                                    else if(d==2)
                                    {
                                        if(map[mx+1][my]==0);
                                        else
                                        {
                                            m[i].setx(mx+1);
                                            m[i].setd(2);
                                            break;
                                        }
                                    }
                                    else
                                    {
                                        if(map[mx][my-1]==0);
                                        else
                                        {
                                            m[i].sety(my-1);
                                            m[i].setd(3);
                                            break;
                                        }
                                    }
                                }
                            }
                            else
                            {
                                m[i].mmove();
                                if(m[i].gety()==-1) m[i].sety(52);
                                else if(m[i].gety()==53) m[i].sety(0);
                            }
                            if(sur)
                            {
                                if(map[mx][my]==1||map[mx][my]==3) mvaddch(mx,my,' ');
                                else if(map[mx][my]==2||map[mx][my]==4||map[mx][my]==7) mvaddch(mx,my,'@');
                                else if(map[mx][my]==5||map[mx][my]==6) mvaddch(mx,my,' ');
                            }
                            else
                            {
                                if(map[mx][my]==1||map[mx][my]==3||map[mx][my]==7) mvaddch(mx,my,'*');
                                else if(map[mx][my]==2||map[mx][my]==4)mvaddch(mx,my,'@');
                                else if(map[mx][my]==5||map[mx][my]==6) mvaddch(mx,my,' ');
                            }
                        }
                        mvaddch(10,26,' ');
                        mvaddch(m[i].getx(),m[i].gety(),'M'|COLOR_PAIR(fc));
                    }
                    if(fc==10) fc=15;
                    else fc=10;
                    ft+=1;
                    if(ft==15)
                    {
                        ft=0;
                        co=0;
                        re=reled;
                        n=40;
                        flee=false;
                    }
                delay=0;
                }
            }
            else
            {
                if(delay==n)
                {
                    for(int i=0;i<j;i++)
                    {
                        if(m[i].release)
                        {
                            int mx=m[i].getx(),my=m[i].gety(),md=m[i].getd();
                            if(map[mx][my]==3||map[mx][my]==4||map[mx][my]==6)
                            {
                                srand(clock()*(i+1));
                                m[i].turn();
                                for(int k=0;k<4;k++)
                                {
                                    int d=m[i].direction[k];
                                    if(d==0)
                                    {
                                        if(map[mx-1][my]==0);
                                        else
                                        {
                                            m[i].setx(mx-1);
                                            m[i].setd(0);
                                            break;
                                        }
                                    }
                                    else if(d==1)
                                    {
                                        if(map[mx][my+1]==0);
                                        else
                                        {
                                            m[i].sety(my+1);
                                            m[i].setd(1);
                                            break;
                                        }
                                    }
                                    else if(d==2)
                                    {
                                        if(map[mx+1][my]==0);
                                        else
                                        {
                                            m[i].setx(mx+1);
                                            m[i].setd(2);
                                            break;
                                        }
                                    }
                                    else
                                    {
                                        if(map[mx][my-1]==0);
                                        else
                                        {
                                            m[i].sety(my-1);
                                            m[i].setd(3);
                                            break;
                                        }
                                    }
                                }
                            }
                            else
                            {
                                m[i].mmove();
                                if(m[i].gety()==-1) m[i].sety(52);
                                else if(m[i].gety()==53) m[i].sety(0);
                            }
                            if(sur)
                            {
                                if(map[mx][my]==1||map[mx][my]==3) mvaddch(mx,my,' ');
                                else if(map[mx][my]==2||map[mx][my]==4||map[mx][my]==7) mvaddch(mx,my,'@');
                                else if(map[mx][my]==5||map[mx][my]==6) mvaddch(mx,my,' ');
                            }
                            else
                            {
                                if(map[mx][my]==1||map[mx][my]==3||map[mx][my]==7) mvaddch(mx,my,'*');
                                else if(map[mx][my]==2||map[mx][my]==4)mvaddch(mx,my,'@');
                                else if(map[mx][my]==5||map[mx][my]==6) mvaddch(mx,my,' ');
                            }
                        }
                        mvaddch(10,26,' ');
                        mvaddch(m[i].getx(),m[i].gety(),'M'|COLOR_PAIR(i%5+1));
                    }
                delay=0;
                }
            }
            if(re==reled&&co<j&&(!flee))
            {
                bool over=false;
                while(m[co].release==1)
                {
                    if(co==j-1)
                    {
                        over=true;
                        co+=1;
                        break;
                    }
                    co+=1;
                }
                if(!over)
                {
                    m[co].release=1;
                    co+=1;
                    re=0;
                }
            }
            re+=1;
            move(0,53);
            char c;
            bool pt=false,inp=false;
            int temp;
            if(p.getd()==0&&map[x-1][y]==0) pt=true;
            else if(p.getd()==1&&y!=52&&map[x][y+1]==0) pt=true;
            else if(p.getd()==2&&map[x+1][y]==0) pt=true;
            else if(p.getd()==3&&y!=0&&map[x][y-1]==0) pt=true;
            if((c=getch())!=ERR)
            {
                temp=pdelay;
                pdelay=pn;
                inp=true;
            }
            mvaddch(0,53,' ');
            if(pdelay==pn)
            {
                mvaddch(x,y,' ');
                if(map[x][y]==3) {map[x][y]=6;p.score+=10;}
                else if(map[x][y]==1) {map[x][y]=5;p.score+=10;}
                else if(map[x][y]==2) p.score+=50;
                else if(map[x][y]==4) p.score+=50;
                else if(map[x][y]==7) {map[x][y]=5;p.score+=10;}
                if(pt)
                {
                    if(inp)
                    {
                        if(c=='w'&&map[x-1][y]!=0) {p.setd(0);p.setx(x-1);pdelay=0;}
                        else if(c=='a'&&map[x][y-1]!=0) {p.setd(3);p.sety(y-1);pdelay=0;}
                        else if(c=='s'&&map[x+1][y]!=0) {p.setd(2);p.setx(x+1);pdelay=0;}
                        else if(c=='d'&&map[x][y+1]!=0) {p.setd(1);p.sety(y+1);pdelay=0;}
                    }
                }
                else
                {
                    if(inp)
                    {
                        if(c=='w'&&p.getd()==0){pdelay=temp;if(temp==pn) {p.pmove();pdelay=0;}}
                        else if(c=='a'&&p.getd()==3)
                        {
                            pdelay=temp;
                            if(temp==pn)
                            {
                                p.pmove();
                                if(p.gety()==-1) p.sety(52);
                                else if(p.gety()==53) p.sety(0);
                                pdelay=0;
                            }
                        }
                        else if(c=='s'&&p.getd()==2) {pdelay=temp;if(temp==pn) {p.pmove();pdelay=0;}}
                        else if(c=='d'&&p.getd()==1)
                        {
                            pdelay=temp;
                            if(temp==pn)
                            {
                                p.pmove();
                                if(p.gety()==-1) p.sety(52);
                                else if(p.gety()==53) p.sety(0);
                                pdelay=0;
                            }
                        }
                        else
                        {
                            if(c=='w'&&map[x-1][y]!=0) {p.setd(0);p.setx(x-1);pdelay=0;}
                            else if(c=='a'&&y==0) {p.setd(3);p.sety(52);pdelay=0;}
                            else if(c=='a'&&map[x][y-1]!=0) {p.setd(3);p.sety(y-1);pdelay=0;}
                            else if(c=='s'&&map[x+1][y]!=0) {p.setd(2);p.setx(x+1);pdelay=0;}
                            else if(c=='d'&&y==52) {p.setd(1);p.sety(0);pdelay=0;}
                            else if(c=='d'&&map[x][y+1]!=0) {p.setd(1);p.sety(y+1);pdelay=0;}
                            else
                            {
                                pdelay=temp;
                                if(temp==pn)
                                {
                                    p.pmove();
                                    if(p.gety()==-1) p.sety(52);
                                    else if(p.gety()==53) p.sety(0);
                                    pdelay=0;
                                }
                            }
                        }
                    }
                    else
                    {
                        p.pmove();
                        if(p.gety()==-1) p.sety(52);
                        else if(p.gety()==53) p.sety(0);
                        pdelay=0;
                    }
                }
            }
            bool die=false;
            for(int qw=0;qw<j;qw++)
            {
                if(m[qw].getx()==p.getx()&&m[qw].gety()==p.gety())
                {
                    if(flee)
                    {
                        if(sur||blo) kill+=1;
                        p.score+=200;
                        m[qw].reset();
                    }
                    else die=true;
                }
            }
            if(die)
            {
                if(blo) engine->removeAllSoundSources();
                napms(50);
                engine->play2D("media\\d.ogg");
                nodelay(stdscr,FALSE);
                mvprintw(13,62,"YOU LOSE!!");
                refresh();
                napms(3000);
                mvprintw(15,60,"continue?(y/n) ");
                move(15,75);
                curs_set(1);
                refresh();
                repeat=getch();
                break;
            }
            if(surre==surd&&sur)
            {
                if(surv[surco][0]!=0)
                {
                    if(surv[surco][0]==17) map[surv[surco][0]][surv[surco][1]]=4;
                    else map[surv[surco][0]][surv[surco][1]]=2;
                    mvaddch(surv[surco][0],surv[surco][1],'@');
                    surv[surco][0]=0;
                    surv[surco][1]=0;
                }
                surco+=1;
                if(surco>=10) surco=0;
                surre=0;
            }
            if((map[p.getx()][p.gety()]==4||map[p.getx()][p.gety()]==2||(sur&&map[p.getx()][p.gety()]==7)))
            {
                if(map[p.getx()][p.gety()]==4) map[p.getx()][p.gety()]=6;
                else if(map[p.getx()][p.gety()]==2||map[p.getx()][p.gety()]==7) map[p.getx()][p.gety()]=5;
                if(sur)
                {
                    surv[surco][0]=p.getx();
                    surv[surco][1]=p.gety();
                    surco+=1;
                    if(surco>=10) surco=0;
                }
                p.score+=50;
                flee=true;
                n=80;
                ft=0;
            }
            bool win=true;
            for(int i=0;i<23;i++)
            {
                for(int j=0;j<53;j++)
                {
                    if(map[i][j]==1) win=false;
                }
            }
            if(win)
            {
                if(sta)
                {
                    mvprintw(13,61,"NEW ROUND!!");
                    napms(3000);
                    n-=3*staad;
                    staad+=1;
                    remap(map);
                }
                else
                {
                    engine->removeAllSoundSources();
                    keypad(stdscr, FALSE);
                    nodelay(stdscr,FALSE);
                    mvprintw(13,62,"YOU WIN!!");
                    refresh();
                    napms(3000);
                    mvprintw(15,60,"continue?(y/n) ");
                    move(15,75);
                    curs_set(1);
                    refresh();
                    repeat=getch();
                    break;

                }
            }
            mvaddch(p.getx(),p.gety(),'P'| COLOR_PAIR(25));
            if(sur) {mvprintw(0,54,"Survival time: ");mvprintw(0,69,tiktok.call());mvprintw(1,54,"Monster been killed :");mvprintw(1,75,int_to_string(kill,cscore));}
            else {mvprintw(0,60,"Score:");mvprintw(0,67,int_to_string(p.score,cscore));}
            if(blo) {mvprintw(1,54,"Survival time: ");mvprintw(1,69,tiktok.call());mvprintw(2,54,"Monster been killed :");mvprintw(2,75,int_to_string(kill,cscore));}
            if(stdn==surtotald&&sur&&!todover)
            {
                firstd=false;
                todover=true;
                map[3][1]=2;
                mvaddch(3,1,'@');
                map[3][51]=2;
                mvaddch(3,51,'@');
                map[17][1]=4;
                mvaddch(17,1,'@');
                map[17][51]=4;
                mvaddch(17,51,'@');
                map[1][19]=7;
                mvaddch(1,19,'@');
                map[1][33]=7;
                mvaddch(1,33,'@');
                map[10][12]=7;
                mvaddch(10,12,'@');
                map[10][40]=7;
                mvaddch(10,40,'@');
                map[20][15]=7;
                mvaddch(20,15,'@');
                map[20][37]=7;
                mvaddch(20,37,'@');
            }
            refresh();
            delay+=1;
            surre+=1;
            pdelay+=1;
            if(sur&&!todover) stdn+=1;
            napms(5);
        }
    endwin();
    system("cls");
    }
}
