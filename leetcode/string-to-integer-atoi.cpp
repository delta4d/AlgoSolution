// 112ms
// need to know what atoi does

class Solution {
public:
    int atoi(const char *str) {
        int sgn = 1, i;
        long long sum = 0, ret = 0;
        for (i=0; str[i]==' '; ++i);
        if (str[i] == '-') sgn = -1, ++i;
        if (str[i] == '+') sgn = 1, ++i;
        for (; str[i]; ++i) {
            if ('0' <= str[i] && str[i] <= '9') {
                sum = sum * 10 + str[i] - '0';
                ret = sum * sgn;
                if (ret > INT_MAX) {
                    ret = INT_MAX;
                    break;
                }
                if (ret < INT_MIN) {
                    ret = INT_MIN;
                    break;
                }
            } else {
                break;
            }
        }
        return ret;
    }
};
