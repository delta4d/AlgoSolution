#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<queue>
using namespace std;

struct Q
{
	char message[10];
	long para;
	long priority;
	long rank;
	
	bool operator < (const Q &a) const
	{
		if (priority != a.priority)
		{
			return priority > a.priority;
		}
		else
		{
			return rank > a.rank;
		}
	}
	
	void print()
	{
		printf("%s %d\n", message, para);
	}
	
};

int main(void)
{
	char order[10];
	char meg[10];
	int num = 0;
	priority_queue<Q>f;
	Q temp;
	
	while (scanf("%s", order) != EOF)
	{
		if (strcmp(order, "GET") == 0)
		{
			if (f.empty())
			{
				printf("EMPTY QUEUE!\n");
			}
			else
			{
				temp = f.top();
				f.pop();
				temp.print();
			}
		}
		else
		{
			scanf("%s %ld %ld", temp.message, &temp.para, &temp.priority);
			temp.rank = num;
			++num;
			f.push(temp);
		}
	}
	
	return 0;
}
