// 60ms
// hash
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        int ret = 0;
        unordered_set <int> v(begin(num), end(num));
        for (auto x: num) if (v.count(x)) {
            int cc = 1;
            for (int i=1; v.count(x+i); v.erase(x+i),++i,++cc);
            for (int i=1; v.count(x-i); v.erase(x-i),++i,++cc);
            ret = max(ret, cc);
        }
        return ret;
    }
};
