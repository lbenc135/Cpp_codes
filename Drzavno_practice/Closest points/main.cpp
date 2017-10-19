#include <cstdio>
#include <set>
#include <cmath>
#include <algorithm>
using namespace std;

const int INF = 1000000000;

struct point {
    int x, y;
    point() {}
    point(int x1, int y1) { x=x1; y=y1; }
    bool operator<(const point &p) const
    {
        if(x!=p.x)
            return x<p.x;
        else
            return y<p.y;
    }
} points[100];

int n;

double dist(point a, point b) { return sqrt(pow(a.x-b.x, 2)+pow(a.y-b.y, 2)); }

struct cmpY
{
    bool operator()(point a, point b) const
    {
        if(a.y!=b.y)
            return a.y<b.y;
        else
            return a.x<b.x;
    }
};

double closest()
{
    set<point, cmpY> active;
    sort(points, points+n);
    int rep=0; double h=INF;
    for(int i=0;i<n;i++)
    {
        while(points[i].x-points[rep].x>h)
        {
            active.erase(points[rep]);
            rep++;
        }

        point left(-INF, points[i].y-h), right(INF, points[i].y+h);
        set<point, cmpY>::const_iterator i1, i2;
        i1=lower_bound(active.begin(), active.end(), left, cmpY());
        i2=upper_bound(active.begin(), active.end(), right, cmpY());

        for(set<point, cmpY>::const_iterator it=i1;it!=i2;it++)
        {
            double d=dist(points[i], *it);
            if(d<h) h=d;
        }
        active.insert(points[i]);
    }
    return h;
}

int main()
{
    scanf("%i", &n);
    for(int i=0;i<n;i++)
        scanf("%i %i", &points[i].x, &points[i].y);

    printf("%lf\n", closest());
    return 0;
}
