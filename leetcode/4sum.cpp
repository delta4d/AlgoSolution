// 500ms
// O(n^2)
int cnt[10086];
class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        int n = (int)num.size();
        vector <vector <int>> ret;
        sort(begin(num), end(num));
        for (int i=1,cc=1,p=0; i<=n; ++i) {
            if (i == n || num[i] != num[i-1]) cnt[p++] = cc, cc = 1;
            else ++cc;
        }
        num.erase(unique(begin(num), end(num)), end(num));
        n = (int)num.size();
        unordered_map <int, vector <pair <int, int>>> mp;
        for (int i=0; i<n; ++i) {
            if (cnt[i] >= 2) {
                mp[target-(num[i] << 1)].push_back(make_pair(i, i));
            }
            for (int j=i+1; j<n; ++j) {
                mp[target-num[i]-num[j]].push_back(make_pair(i, j));
            }
        }
        for (int i=0; i<n; ++i) {
            if (cnt[i] >= 2) {
                if (mp.count(num[i] << 1)) {
                    for (auto &cc: mp[num[i] << 1]) {
                        if (cc.first >= i && cnt[i] >= 2 + (cc.first == i) + (cc.second == i)) {
                            ret.push_back({num[i], num[i], num[cc.first], num[cc.second]});
                        }
                    }
                }
            }
            for (int j=i+1; j<n; ++j) {
                if (mp.count(num[i] + num[j])) {
                    for (auto &cc: mp[num[i] + num[j]]) {
                        if (cc.first >= j && cnt[j] >= 1 + (cc.first == j) + (cc.second == j)) {
                            ret.push_back({num[i], num[j], num[cc.first], num[cc.second]});
                        }
                    }
                }
            }
        }
        return ret;
    }
};
