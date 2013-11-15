#include <queue>
#include <cstdio>
#include <vector>
#include <memory>
#include <algorithm>
using namespace std;

const int INF = 0x7fffffff;
const int MaxN = 50002;
struct node
{
	int t;
	int w;
	node(int t=-1, int w=-INF) : t(t), w(w){}
};
int d[MaxN];
bool visit[MaxN];

int main()
{
	int i;
	int j;
	int k;
	int n;
	int s;
	int t;
	int w;
	int start;
	int end;
	int index;
	node ss;
	node tt;
	
	//freopen("f:\\in.txt", "r", stdin);
	while (scanf("%d", &n) != EOF)
	{
		vector<node>conn[MaxN];
		vector<node>::iterator it;
		start = INF;
		end = -INF;
		for (i=0; i<n; ++i)
		{
			scanf("%d %d %d", &s, &t, &w);
			ss.t = s;
			ss.w = -w;
			conn[t+1].push_back(ss);
			start = min(start, s);
			end = max(end, t);
		}
		++end;
		ss.t = start + 1;
		ss.w = 1;
		conn[start].push_back(ss);
		for (i=start+1; i<=end; ++i)
		{
			ss.t = i - 1;
			ss.w = 0;
			conn[i].push_back(ss);
			ss.t = i + 1;
			ss.w = 1;
			conn[i].push_back(ss);
		}
		//SPFA
		queue<node>q;
		memset(visit, false, sizeof(visit));
		fill(d, d+MaxN, INF);
		ss.t = end;
		ss.w = 0;
		d[end] = 0;
		q.push(ss);
		visit[end] = true;
		while (!q.empty())
		{
			ss = q.front();
			q.pop();
			index = ss.t;
			visit[index] = false;
			for (it=conn[index].begin(); it!=conn[index].end(); ++it)
			{
				tt.t = (*it).t;
				tt.w = d[index] + (*it).w;
				if (tt.w < d[(*it).t])
				{
					d[(*it).t] = tt.w;
					if (!visit[(*it).t])
					{
						visit[(*it).t] = true;
						q.push(tt);
					}
				}
			}
		}
		
		printf("%d\n", -d[start]);
	}
	
	return 0;
}