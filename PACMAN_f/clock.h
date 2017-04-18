#include<ctime>
class clockc
{
private:
    int hour,minute,second,tot;
    clock_t current,defa,result;
    char *time;
    char int_to_char(int);
public:
    clockc();
    char *call();
    void start();
};
