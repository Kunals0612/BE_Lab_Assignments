#include<bits/stdc++.h>
using namespace std;

class NQueens{
    private:
        bool isSafe(int row, int col, vector<string>& board, int n){
            int dupRow = row;
            int dupCol = col;

            while(row >= 0 && col >= 0){
                if(board[row][col] == 'Q'){
                    return false;
                }
                row--;
                col--;
            }

            row = dupRow;
            col = dupCol;

            while(col >= 0){
                if(board[row][col] == 'Q'){
                    return false;
                }
                col--;
            }

            col = dupCol;

            while(row < n && col >= 0){
                if(board[row][col] == 'Q'){
                    return false;
                }
                row++;
                col--;
            }

            return true;
        }
        void solve(int col, int n, vector<string>& board, vector<vector<string>>& ans){
            if(col == n){
                ans.push_back(board);
                return;
            }
            for(int row = 0; row < n; row++){
                if(isSafe(row,col,board,n)){
                    board[row][col] = 'Q';
                    solve(col+1,n,board,ans);
                    board[row][col] = '.';
                }
            }
        }
        void printAns(vector<vector<string>>& ans){
            int count = 1;
            for(auto& board : ans){
                cout << "Solution: " << count << endl;
                for(int i = 0; i < board.size(); i++){
                    for(int j = 0; j < board[i].size(); j++){
                        cout << board[i][j] << " ";
                    }
                    cout << endl;
                }
                count++;
                cout << endl;
            }
        }
    public:
        vector<vector<string>> solveNQueens(int n){
            vector<vector<string>> ans;
            vector<string> board(n);
            string s(n, '.');
            for(int i = 0; i < n; i++){
                board[i] = s;
            }
            solve(0, n, board, ans);
            printAns(ans);
            return ans;
        }
};

int main(){
    NQueens nq;
    nq.solveNQueens(4);
}