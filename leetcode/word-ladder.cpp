// 896ms
// bfs
class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        int n = (int)dict.size(), lw = (int)(dict.begin()->length());
        unordered_set <string> v;
        queue <pair<string, int>> q;
        q.push(make_pair(start, 1));
        v.insert(start);
        while (!q.empty()) {
            pair <string, int> x = q.front();
            q.pop();
            if (x.first == end) return x.second;
            string cc = x.first;
            for (int i=0; i<lw; ++i) for (int j=0; j<26; ++j) {
                cc[i] = j + 'a';
                if (dict.find(cc) != dict.end() && v.find(cc) == v.end()) {
                    q.push(make_pair(cc, x.second+1));
                    v.insert(cc);
                }
                cc[i] = x.first[i];
            }
        }
        return 0;
    }
};
