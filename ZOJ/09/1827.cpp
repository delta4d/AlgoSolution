#include <cstdio>
#include <memory>
#include <cstring>
using namespace std;

const int MaxL = 32;
char seq[MaxL];
int card[7];

bool dfs(int sum)
{
	int i;
	for (i=1; i<7; ++i)
	{
		if (card[i] > 0 && sum >= i)
		{
			--card[i];
			if (dfs(sum - i))
			{
				++card[i];
				return false;
			}
			++card[i];
		}
	}
	return true;
}

void gao()
{
	int i;
	int j;
	int sum(31);
	int who(1);
	int len(strlen(seq));
	fill(card, card+7, 4);
	for (i=0; i<len; ++i)
	{
		sum -= seq[i] - '0';
		--card[seq[i]-'0'];
		who ^= 1;
	}
	if (!dfs(sum)) who ^= 1;
	printf("%s %c\n", seq, 'A'+who);
}

int main()
{
	//freopen("f:\\in.txt", "r", stdin);
	while (scanf("%s", seq) != EOF) gao();	
	return 0;
}