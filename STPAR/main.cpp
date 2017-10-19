#include <cstdio>
#include <stack>
using namespace std;

int t[1001];

int main()
{
    int n;
    while(1)
    {
        stack<int> st;
        scanf("%i", &n);
        if(!n) break;
        for(int i=0;i<n;i++)
            scanf("%i", &t[i]);

        int it=0;
        for(int i=0;i<n;i++)
        {
            if(!st.empty() && st.top()==i+1) {st.pop(); continue;}
            while(it<n && t[it]!=i+1)
            {
                st.push(t[it]);
                it++;
            }
            it++;
        }
        if(st.empty()) printf("yes\n");
        else printf("no\n");
    }
}
