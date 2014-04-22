// 44ms
// simulation
class Solution {
public:
    bool isPalindrome(string s) {
        s.erase(remove_if(begin(s), end(s), [](char c) {
            return ::ispunct(c) || ::isspace(c);    
        }), end(s));
        for (int i=0,n=(int)s.length(); i+i<n; ++i) {
            if (tolower(s[i]) != tolower(s[n-1-i])) return false;
        }
        return true;
    }
};
