class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==1)
                    continue;
                else{
                    vector<int> v;
                    int di=i;
                    int dj=j;
                    while(di<m and dj<n){
                        v.push_back(mat[di][dj]);
                        di++,dj++;
                    }
                    sort(v.begin(),v.end());
                    di=i;
                    dj=j;
                    int idx=0;
                    while(di<m and dj<n){
                        mat[di][dj]=v[idx];
                        idx++;
                        di++,dj++;
                    }
                    
                }
            }
        }
        return mat;
        
    }
};