#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
    struct tm y2k;
    double tm;
    clock_t t;
    int d, m, y;

    cout << "Unesi dan, mjesec i godinu: ";
    cin >> d >> m >> y;

    y2k.tm_hour = 0;   y2k.tm_min = 0; y2k.tm_sec = 0;
    y2k.tm_year = y-1900; y2k.tm_mon = --m; y2k.tm_mday = --d;

    tm=difftime(time(0),mktime(&y2k));
    cout << tm/60/60/24/365 << " godina" << endl
        << (long)(tm/60/60/24) << " dana" << endl
        << (long)tm << " sekunda" << endl;

    t=clock();
    while(1)
    {
        if(clock()-t>CLOCKS_PER_SEC)
        {
            system("CLS");
            tm=difftime(time(0),mktime(&y2k));
            cout << tm/60/60/24/365 << " godina" << endl
                << (long)(tm/60/60/24) << " dana" << endl
                << (long)tm << " sekunda" << endl;
            t=clock();
        }
    }
}
