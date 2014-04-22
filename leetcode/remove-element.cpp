// 12ms
// read comprehension
class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        for (int i=0; i<n; ++i) if (A[i] == elem) {
            A[i--] = A[--n];
        }
        return n;
    }
};
