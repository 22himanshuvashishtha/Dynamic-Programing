class Solution {
    private:
    int f(int no,vector<int>& dp){
        if(no==1)return 1;
        if(no==0)return 1;
        
        if (dp[no] != -1) return dp[no];
        int left=f(no-1,dp);
        int right=f(no-2,dp);
        return dp[no]=left+right;
    }
public:
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return f(n,dp);
    }
};
