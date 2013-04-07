nclude <map>
#include <set>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef pair <int, int> PII;
typedef map <int, PII> MIP;
typedef map <PII, int> MPI;

struct MemMgr {
	MIP id;
	MPI ram;
	int m, n;

	MemMgr(int _n=1, int _m=0) { 
		n = _n, m = _m; 
		id.clear(); ram.clear();
		id[-1] = make_pair(0, 0);
		ram[make_pair(0, 0)] = -1;
		id[-2] = make_pair(m+1, m+1);
		ram[make_pair(m+1, m+1)] = -2;
	}

	int alloc(const int sz) {
		MPI::iterator c = ram.begin(), p = c;
		for (++p; p!=ram.end(); c=p,++p) {
			if (p->first.first - c->first.second > sz) {
				PII cc = make_pair(c->first.second + 1, c->first.second + sz);
				ram[cc] = n;
				id[n] = cc;
				printf("%d\n", n);
				return n++;
			}
		}	
		puts("NULL");
		return -1;
	}

	int erase(const int nu) {
		if (nu > 0 && id.count(nu)) {
			ram.erase(id[nu]);
			id.erase(nu);
			return 0;
		}
		puts("ILLEGAL_ERASE_ARGUMENT");
		return -1;
	}

	void defrag() {
		MPI tmp;
		MPI::iterator it = ram.begin();
		tmp.insert(*it);
		int pp = 0;
		for (++it; it!=ram.end(); ++it) {
			if (it->second < 0) break;
			PII p = it->first;
			int k = p.first - pp - 1;
			p.first -= k, p.second -= k;
			tmp.insert(make_pair(p, it->second));
			pp = p.second;
		}
		tmp.insert(*it);
		ram = tmp;
		id.clear();
		for (it=ram.begin(); it!=ram.end(); ++it) id[it->second] = it->first;
	}

	void info() {
		printf("= %d == %d =\n", ram.size(), id.size());
		for (MPI::iterator it=ram.begin(); it!=ram.end(); ++it) {
			printf("ram: [%d %d] => %d\n", it->first.first, it->first.second, it->second);
		}
		for (MIP::iterator it=id.begin(); it!=id.end(); ++it) {
			printf("id : %d => [%d %d]\n", it->first, it->second.first, it->second.second);
		}
	}
};

int main() {
	int t, m, k;
	char op[16];

	scanf("%d%d", &t, &m);
	MemMgr mm(1, m);
	while (t--) {
		scanf("%s", op);
		if (op[0] == 'd') mm.defrag();
		else scanf("%d", &k);
		if (op[0] == 'a') mm.alloc(k);
		else if (op[0] == 'e') mm.erase(k);
//		mm.info();
	}

	return 0;
}

// 3480446	 Apr 6, 2013 7:59:04 PM	delta_4d	 B - Memory Manager	 GNU C++	Accepted	 15 ms	 100 KB
