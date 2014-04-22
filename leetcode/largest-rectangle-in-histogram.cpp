// 88ms
// O(n)
// enumerate the lowest
// left[i] is the first bar lower than bar i on the left
// right[i] is the first bar lower than bar i on the right
const int MAXN = 1e5 + 86;
class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        if (height.empty()) return 0;
        int left[MAXN], right[MAXN], n = (int)height.size(), ret = 0;
        left[0] = -1;
        for (int i=1,j; i<n; ++i) {
            for (j=i-1; j>=0&&height[j]>=height[i]; j=left[j]);
            left[i] = j;
        }
        right[n-1] = n;
        for (int i=n-2,j; i>=0; --i) {
            for (j=i+1; j<n&&height[j]>=height[i]; j=right[j]);
            right[i] = j;
        }
        for (int i=0; i<n; ++i) {
            ret = max(ret, height[i] * (right[i] - left[i] - 1));
        }
        return ret;
    }
};


// 88ms
// monotonous queue
const int MAXN = 1e5 + 86;
class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        if (height.empty()) return 0;
        int st[MAXN], left[MAXN], right[MAXN], n = (int)height.size(), ret = 0;
        for (int i=0,p=0; i<n; ++i) {
            for (; p>0&&height[st[p-1]]>=height[i]; --p);
            left[i] = p > 0 ? st[p-1] : -1;
            st[p++] = i;
        }
        for (int i=n-1,p=0; i>=0; --i) {
            for (; p>0&&height[st[p-1]]>=height[i]; --p);
            right[i] = p > 0 ? st[p-1] : n;
            st[p++] = i;
        }
        for (int i=0; i<n; ++i) {
            ret = max(ret, height[i] * (right[i] - left[i] - 1));
        }
        return ret;
    }
};
