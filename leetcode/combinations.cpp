// 44ms
// generating combinations
// like add 1 to a integer
class Solution {
public:
    bool next_p(vector <int> &p, const int n) {
        int k = (int)p.size();
        for (int i=k-1; i>=0; --i) if (p[i] + k - 1 - i < n) {
            ++p[i];
            for (int j=i+1; j<k; ++j) p[j] = p[j-1] + 1;
            return true;
        }
        return false;
    }
    vector<vector<int> > combine(int n, int k) {
        vector <int> p;
        vector <vector<int>> ret;
        for (int i=0; i<k; ++i) p.push_back(i+1);
        do {
            ret.push_back(p);
        } while (next_p(p, n));
        return ret;
    }
};
