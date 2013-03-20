#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int p2[] = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048};

struct par {
	int left;
	int right;
	par(int _left, int _right):left(_left), right(_right) {}
};

vector<par> tran[15][11];
vector<char> tree[12];
char buff[128];

inline bool leaf(int cd, int cl) {
	return tree[cd][cl] == '*';
}

bool dfs(int signal, int cd, int cl, const int L, const int low) {
	int i, j, k;
	if (leaf(cd, cl)) return signal >= low;
	for (i=0; i!=tran[signal][tree[cd][cl]-'a'].size(); ++i) {
		par temp = tran[signal][tree[cd][cl]-'a'][i];
		if (dfs(temp.left, cd+1, cl<<1, L, low) && dfs(temp.right, cd+1, (cl<<1)+1, L, low)) return true;
	}
	return false;
}

int main() {
	int i, j, k;
	int m, n;
	int cn(0);
	int x, y, offset;
	int L;
	char *cp;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d %d %d", &n, &m, &k);
	while (true) {
		gets(buff);
		for (i=0; i<n; ++i) for (j=0; j<k; ++j) tran[i][j].clear();
		// read table
		for (i=0; i<n; ++i) {
			for (j=0; j<k; ++j) {
				gets(buff);
				cp = strtok(buff, " \n");
				while (cp != NULL) {
					sscanf(cp, "%d", &x);
					cp = strtok(NULL, " \n");
					sscanf(cp, "%d", &y);
					cp = strtok(NULL, " \n");
					tran[i][j].push_back(par(x, y));
				}
			}
		}
		printf("NTA%d:\n", ++cn);
		// read tree
		while (scanf("%d", &L), L+1) {
			for (i=0; i<=L+1; ++i) tree[i].clear();
			for (i=0; i<=L; ++i) {
				for (j=0; j<p2[i]; ++j) {
					scanf("%s", buff);
					tree[i].push_back(buff[0]);
				}
			}
			for (j=0; j<p2[i]; ++j) tree[i].push_back('*');
			puts(dfs(0, 0, 0, L, n-m)?"Valid":"Invalid");
		}
		scanf("%d %d %d", &n, &m, &k);
		if (n || m || k) puts("");
		else break;
	}
	return 0;
}