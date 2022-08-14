class Solution {
public:
    int helper(int ind ,vector<int>& nums,int a,int b, vector<vector<int>>& dp){
       int diff=abs(a-b);
        
        if(ind==nums.size())
            return diff;
        if(dp[ind][diff]!=-1)
            return dp[ind][diff];
        int left_sub=helper(ind+1,nums,a+nums[ind],b,dp);
        int right_sub=helper(ind+1,nums,a,b+nums[ind],dp);
        return dp[ind][diff]=min(left_sub,right_sub);
    }
    int lastStoneWeightII(vector<int>& stones) {
        vector<vector<int>> dp(31 ,vector<int>(3001,-1));
        return helper(0,stones,0,0,dp);
       
        
    }
//       int dp[31][3001];
//     int solve(vector<int>& s,int idx,int a,int b)
//     {
//         int diff=abs(a-b);
        
//         if(idx==s.size())
//             return diff ;
        
//         if(dp[idx][diff]!=-1)
//             return dp[idx][diff];
        
//         int k=min(solve(s,idx+1,a+s[idx],b),solve(s,idx+1,a,b+s[idx]));
        
//         return dp[idx][diff]=k;
//     }
//     int lastStoneWeightII(vector<int>& stones) 
//     {
//         int n=stones.size();
//         memset(dp,-1,sizeof(dp));
//         return solve(stones,0,0,0);
//     }
};