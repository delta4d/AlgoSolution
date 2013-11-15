#include <cstdio>
#include <memory>

using namespace std;

const int MaxL = 8001;
int cnt[MaxL];

struct node
{
	int ld;
	int rd;
	int c;
	node *lc;
	node *rc;
	
	node(int ld, int rd) : ld(ld), rd(rd)
	{
		c = -1;
		lc = NULL;
		rc = NULL;
	}
};

node *build_tree(int left, int right)
{
	int mid = (left + right) / 2;
	node *temp = new node(left, right);
	
	if (right - left > 1)
	{
		temp -> lc = build_tree(left, mid);
		temp -> rc = build_tree(mid, right);
	}
	
	return temp;
}

void insert(node *root, int left, int right, int color)
{
	int mid;
	
	if (root -> ld == left && root -> rd == right || root -> c == color)
	{
		root -> c = color;
		return;
	}
	
	if (root -> c >= 0)
	{
		root -> lc -> c = root -> c;
		root -> rc -> c = root -> c;
	}
	
	root -> c = -2;
	mid = (root -> ld + root -> rd) / 2;
	
	if (right <= mid)
	{
		insert(root -> lc, left, right, color);
	}
	else if (left >= mid)
	{
		insert(root -> rc, left, right, color);
	}
	else
	{
		insert(root -> lc, left, mid, color);
		insert(root -> rc, mid, right, color);
	}
}

void search(node *root, int &color)
{
	if (root -> c >= 0 && color != root -> c)
	{
		color = root -> c;
		++cnt[color];
	}
	else if (root -> c == -2)
	{
		search(root -> lc, color);
		search(root -> rc, color);
	}
	else
	{
		color = root -> c;
	}
}

int main(void)
{
	int s;
	int d;
	int c;
	int n;
	int i;
	node *root;
	
	while (scanf("%d", &n) != EOF)
	{
		root = build_tree(0, MaxL);
		for (i=0; i<n; ++i)
		{
			scanf("%d %d %d", &s, &d, &c);
			insert(root, s, d, c);
		}
		
		memset(cnt, 0, sizeof(cnt));
		int c(-1);
		search(root, c);
		for (i=0; i<MaxL; ++i)
		{
			if (cnt[i])
			{
				printf("%d %d\n", i, cnt[i]);
			}
		}
		printf("\n");
	}
	
	return 0;
}
