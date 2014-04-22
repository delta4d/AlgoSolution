// 140ms
// window scan
const int N = 100086;
int rem[N];
class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        if (L.empty()) return {};
        int n = (int)L.size(), tw = n;
        sort(begin(L), end(L));
        vector <int> cnt;
        for (int i=1,cc=1; i<=n; ++i) {
            if (i == n || L[i] != L[i-1]) cnt.push_back(cc), cc = 1;
            else ++cc;
        }
        L.erase(unique(begin(L), end(L)), end(L));
        n = (int)L.size();
        unordered_map <string, int> idx;
        for (int i=0; i<n; ++i) idx[L[i]] = i;
        int lw = (int)L.front().size(), len = (int)S.size();
        vector <int> ret;
        for (int st=0; st<lw&&st<len; ++st) {
            for (int i=0; i<n; ++i) rem[i] = cnt[i];
            vector <int> id;
            for (int i=st; i+lw<=len; i+=lw) {
                string cc = S.substr(i, lw);
                id.push_back(idx.count(cc) ? idx[cc] : -1);
            }
            int tot = tw, sz = (int)id.size();
            for (int i=0,j=0; j<sz; ++j) {
                if (id[j] == -1) {
                    for (; i<j; ++i) ++rem[id[i]], ++tot;
                    i = j + 1;
                } else {
                    int k = id[j];
                    if (rem[k] == 0) {
                        for (; i<j&&id[i]!=k; ++i) ++rem[id[i]], ++tot;
                        ++i;
                    } else {
                        --rem[k], --tot;
                    }
                }
                if (tot == 0) {
                    ret.push_back(i*lw+st);
                }
            }
        }
        return ret;
    }
};
