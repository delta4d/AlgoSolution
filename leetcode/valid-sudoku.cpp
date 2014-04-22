// 76ms
// simulation, bits
class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        int state[27] = {0};
        for (int i=0; i<9; ++i) for (int j=0; j<9; ++j) if (board[i][j] != '.') {
            int c = 1 << (board[i][j] - '0');
            if (state[9+i] & c) return false;
            if (state[18+j] & c) return false;
            if (state[i/3*3+j/3] & c) return false;
            state[9+i] |= c, state[18+j] |= c, state[i/3*3+j/3] |= c;
        }
        return true;
    }
};
