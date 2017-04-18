class monster
{

private:
    int x;
    int y;
    int randdire[4]={0,0,0,0};
    int direct;
public:
    monster()
    {
        x=10;
        y=26;
        direct=0;
        release=0;
    }
    void reset()
    {
        x=10;
        y=26;
        direct=0;
        release=0;
    }
    static int monsterw,monsterh;
    bool release;
    int getx();
    int gety();
    int getd();
    void setx(int);
    void sety(int);
    void setd(int);
    void turn();
    void mmove();
    int direction[4];
};
