/*
class Solution {
    private:
    int f(int i,int j,int n,vector<vector<int>>& matrix,vector<vector<int>>& dp){
        
        if(j<0 || j>=n)return 1e9;
        if(i==0)return matrix[0][j];
        if(dp[i][j]!=-1)return dp[i][j];

        int up=matrix[i][j]+f(i-1,j,n,matrix,dp);
        int dl=matrix[i][j]+f(i-1,j-1,n,matrix,dp);
        int dr=matrix[i][j]+f(i-1,j+1,n,matrix,dp);

        return dp[i][j]=min(up,min(dl,dr));
    }
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int maxi=1e9;
        for(int i=0;i<n;i++){
            maxi=min(maxi,f(n-1,i,n,matrix,dp));
        }
        return maxi;
    }
};
*/
// Tabulation 

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 0) return 0; 
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int j = 0; j < n; j++) {
            dp[0][j] = matrix[0][j];
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int up = dp[i-1][j];
                int diag_left = (j > 0) ? dp[i-1][j-1] : 1e9;
                int diag_right = (j < n - 1) ? dp[i-1][j+1] : 1e9;

                dp[i][j] = matrix[i][j] + min({up, diag_left, diag_right});
            }
        }
        int mini = 1e9;
        for (int j = 0; j < n; j++) {
            mini = min(mini, dp[n-1][j]);
        }
        return mini;
    }
};
