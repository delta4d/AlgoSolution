// 136ms
int L[100086], R[100086];
class Solution {
public:
    int candy(vector<int> &ratings) {
        int n = (int)ratings.size();
        if (n < 2) return n;
        L[0] = 0;
        for (int i=1; i<n; ++i) L[i] = ratings[i] > ratings[i-1] ? L[i-1] + 1 : 0;
        R[n-1] = 0;
        for (int i=n-2; i>=0; --i) R[i] = ratings[i] > ratings[i+1] ? R[i+1] + 1 : 0;
        int tot = 0;
        for (int i=0; i<n; ++i) tot += max(L[i], R[i]) + 1;
        return tot;
    }
};
