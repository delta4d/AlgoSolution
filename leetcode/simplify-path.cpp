// 72ms
// stack
class Solution {
public:
    string simplifyPath(string path) {
		vector <string> st;
        char token[] = "/";
		char buf[10000];
		strcpy(buf, path.c_str());
        for (char *cp=strtok(buf, token); cp!=NULL; cp = strtok(NULL, token)) {
            string s = cp;
            if (s.empty()) continue;
            if (s == "..") {
				if (!st.empty()) st.pop_back();
			} else if (s != ".") {
				st.push_back(s);
			}
        }
        string ret;
        for (auto &c: st) ret += "/" + c;
        if (ret.empty()) ret = "/";
        return ret;
    }
};
