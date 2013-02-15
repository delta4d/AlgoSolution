#include <set>
#include <cstdio>
#include <vector>
#include <cstring>
#include <cassert>
#include <algorithm>
using namespace std;

const int MAXN = 200086;
const int off = 5;

set<pair<int, int> > f;
int m, n;
int fx[MAXN], fy[MAXN];
bool visit[MAXN];

struct node {
	int left, right;
	bool mark;
} tt[MAXN*3];

void build_tree(int root, int left, int right) {
	int i, j, k;
	int mid;
	
	tt[root].left = left, tt[root].right = right, tt[root].mark = false;
	if (left >= right) return;
	mid = (right + left) >> 1;
	build_tree(root<<1, left, mid);
	build_tree((root<<1)+1, mid+1, right);
}

void insert(int root, int left, int right) {
	int i, j, k;
	int mid;
	
	if (tt[root].left == left && tt[root].right == right) {
		tt[root].mark = true;
		return;
	}
	mid = (tt[root].right + tt[root].left) >> 1;
	if (right <= mid) {
		insert(root<<1, left, right);
	} else if (left > mid) {
		insert((root<<1)+1, left, right);
	} else {
		insert(root<<1, left, mid);
		insert((root<<1)+1, mid+1, right);
	}
}

void query(int root, int left, int right) {
	int i, j, k;
	int mid;

	if (tt[root].mark) {
		for (i=left; i<=right; ++i) visit[i] = true;
		return;
	}
	if (left >= right) return;
	mid = (right + left) >> 1;
	query(root<<1, left, mid);
	query((root<<1)+1, mid+1, right);
}

int main() {
	int i, j, k;
	int x, y;
	int left, right, mid;
	int px, py;
	int tot;
	
	//freopen("d:\\in.txt", "r", stdin);
	while (2 == scanf("%d %d", &n, &m)) {
		f.clear();
		for (i=0; i<n; ++i) {
			scanf("%d %d", &x, &y);
			f.insert(make_pair(x, y));
		}
		i = 0;
		for (set<pair<int, int> >::iterator it=f.begin(); it!=f.end(); ++it) {
			fx[i] = it->first;
			fy[i++] = it->second;
		}
		n = i;
		build_tree(1, 0, n-1);
		for (i=0; i<m; ++i) {
			scanf("%d %d", &x, &y);
			left = 0, right = n - 1;
			while (left <= right) {
				mid = (right + left) >> 1;
				if (fx[mid] >= x) right = mid - 1;
				else left = mid + 1;
			}
			for (k=-off; k<=off; ++k) {
				if (0 <= mid + k && mid + k < n && fx[mid + k] >= x) break;
			}
			if (k > off) continue;
			px = mid + k;
			left = px, right = n - 1;
			while (left <= right) {
				mid = (right + left) >> 1;
				if (fy[mid] <= y) left = mid + 1;
				else right = mid - 1;
			}
			for (k=off; k>=-off; --k) {
				if (px <= mid + k && mid + k < n && fy[mid + k] <= y) break;
			}
			if (k < -off) continue;
			py = mid + k;
			insert(1, px, py);
		}
		memset(visit, false, sizeof(visit));
		query(1, 0, n-1);
		tot = 0;
		for (i=0; i<n; ++i) tot += visit[i];
		printf("%d\n", n-tot);
		for (i=0; i<n; ++i) if (!visit[i]) printf("%d %d\n", fx[i], fy[i]);
	}

	return 0;
}
