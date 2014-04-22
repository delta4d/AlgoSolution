// 144ms
// same code as permutations.cpp
class Solution {
public:
    bool next_p(int n, vector <int> &p) {
        for (int i=n-1; i>0; --i) if (p[i] > p[i-1]) {
            for (int j=n-1; j>=i; --j) if (p[j] > p[i-1]) {
                swap(p[i-1], p[j]);
                reverse(begin(p)+i, end(p));
                return true;
            }
        }
        return false;
    }
    vector<vector<int> > permuteUnique(vector<int> &num) {
        vector <vector <int>> ret;
        int n = (int)num.size();
        sort(begin(num), end(num));
        do {
            ret.push_back(num);
        } while (next_p(n, num));
        return ret;
    }
};
