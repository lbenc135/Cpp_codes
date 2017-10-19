// KRIVO
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

int m, k, poc;
char n[10001], w[21];
vector<string> v;
int words;

struct node {
    char c;
    bool isEnd=0;
    node* child[26]={0};
};

void addWord(char *s, int len, node *t)
{
    for(int i=0;i<len;i++)
    {
        if(t->child[s[i]-'a']!=NULL) t=t->child[s[i]-'a'];
        else t=t->child[s[i]-'a']=new node;
        t->c=s[i];
    }
    t->isEnd=1;
}

int main()
{
    node *root=new node;
    node *t=root, *prev=NULL;


    scanf("%i %i", &m, &k);
    scanf("%s", &n);
    int nlen=strlen(n);
    for(int i=0;i<m;i++)
    {
        scanf("%s", &w);
        addWord(w, strlen(w), root);
    }

    int sum=0;
    string s2a;
    for(int i=0;i<nlen;i++)
    {
        if(t->child[n[i]-'a']!=NULL)
        {
            if(s2a!="") s2a+=n[i];
            prev=t;
            t=t->child[n[i]-'a'];
        }
        else
        {
            if(prev!=root && prev->child[n[i]-'a']!=NULL)
            {
                s2a+=n[i];
                t=prev->child[n[i]-'a'];
            }
            else if(poc<i)
            {
                sum+=i-poc;
                poc=i;
                i--;
                prev=t;
                t=root;
            }
            else
            {
                sum++;
                poc=i+1;
                prev=t;
                t=root;
            }
        }
        if(t->isEnd)
        {
            if(s2a!="") { v[v.size()-1].append(s2a); s2a=""; }
            else
            {
                if(sum) { v.push_back(string(sum, '#')); sum=0; }
                string s;
                for(int j=poc;j<=i;j++)
                    s+=n[j];
                v.push_back(s);
                words++;
            }
            poc=i+1;
            prev=t;
            t=root;
        }

    }
    if(sum) v.push_back(string(sum, '#'));

    printf("%i\n", words);
    for(int i=0;i<v.size();i++)
    {
        printf("%s ", v[i].c_str());
    }
}
