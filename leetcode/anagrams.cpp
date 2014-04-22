// 164ms
// simulation
class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        unordered_map <string, vector<string>> mp;
        for (auto &c: strs) {
            string cc = c;
            sort(begin(cc), end(cc));
            mp[cc].push_back(c);
        }
        vector <string> ret;
        for (auto &c: mp) if ((int)c.second.size() > 1) {
            ret.insert(end(ret), begin(c.second), end(c.second));
        }
        return ret;
    }
};
