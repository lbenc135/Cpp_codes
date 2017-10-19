#include <cstdio>
#include <vector>
#include <cmath>
#include <stack>
#include <algorithm>
using namespace std;

const int INF = 1000000000;

struct point {
    int x, y;
    point() {}
    point(int a, int b) { x=a; y=b; }
    bool operator<(const point& p) const
    {
        if(x!=p.x) return x<p.x;
        else return y<p.y;
    }
};

int n;
vector<point> g;
stack<point> st;

int orient(point o, point a, point b)
{
    return (a.x-o.x)*(b.y-o.y)-(a.y-o.y)*(b.x-o.x);
}

double dist(point a, point b) { return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2)); }

bool cmp(point a, point b)
{
    int o=orient(g[0], a, b);
    if(o==0) return dist(a, g[0])<dist(b, g[0]);
    else if(o>0) return true;
    return false;
}

point druga()
{
    point temp=st.top(), rez;
    st.pop();
    rez=st.top();
    st.push(temp);
    return rez;
}

void convex_hull()
{
    // Find lowest leftest point
    int miny=INF, minx=INF, it;
    for(int i=0;i<n;i++)
    {
        if(g[i].y<miny) { miny=g[i].y; minx=g[i].x; it=i; }
        else if(g[i].y==miny && g[i].x<minx) { minx=g[i].x; it=i; }
    }
    swap(g[0], g[it]);

    // Sort by angle
    sort(g.begin()+1, g.end(), cmp);

    // Push first 3 to stack
    for(int i=0;i<3;i++) st.push(g[i]);

    for(int i=3;i<n;i++)
    {
        while(st.size()>1 && orient(druga(), st.top(), g[i])<0)
            st.pop();
        st.push(g[i]);
    }
}

int main()
{
    scanf("%i", &n);
    for(int i=0;i<n;i++)
    {
        int x, y;
        scanf("%i %i", &x, &y);
        g.push_back(point(x, y));
    }

    convex_hull();
    for(int i=0;!st.empty();i++)
    {
        printf("\n%i %i", st.top().x, st.top().y);
        st.pop();
    }

}
