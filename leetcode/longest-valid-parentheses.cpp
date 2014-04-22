// 88ms
// stack
// store the longest valid seq length
// -1: open tag
// -2: error tag
class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.empty()) return 0;
        vector <int> st;
        for (auto c: s) {
            if (c == '(') {
                st.push_back(-1);
            } else {
                if (st.empty()) {
                    st.push_back(-2);
                } else {
                    if (st.back() == -1) {
                        st.pop_back();
                        st.push_back(1);
                    } else {
                        int n = (int)st.size();
                        if (n > 1 && st[n-1] > 0 && st[n-2] == -1) {
                            st[n-2] = st[n-1] + 1;
                            st.pop_back();
                            --n;
                        } else {
                            st.push_back(-2);
                        }
                    }
                    int n = (int)st.size();
                    while (n > 1 && st[n-1] > 0 && st[n-2] > 0) {
                        st[n-2] += st[n-1];
                        st.pop_back();
                        --n;
                    }
                }
            }
        }
        return max(0, *max_element(begin(st), end(st)) << 1);
    }
};
