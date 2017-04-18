#include"clock.h"
#include<ctime>
clockc::clockc()
{
    time=new char[9];
    time[2]=':';
    time[5]=':';
    time[8]='\0';
}

void clockc::start()
{
    defa=clock();
}

char *clockc::call()
{
    current=clock();
    result=current-defa;
    tot=(int)result/CLOCKS_PER_SEC;
    hour=tot/3600;
    tot%=3600;
    minute=tot/60;
    tot%=60;
    second=tot;
    int temp;
    if(hour<10)
    {
        time[0]='0';
        time[1]=int_to_char(hour);
    }
    else
    {
        temp=hour/10;
        hour%=10;
        time[0]=int_to_char(temp);
        time[1]=int_to_char(hour);
    }
    if(minute<10)
    {
        time[3]='0';
        time[4]=int_to_char(minute);
    }
    else
    {
        temp=minute/10;
        minute%=10;
        time[3]=int_to_char(temp);
        time[4]=int_to_char(minute);
    }
    if(second<10)
    {
        time[6]='0';
        time[7]=int_to_char(second);
    }
    else
    {
        temp=second/10;
        second%=10;
        time[6]=int_to_char(temp);
        time[7]=int_to_char(second);
    }
    return time;
}

char clockc::int_to_char(int x)
{
    switch(x)
    {
    case 0:return '0';
    case 1:return '1';
    case 2:return '2';
    case 3:return '3';
    case 4:return '4';
    case 5:return '5';
    case 6:return '6';
    case 7:return '7';
    case 8:return '8';
    case 9:return '9';
    }
}
