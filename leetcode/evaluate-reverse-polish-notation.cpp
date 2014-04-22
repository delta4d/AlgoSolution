// 8ms
// basic stack operation
class Solution {
public:
	int evalRPN(vector<string> &tokens) {
		vector <int> st;
		for (auto &op: tokens) {
			if ('0' <= op.back() && op.back() <= '9') {
				st.push_back(atoi(op.c_str()));
			} else {
				int n = (int)st.size();
				assert(n >= 2);
				if (op[0] == '+') st[n-2] += st[n-1];
				else if (op[0] == '-') st[n-2] -= st[n-1];
				else if (op[0] == '*') st[n-2] *= st[n-1];
				else if (op[0] == '/') st[n-2] /= st[n-1];
				st.pop_back();
			}
		}
		return st.front();
	}
};
