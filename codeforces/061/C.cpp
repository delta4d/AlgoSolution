#include <set>
#include <map>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef set<string> SS;
typedef vector<string> VS;
typedef map<string, int> MSI;
typedef MSI::iterator MSII;

MSI subfile, file;
VS flist;
SS fc;

int main() {
	int m, n;
	int i, j, k;
	int max_subfile, max_file;
	string s, x;
	//freopen("f:\\in.txt", "r", stdin);
	while (cin >> s) {
		flist.clear();
		for (i=3; s[i]; ++i) {
			if (s[i] == '\\') flist.push_back(s.substr(0, i));
		}
		n = flist.size();
		for (i=0; i!=n; ++i) {
			if (fc.find(flist[i]) == fc.end()) {
				for (j=0; j!=i; ++j) {
					if (subfile.find(flist[j]) == subfile.end()) subfile.insert(make_pair(flist[j], 1));
					else ++subfile[flist[j]];
				}
				fc.insert(flist[i]);
			}
			if (file.find(flist[i]) == file.end()) file.insert(make_pair(flist[i], 1));
			else ++file[flist[i]];
		}
	}
	max_subfile = 0, max_file = 0;
	for (MSII it=subfile.begin(); it!=subfile.end(); ++it) max_subfile = max(max_subfile, it->second);
	for (MSII it=file.begin(); it!=file.end(); ++it) max_file = max(max_file, it->second);
	printf("%d %d\n", max_subfile, max_file);
	return 0;
}

// 330667	 Mar 11, 2011 10:11:33 AM	delta_4d	 C - Petya and File System	 GNU C++	Accepted	 230 ms	 2100 
