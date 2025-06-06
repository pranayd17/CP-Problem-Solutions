#define ll long long

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        ll sum=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                sum+=grid[i][j];
            }
        }
        ll s=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                s+=grid[i][j];
            }
            if(s==sum-s) return 1;
        }
        
        s=0;
        for(int i=0;i<grid[0].size();i++){
            for(int j=0;j<grid.size();j++){
                s+=grid[j][i];
            }
            if(s==sum-s) return 1;
        }
        return 0;
    }
};
