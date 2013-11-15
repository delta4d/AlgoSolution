#include <set>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXL = 80;
set<double> out;
char buff[MAXL];
char tout[MAXL];
int num[10];
int len;

void dfs(int d) {
	int i, j, k;
	double x;
	if (d == len) {
		tout[len] = tout[len-1];
		tout[len-1] = '.';
		sscanf(tout, "%lf", &x);
		out.insert(x);
		return;
	}
	for (i=0; i<10; ++i) {
		if (num[i] > 0) {
			if (i == 6 || i == 9) {
					--num[i];
					tout[d] = '6';
					dfs(d+1);
					++num[i];
					--num[i];
					tout[d] = '9';
					dfs(d+1);
					++num[i];
			} else if (i == 2 || i == 5) {
					--num[i];
					tout[d] = '2';
					dfs(d+1);
					++num[i];
					--num[i];
					tout[d] = '5';
					dfs(d+1);
					++num[i];
			} else {
				--num[i];
				tout[d] = i + '0';
				dfs(d+1);
				++num[i];
			}
		}
	}
} 

int main() {
	int i, j, k;
	double x;
	//freopen("f:\\in.txt", "r", stdin);
	while (gets(buff)) {
		k = 0;
		while (buff[k] == '0') ++k;
		if (buff[k] == '.') --k;
		strcpy(buff, buff+k);
		len = strlen(buff);
		memset(num, 0, sizeof(num));
		for (i=0; i<len; ++i) {
			if (buff[i] <= '9' && buff[i] >= '0') ++num[buff[i]-'0'];
		}
		--len;
		out.clear();
		tout[len+1] = '\0';
		dfs(0);
		sscanf(buff, "%lf", &x);
		set<double>::iterator it = out.find(x);
		++it;
		if (it == out.end()) puts("The price cannot be raised.");
		else printf("%.1lf\n", *(it));
	}
	return 0;
}