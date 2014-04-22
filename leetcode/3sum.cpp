// 244ms
// O(n^2)
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        int n = (int)num.size();
        vector <vector <int>> ret;
        unordered_map <int, int> mp;
        sort(begin(num), end(num));
        for (int i=0; i<n; ++i) {
			mp[num[i]] = min(mp[num[i]] + 1, 2+!num[i]);
		}
		num.erase(unique(begin(num), end(num)), end(num));
		n = (int)num.size();
		for (int i=0,a,b,c; i<n; ++i) {
			a = num[i];
			if (!a) {
				if (mp[a] == 3) ret.push_back({a, a, a});
			} else if (mp[a] >= 2) {
				b = a, c = -(a << 1);
				if (c >= b && mp.count(c)) ret.push_back({a, b, c});
			} 
			for (int j=i+1; j<n; ++j) {
				b = num[j], c = -(a + b);
				if (c >= b && mp.count(c) && mp[c] >= 1 + (c == b)) ret.push_back({a, b, c});
			}
		}
		return ret;
	}
};
