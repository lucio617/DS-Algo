class Solution {
public:
    bool func(int i,vector<int>& nums,int s,vector<vector<int>> &dp)
    {
        if(dp[i][s]!=-1)
            return dp[i][s];
        if(s==0)
            return true;
        if(i==nums.size())
            return false;
        //pick
        bool pick=false;
        if(s>=nums[i])
        {
            pick=func(i+1,nums,s-nums[i],dp);
        }
        //not pick
        bool not_pick=func(i+1,nums,s,dp);
        if((pick or not_pick)==true)
            dp[i][s]=1;
        else if((pick or not_pick)==false)
            dp[i][s]=0;
        return pick or not_pick;// if any of the tree paths gives true then its true
        
    }
    bool canPartition(vector<int>& nums) {
       int ts=accumulate(nums.begin(),nums.end(),0);
       int n=nums.size();
        
        if(ts%2!=0)
            return false;
        else
        {
            int s=ts/2;
            vector<vector<int>> dp(n+1,vector<int>(s+1,-1));
            return func(0,nums,s,dp);
            }
    }
};