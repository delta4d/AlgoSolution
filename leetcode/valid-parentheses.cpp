// 40ms
// basic stack operation
class Solution {
public:
    bool match(char a, char b) {
        return a == '(' && b == ')' || a == '{' && b == '}' || a == '[' && b ==']';
    }
    bool close(char c) {
        return c == ')' || c == '}' || c == ']';
    }
    bool isValid(string s) {
        vector <int> st;
        for (auto c: s) {
            if (close(c)) {
                if (st.empty()) return false;
                if (!match(st.back(), c)) return false;
                st.pop_back();
            } else {
                st.push_back(c);
            }
        }
        return st.empty();
    }
};
