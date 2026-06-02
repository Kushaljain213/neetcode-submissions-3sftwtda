class Solution {
public:
    // vector<pair<int,int>> dir = {{-1,0},{0,-1},{0,1},{1,0}};
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        for(int i = 0 ; i < n ; i++){
            if(board[i][0] == 'O'){
                func(board,i,0);
            }
            if(board[i][m-1] == 'O'){
                func(board,i,m-1);
            }
        }
        for(int j = 0 ; j < m ; j++){
            if(board[0][j] == 'O'){
                func(board,0,j);
            }
            if(board[n-1][j] == 'O'){
                func(board,n-1,j);
            }
        }
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                if(board[i][j] == 'A'){
                    board[i][j] = 'O';
                }
            }
        }
    }
    void func(vector<vector<char>>& grid, int r , int c){
        if(r <0 || c<0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] != 'O'){
            return;
        }
        grid[r][c] = 'A';
        func(grid,r+1,c);
        func(grid,r-1,c);
        func(grid,r,c+1);
        func(grid,r,c-1);
    }
};
