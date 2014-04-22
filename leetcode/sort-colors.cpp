// 8ms
// put 0 to front, 2 to end 
class Solution {
public:
    void sortColors(int A[], int n) {
		for (int head=0, tail=n-1, p=head; p<=tail&&head<=tail; ++p) {
			if (A[p] == 0 && p != head) swap(A[head++], A[p--]);
			else if (A[p] == 2) swap(A[tail--], A[p--]);
		}
    }
};
