// 716ms
// basics
class Solution {
public:
    bool isPalindrome(int x) {
        char buf[32];
        sprintf(buf, "%d", x);
        for (int i=0,sz=strlen(buf); i+i<sz; ++i) {
            if (buf[i] != buf[sz-i-1]) return false;
        }
        return true;
    }
};
