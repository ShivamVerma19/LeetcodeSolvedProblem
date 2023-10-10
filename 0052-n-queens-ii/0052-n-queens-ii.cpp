class Solution {
public:
    int n;
    // bool isSafe(int r, int c, vector<vector<int>> &board){
    //     //Upper
    //     for(int i = r-1; i >= 0; --i){
    //         if(board[i][c]) return false;
    //     }

    //     //UL
    //     for(int i = r-1, j = c-1; i >= 0 && j >= 0; --i, --j){
    //         if(board[i][j]) return false;
    //     }

    //     //UR
    //     for(int i = r-1, j = c+1; i >= 0 && j < n; --i, ++j){
    //         if(board[i][j]) return false;
    //     }

    //     return true;
    // }
    // int f(int row, vector<vector<int>> &board){
    //     if(row == n) return 1;

    //     int count = 0;
    //     for(int i = 0; i < n; ++i){
    //         if(isSafe(row, i, board)){
    //             board[row][i] = 1;
    //             count += f(row+1, board);
    //             board[row][i] = 0;
    //         }
    //     }
    //     return count;
    // }
    int f(int row, vector<bool> &u, vector<bool> &ul, vector<bool> &ur){
        if(row == n) return 1;
        int count = 0;
        for(int col = 0; col < n; ++col){
            if(u[col] && ul[n-1+row-col] && ur[row+col]){
                u[col] = false;
                ul[n-1+row-col] = false;
                ur[row+col] = false;
                count += f(row+1, u, ul, ur);
                u[col] = true;
                ul[n-1+row-col] = true;
                ur[row+col] = true;
            }
        }
        return count;
    }
    int totalNQueens(int N) {
        n = N;
        // vector<vector<int>> board(n, vector<int>(n, 0));
        vector<bool> u(n, true), ul(2*n-1, true), ur(2*n-1, true);
        return f(0, u, ul, ur);
    }
};