class Solution {
public:
    bool dfs(int i,vector<int> &color,vector<vector<int>>& adj){
        if(color[i]==-1) color[i]=1;
        for(auto it:adj[i]){
            if(color[it]==-1){
                color[it]=1-color[i];
                if(dfs(it,color,adj)==false)
                    return false;
            }
            else if(color[i]==color[it])return false;
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& adj) {
        int v=adj.size();
        vector<int> color(v,-1);
        for(int i=0;i<v;i++){
            if(color[i]==-1)
                if(dfs(i,color,adj)==false)
                    return false;
        }
        return true;
    }
};