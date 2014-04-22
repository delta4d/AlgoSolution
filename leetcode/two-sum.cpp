// 132ms
// O(nlogn)
// sort numbers with their index [O(nlogn)]
// enumerate first number, and make a binary search on the second one [O(nlogn)]
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        const int INF = 0x3f3f3f3f;
        vector <pair<int, int>> num;
        int sz = (int)numbers.size();
        for (int i=sz-1; i>=0; --i) {
            num.push_back(make_pair(numbers[i], i+1));
        }
        sort(begin(num), end(num));
        for (int i=0; i<sz; ++i) {
            int j = lower_bound(begin(num)+i+1, end(num), make_pair(target-num[i].first, -INF)) - begin(num);
            if (0 <= j && j < sz && num[i].first + num[j].first == target) {
                return {min(num[i].second, num[j].second), max(num[i].second, num[j].second)};
            }
        }
    }
};
