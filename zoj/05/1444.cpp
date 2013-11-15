#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXP = 101;
const int MAXN = 10001;
const int MAXL = 31;
const int PER = 20;

struct node {
	char name[MAXL];
	int sloved;
	int penalty;
	bool is_sloved[MAXP];
	int temp_penalty[MAXP];
	
	node(int _sloved=0, int _penalty=0):sloved(_sloved), penalty(_penalty) {
		memset(name, '\0', sizeof(name));
		memset(is_sloved, false, sizeof(is_sloved));
		memset(temp_penalty, 0, sizeof(temp_penalty));
	}
	bool equal(const node &a) {
		return sloved == a.sloved && penalty == a.penalty;
	}
	void set_name(char tname[]) {
		strcpy(name, tname);
	}
	bool is_me(char tname[]) {
		return strcmp(name, tname) == 0;
	}
	void deal_record(int stime, int pid, char statue[]) {
		if (is_sloved[pid]) return;
		if (strcmp(statue, "AC") == 0) {
			is_sloved[pid] = true;
			++sloved;
			penalty += temp_penalty[pid];
			penalty += stime;
		} else {
			temp_penalty[pid] += PER;
		}
	}
	void output(bool first, const int rank) {
		if (first) printf("%-10d%-30s%-10d%d\n", rank, name, sloved, penalty);
		else printf("          %-30s%-10d%d\n", name, sloved, penalty);
	}
} f[MAXN];

inline bool cmp(const node &a, const node &b) {
	if (a.sloved == 0) return false;
	if (b.sloved == 0) return true;
	if (a.sloved != b.sloved) return a.sloved > b.sloved;
	if (a.penalty != b.penalty) return a.penalty < b.penalty;
	return strcmp(a.name, b.name) < 0;
}

inline int find_name(const int n, char name[]) {
	for (int i=0; i<n; ++i) if (f[i].is_me(name)) return i;
	return n;
}

int main() {
	int i, j, k;
	int m, n, p;
	int stime, pid;
	int rank;
	char name[MAXL], statue[MAXL];
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &p);
	n = 0;
	while (scanf("%d %s %d %s", &stime, name, &pid, statue) == 4) {
		k = find_name(n, name);
		if (k == n) {
			f[k].set_name(name);
			++n;
		}
		f[k].deal_record(stime, pid, statue);
	}
	sort(f, f+n, cmp);
	rank = 1;
	if (f[0].sloved == 0) return 0;
	f[0].output(true, rank);
	for (i=1; i<n; ++i) {
		if (f[i].sloved == 0) break;
		f[i].output(!f[i].equal(f[i-1]), i+1);
	}
	return 0;
}