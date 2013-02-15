#define overload 0
#include<cstdio>
#include<queue>
#include<vector>
using namespace std;

struct node
{
    int x;
    int y;

    node(int x=0, int y=0) : x(x), y(y){}
};

#if overload

bool operator<(node a, node b)
{
    if (a.x != b.x)
    {
        return b.x < a.x;
    }
    else
    {
        return a.y < b.y;
    }
}

#else

struct cmp
{
    bool operator()(node &a, node &b)
    {
        if (a.x != b.x)
        {
            return b.x < a.x;
        }
        else
        {
            return a.y < b.y;
        }
    }
};

#endif

int main(void)
{
    int i;
#if overload
    priority_queue<node>f;
#else
	priority_queue<node, vector<node>, cmp>f;
#endif
	    
    node temp;

    f.push(node(1, 2));
    f.push(node(0, 3));
    f.push(node(0, 2));
    temp = f.top();
    printf("x: %d, y: %d\n", temp.x, temp.y);

    return 0;
}
