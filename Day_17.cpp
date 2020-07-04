// Time Complexity : O(N*M)
// Space Complexity : O(N*M)
class Solution {
public:
    int n,m;    
    void capture(int i,int j,vector<vector<char>>& board){
        board[i][j]='#';
        int x[]={i,i,i+1,i-1};
        int y[]={j+1,j-1,j,j};
        for(int k=0;k<4;k++)
            if(x[k]>=0 && y[k]>=0 && x[k]<=n-1 && y[k]<=m-1 && board[x[k]][y[k]]=='O')
            capture(x[k],y[k],board);
    }
    void solve(vector<vector<char>>& board) {
        if(board.empty())
            return;
        n=board.size();m=board[0].size();
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if((i==0 || j==0 || i==n-1 || j==m-1 ) && board[i][j]=='O' ){                    
                  capture(i,j,board);
                }
        
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                if(board[i][j]=='#')
                    board[i][j]='O';
                else
                    board[i][j]='X';
    }
};
