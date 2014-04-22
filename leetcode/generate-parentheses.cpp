// 36ms
// dfs
class Solution {
public:
    void _g(int sum, int d, int n, vector <char> &st, vector <string> &ret) {
        if (d + sum > 2 * n) return;
        if (d == 2 * n) {
            string cc;
            for (auto c: st) cc += c;
            ret.push_back(cc);
            return;
        }
        if (sum == 0) {
            st.push_back('(');
            _g(sum+1, d+1, n, st, ret);
            st.pop_back();
        } else {
            st.push_back('(');
            _g(sum+1, d+1, n, st, ret);
            st.back() = ')';
            _g(sum-1, d+1, n, st, ret);
			st.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector <string> ret;
        vector <char> st;
        _g(0, 0, n, st, ret);
        return ret;
    }
};
