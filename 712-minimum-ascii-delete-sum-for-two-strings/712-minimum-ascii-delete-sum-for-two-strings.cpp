class Solution {
public:
    int helper(string s1,string s2,int i,int j,vector<vector<int>> &dp){
        int count=0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(i==s1.size() and j==s2.size())
            count=0;
       else if(i==s1.size()){
            count+=int(s2[j])+helper(s1,s2,i,j+1,dp);
        }
       else if( j==s2.size()){
            count+=helper(s1,s2,i+1,j,dp)+int(s1[i]);
        }
       else if(s1[i]==s2[j])
            count+= helper(s1,s2,i+1,j+1,dp);
      
        else
        count+= min(helper(s1,s2,i+1,j,dp)+s1[i],helper(s1,s2,i,j+1,dp)+s2[j]);
            
        return dp[i][j]=count;
            
    }
    int minimumDeleteSum(string s1, string s2) {
        //vector<vector<int>> dp(s1.size()+1,vector<int>(s2.size()+1,-1));
       
       // return helper(s1,s2,0,0,dp);
         int m = s1.size(), n = s2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        for (int j = 1; j <= n; j++)
            dp[0][j] = dp[0][j-1]+s2[j-1];
        for (int i = 1; i <= m; i++) {
            dp[i][0] = dp[i-1][0]+s1[i-1];
            for (int j = 1; j <= n; j++) {
                if (s1[i-1] == s2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else 
                    dp[i][j] = min(dp[i-1][j]+s1[i-1], dp[i][j-1]+s2[j-1]);
            }
        }
        return dp[m][n];
    }
};