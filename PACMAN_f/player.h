class player
{
private:
    int x,y;
    int direct;
public:
    player()
    {
        x=1;
        y=2;
        direct=1;
        score=0;
    }
    void pmove();
    int getx();
    int gety();
    int getd();
    int score;
    void setd(int);
    void setx(int);
    void sety(int);
};

