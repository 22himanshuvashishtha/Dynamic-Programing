/* class Solution {
    private:
    int f(int n,vector<int>& nums,vector<int>& dp){
        if(n==0)return nums[n];
        if(n<0)return 0;
        if(dp[n]!=-1)return dp[n];

        int take=nums[n]+f(n-2,nums,dp);
        int not_t=0+f(n-1,nums,dp);
        return dp[n]=max(take,not_t);
    }
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return f(n-1,nums,dp);
    }
};

class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        dp[0]=nums[0];
        int neg=0;
        for(int i=1;i<n;i++){
        int take=nums[i];
        if(i>1){
            take+=dp[i-2];
        }
        int not_t=0+dp[i-1];
        dp[i]=max(take,not_t);
        }
        return dp[n-1];
    }
};
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int prev1,prev2=0;
        prev1=nums[0];
        for(int i=1;i<n;i++){
        int take=nums[i];
        if(i>1){
            take+=prev2;
        }
        int not_t=0+prev1;
        int curr=max(take,not_t);
        prev2=prev1;
        prev1=curr;
        }
        return prev1;
    }
};
