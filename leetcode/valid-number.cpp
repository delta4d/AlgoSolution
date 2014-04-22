// 124ms
// NASTY
class Solution {
public:
    bool _is_oct(char s[], int len) { // 8, 0??
        if (s[0] != '0') return false;
        for (int i=1; i<len; ++i) if (s[i] < '0' || s[i] > '7') return false;
        return true;
    }
    bool _is_dec(char s[], int len) { // 10, ???
		if (len <= 0) return false;
        for (int i=0; i<len; ++i) if (s[i] < '0' || s[i] > '9') return false;
        return true;
    }
    bool _is_hex(char s[], int len) { // 16, 0x??
        if (s[0] != '0' || s[1] != 'x' || s[1] != 'X') return false;
        for (int i=2; i<len; ++i) if (!('0' <= s[i] && s[i] <= '9') || 
        !('a' <= s[i] && s[i] <= 'f') || !('A' <= s[i] && s[i] <= 'F')) return false;
        return true;
    }
    bool _is_float(char s[], int len) { //.1, 0.1, 00.01
		if (s[0] == '.' && len == 1) return false;
        bool dot = false;
        for (int i=0; i<len; ++i) {
            if (s[i] == '.') {
                if (dot) return false;
                dot = true;
                continue;
            }
            if (s[i] < '0' || s[i] > '9') return false;
        }
        return true;
    }
 	bool _is_exp(char s[], int len) { // 0e10, 1e-10
        for (int i=0; i<len; ++i) {
            if (s[i] == 'e') {
//                s[i] = '\0';
                return (_is_dec(s, i) || _is_float(s, i)) && 
                i && _is_dec(s+i+1+(s[i+1]=='-'||s[i+1]=='+'), len-i-1-(s[i+1]=='-'||s[i+1]=='+'));
            }
        }
        return false;
    }
    bool _is_num(char s[], int len) {
        if (len <= 0) return false;
        return _is_oct(s, len) || _is_dec(s, len) || _is_hex(s, len) || _is_float(s, len) || _is_exp(s, len);
    }
    bool isNumber(const char *s) {
        char buf[80]="";
        int p = 0, len = 0;
        for (; s[p]==' '; ++p);
        for (; s[p]; buf[len++]=s[p++]) if (s[p] == ' ') {
            for (; s[p]==' '; ++p); --p;
        }
        for (; len&&buf[len-1]==' '; --len);
        if (buf[p=0] == '-' || buf[p] == '+') ++p;
        return _is_num(buf+p, len-p);
    }
};
