#include <cstdio>
#include <list>
#include <algorithm>
using namespace std;

#define INF 1000000000000000000L

struct balon
{
    int val;
    long long left, right;
};

list<balon> balons;

void updateBaloonTime(list<balon>::iterator it)
{
    list<balon>::iterator next = it;
    next++;

    if(it==balons.begin()) it->left=INF;
    if(next==balons.end()) return;

    if (next->val < it->val)
        next->left = INF;
    else if (next->val < it->val*2)
        next->left = 0;
    else
        next->left = next->val - it->val * 2;

    if (it->val < next->val)
        it->right = INF;
    else if (it->val < next->val*2)
        it->right = 0;
    else
        it->right = it->val - next->val * 2;
}

void updateTimes()
{
    for (list<balon>::iterator it = balons.begin(); it != balons.end(); ++it)
	{
		updateBaloonTime(it);
	}
}

long long GetNextTime ()
{
	long long nextTime = INF;

	for (list<balon>::iterator it = balons.begin(); it != balons.end(); ++it)
	{
		nextTime = min (nextTime, min (it->left, it->right));
	}

	return nextTime;
}

void PopBaloons ()
{
	bool endReached = false;

	while (!endReached)
	{
		if (min (balons.begin()->left, balons.begin()->right) == 0)
		{
			balons.erase(balons.begin());

			updateBaloonTime (balons.begin());
		}

		for (list<balon>::iterator it = balons.begin(); it != balons.end(); ++it)
		{
			list<balon>::iterator next = it;
			++next;

			if (next == balons.end())
			{
				endReached = true;
				break;
			}

			if (min (next->left, next->right) == 0)
			{
				balons.erase(next);

				updateBaloonTime(it);

				break;
			}
		}
	}
}

void GrowBaloons (long long growTime)
{
	for (list<balon>::iterator it = balons.begin(); it != balons.end(); ++it)
	{
		it->val += growTime;
	}
}

int main()
{
    int n;
    scanf("%i", &n);
    balon b;
    for(int i=0;i<n;i++)
    {
        scanf("%i", &b.val);
        b.left=b.right=INF;
        balons.push_back(b);
    }

    long long t=0;
    updateTimes();
    while (balons.size() > 1)
	{
		long long td = GetNextTime();

		t += td;

		GrowBaloons(td);

		updateTimes();

		PopBaloons();
	}

    printf("%lli\n", t);
}
