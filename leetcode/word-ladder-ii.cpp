// 984ms
// bfs/dfs
const int N = 100086;
const int INF = 0x3f3f3f3f;
unordered_map <string, int> mp;
vector <string> ss;
queue <int> q;
int d[N];
bool v[N];
vector <vector <int>> e;
class Solution {
public:
    void bfs(int s, int t, int n) {
        memset(d, 0xff, sizeof(d));
        while (!q.empty()) q.pop();
        q.push(s), d[s] = 0;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (auto &y: e[x]) if (d[y] == -1) {
                d[y] = d[x] + 1;
                q.push(y);
            }
        }
    }
    void dfs(int s, int t, int n, vector <string> &cc, vector <vector <string>> &ret) {
        if (s == t) {
            ret.push_back(cc);
            return;
        }
        for (auto i: e[s]) if (!v[i] && d[i] == d[s] + 1) {
            v[i] = true, cc.push_back(ss[i]);
            dfs(i, t, n, cc, ret);
            v[i] = false, cc.pop_back();
        }
    }
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        mp.clear(), ss.clear();
        dict.insert(start), dict.insert(end);
        int cnt = 0;
        for (auto &s: dict) mp[s] = cnt++, ss.push_back(s);
        int n = (int)dict.size(), lw = (int)(dict.begin()->length());
        e.resize(n);
        for (auto &s: dict) {
            int i = mp[s];
            e[i].clear();
            string w = s;
            for (int k=0; k<lw; ++k) {
                for (int t=0; t<26; ++t) {
                    w[k] = t + 'a';
                    if (w[k] != s[k] && mp.count(w)) e[i].push_back(mp[w]);
                    w[k] = s[k];
                }
            }
        }
        bfs(mp[start], mp[end], n);
        vector <string> cc;
        vector <vector <string>> ret;
        cc.push_back(start);
        memset(v, false, sizeof(v));
        v[mp[start]] = true;
        dfs(mp[start], mp[end], n, cc, ret);
        return ret;
    }
};
