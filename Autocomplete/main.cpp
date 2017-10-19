#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

struct trie_node_t
{
    int value, numch;
    trie_node_t *children[26];
};

struct trie_t
{
    trie_node_t *root;
    int count;
};

trie_node_t *getNode(void)
{
    trie_node_t *pNode = NULL;

    pNode = (trie_node_t *)malloc(sizeof(trie_node_t));

    if(pNode)
    {
        int i;

        pNode->value = 0;
        pNode->numch = 0;

        for(i = 0; i < 26; i++)
        {
            pNode->children[i] = NULL;
        }
    }

    return pNode;
}

void initialize(trie_t *pTrie)
{
    pTrie->root = getNode();
    pTrie->count = 0;
}

void dein(trie_node_t *pTrie)
{
    for(int i = 0; i < 26; i++)
    {
        if(pTrie->children[i]!=NULL) dein(pTrie->children[i]);
        pTrie = NULL;
    }
}

void insert(trie_t *pTrie, char key[])
{
    int level;
    int length = strlen(key);
    int index;
    trie_node_t *pCrawl;

    pTrie->count++;
    pCrawl = pTrie->root;

    for( level = 0; level < length; level++ )
    {
        index = key[level]-'a';
        if( !pCrawl->children[index] )
        {
            pCrawl->numch++;
            pCrawl->children[index] = getNode();
        }

        pCrawl = pCrawl->children[index];
    }
    pCrawl->value = pTrie->count;
}

int search(trie_t *pTrie, char key[], int l, int len)
{
    int level;
    int index;
    int vals=0;
    trie_node_t *pCrawl;

    pCrawl = pTrie->root;

    for( level = 0; level < len; level++ )
    {
        index = key[level]-'a';
        pCrawl = pCrawl->children[index];
        if(level>=l && pCrawl->value) vals++;
        if(level>=l && pCrawl->numch>1) return 1;
    }
    if(vals>1 || pCrawl->numch>0) return 1;
    else return 0;
}

char w[1000000100];

int main()
{
    FILE *fin = fopen("autocomplete.txt", "r");

    int t, n, rj[101]={0}, tempr;
    fscanf(fin, "%i", &t);
    for(int c=0;c<t;c++)
    {
        printf("%i\n", c);
        trie_t trie;
        initialize(&trie);

        tempr=0;
        fscanf(fin, "%i", &n);
        for(int i=0;i<n;i++)
        {
            fscanf(fin, "%s", &w);
            insert(&trie, w);

            int len=strlen(w);
            bool whole=1;
            for(int j=0;j<len;j++)
            {
                int strie=search(&trie, w, j, len);
                if(strie==0)
                {
                    tempr+=j+1;
                    whole=0;
                    break;
                }
            }
            if(whole) tempr+=len;
        }
        rj[c]=tempr;
    }
    for(int i=0;i<t;i++)
        printf("Case #%i: %i\n", i+1, rj[i]);
}
