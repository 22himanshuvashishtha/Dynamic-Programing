class Solution {
    private:
    int findmax(vector<int>& nums){
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
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        vector<int>temp1,temp2;
        for(int i=0;i<n-1;i++){
            temp1.push_back(nums[i]);
        }
        for(int i=1;i<n;i++){
            temp2.push_back(nums[i]);
        }
        if(nums.size()==1)return nums[0];
        int ans=findmax(temp1);
        int ans2=findmax(temp2);
        return max(ans,ans2);
    }
};
