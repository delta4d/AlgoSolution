#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

const char res[2][16] = {"same", "different"};
string s1, s2;

string dfs(string cc) {
	int i, j, k;
	int depth(0);
	int len(cc.length());
    if(cc == "01") return cc ;
    cc = cc.substr(1, len-2);
    vector<string>subtree;
    int start, end;
    for(i=0, start =0; i<len-2; ++i) {
    	depth += cc[i] == '0' ? 1 : -1;
        if(depth == 0) {
            subtree.push_back(dfs(cc.substr(start, i - start + 1)));
            start = i + 1;
        }
    }
    sort(subtree.begin(),subtree.end());
    string ret("0");
    for(i=0; i<subtree.size(); i++) ret += subtree[i];
    return ret+"1";
}

int gao() {
	int i, j, k;
	int len, len1(s1.length()), len2(s2.length());
	if (len1 != len2) return 1;
	len = len1;
	return dfs("0"+s1+"1") == dfs("0"+s2+"1") ? 0 : 1;
}

int main() {
	int i, j, k;
	int n;
	//freopen("f:\\in.txt", "r", stdin);
	scanf("%d", &n);
	for (i=0; i<n; ++i) {
		cin >> s1 >> s2;
		printf("%s\n", res[gao()]);
	}
	return 0;
}