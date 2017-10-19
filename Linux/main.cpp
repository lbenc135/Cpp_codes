#include <iostream>
#include <map>
using namespace std;

struct node {
    string ime, put;
    int maps=0;
    node* par;
    map<string, node*> ch;

    node() {}
    node(string i, string p, node* pr)
    {
        ime=i;
        put=p;
        par=pr;
    }
};

void find_print(node *n)
{
    cout << n->put;
    if(n->maps)
        for(map<string,node*>::iterator i=n->ch.begin();i!=n->ch.end();i++)
        {
            if((*i).second)
            {
                cout << ":";
                find_print((*i).second);
            }
        }
}

int main()
{
    int n;
    cin >> n;

    node root("/", "", NULL), *tr;
    tr=&root;

    for(int i=0;i<n;i++)
    {
        string nar, par;
        cin >> nar >> par;
        if(nar=="mkdir")
        {
            if(tr->ch[par]==NULL)
            {
                string put=tr->put+"/"+par;
                cout << put << endl;
                tr->ch[par]=new node(par, put, tr);
                tr->maps++;
            }
            else
                cout << "greska\n";
        }
        else if(nar=="rmdir")
        {
            if(tr->ch[par]!=NULL && tr->ch[par]->maps==0)
            {
                string put=tr->put+"/"+par;
                cout << put << endl;
                tr->ch.erase(par);
                tr->maps--;
            }
            else
                cout << "greska\n";
        }
        else if(nar=="cd")
        {
            if(par=="..")
            {
                if(tr==&root)
                    cout << "greska\n";
                else
                {
                    tr=tr->par;
                    if(tr==&root)
                        cout << "/\n";
                    else
                        cout << tr->put << endl;
                }
            }
            else
            {
                if(tr->ch[par]!=NULL)
                {
                    tr=tr->ch[par];
                    cout << tr->put << endl;
                }
                else
                    cout << "greska\n";
            }
        }
        else if(nar=="find")
        {
            if(tr->ch[par]!=NULL)
            {
                find_print(tr->ch[par]);
                cout << endl;
            }
            else
                cout << "greska\n";
        }
    }
}
